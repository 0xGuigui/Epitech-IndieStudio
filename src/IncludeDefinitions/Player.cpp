/*
** EPITECH PROJECT, 2022
** Player.cpp
** File description:
** IncludeDefinitions
*/

#include "indie.hpp"

using namespace bmb;

bool Player::checkCollision(float x, float y) {
    if (ghost)
        return false;
    Rectangle playerRect = {position.getX() + x, position.getZ() + y, 0.75f, 0.75f};
    for (IndieVector3 pos : indie.map.getDestructiblePositions()) {
        Rectangle destructibleRect = {pos.getX(), pos.getZ(), 0.75f, 0.75f};
        if (CheckCollisionRecs(playerRect, destructibleRect))
            return true;
    }
    return false;
}

Player::Player(IndieColor color, IndieVector3 position, direction facing) {
	unsigned int count = 0;
    IndieTexture2D texture = indie.loader.textures["skin"];

    playerColor = color;
    this->position = position;
    playerModel.LoadModel("assets/Steve.iqm");
    anim = LoadModelAnimations("assets/Steve.iqm", &count);
    playerModel.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    switch (facing) {
        case LEFT:
            turnLeft();
            break;
        case RIGHT:
            turnRight();
            break;
        case UP:
            turnUp();
            break;
        case DOWN:
            turnDown();
            break;
    };
}

void Player::setControls(KeyboardKey *controls) {
	setKeyUp(controls[0]);
    setKeyDown(controls[1]);
    setKeyRight(controls[2]);
    setKeyLeft(controls[3]);
    setKeyBomb(controls[4]);
}

void Player::setKeyLeft(KeyboardKey key) {
	indie.keyboard.unbind(keys[LEFT]);
    keys[LEFT] = key;
    indie.keyboard.bind(key, [&]() -> void {
        if (dead || deadAnimation)
            return;
        turnLeft();
        if (position.getZ() > -7.35f && (static_cast<int>(round(position.getX())) % 2 != 0 || static_cast<int>(round(position.getZ() - 0.35f)) % 2 != 0) && !checkCollision(0.0f, -0.05f))
            position = { position.getX(), position.getY(), position.getZ() - (0.05f * speed)};
        _animate = true;
    }, [&]() -> void {
        if (dead || deadAnimation)
            return;
        _animate = false;
        frame = 0;
    }, inGame);
}

void Player::setKeyRight(KeyboardKey key) {
    indie.keyboard.unbind(keys[RIGHT]);
    keys[RIGHT] = key;
    indie.keyboard.bind(key, [&]() -> void {
        if (dead || deadAnimation)
            return;
        turnRight();
        if (position.getZ() < 5.35f && (static_cast<int>(round(position.getX())) % 2 != 0 || static_cast<int>(round(position.getZ() + 0.35f)) % 2 != 0) && !checkCollision(0.0f, 0.05f))
            position = { position.getX(), position.getY(), position.getZ() + (0.05f * speed) };
        _animate = true;
    }, [&]() -> void {
        if (dead || deadAnimation)
            return;
        _animate = false;
        frame = 0;
    }, inGame);
}

void Player::setKeyUp(KeyboardKey key) {
    indie.keyboard.unbind(keys[UP]);
    keys[UP] = key;
    indie.keyboard.bind(key, [&]() -> void {
        if (dead || deadAnimation)
            return;
        turnUp();
        if (position.getX() < -3.0f && (static_cast<int>(round(position.getX() + 0.35f)) % 2 != 0 || static_cast<int>(round(position.getZ())) % 2 != 0) && !checkCollision(0.05f, 0.0f))
            position = { position.getX() + (0.05f * speed), position.getY(), position.getZ()};
        _animate = true;
    }, [&]() -> void {
        if (dead || deadAnimation)
            return;
        _animate = false;
        frame = 0;
    }, inGame);
}

void Player::setKeyDown(KeyboardKey key) {
    indie.keyboard.unbind(keys[DOWN]);
    keys[DOWN] = key;
    indie.keyboard.bind(key, [&]() -> void {
        if (dead || deadAnimation)
            return;
        turnDown();
        if (position.getX() > -15.35f && (static_cast<int>(round(position.getX() - 0.35f)) % 2 != 0 || static_cast<int>(round(position.getZ())) % 2 != 0) && !checkCollision(-0.05f, 0.0f))
            position = { position.getX() - (0.05f * speed), position.getY(), position.getZ()};
        _animate = true;
    }, [&]() -> void {
        if (dead || deadAnimation)
            return;
        _animate = false;
        frame = 0;
    }, inGame);
}

void Player::setKeyBomb(KeyboardKey key) {
    indie.keyboard.unbind(keys[BOMB]);
    keys[BOMB] = key;
    indie.keyboard.bind(key, [&]() -> void {
        if (dead || deadAnimation)
            return;
        IndieVector3 newPos(
            round(position.getX()),
            0.5f,
            round(position.getZ())
		);
        for (IndieBomb &bomb : indie.bombs) {
            IndieVector3 pos = bomb.getPosition();
            if (pos.getX() == newPos.getX() && pos.getZ() == newPos.getZ())
                return;
        }
        for (IndieVector3 &pos : indie.map.getDestructiblePositions()) {
            if (pos.getX() == newPos.getX() && pos.getZ() == newPos.getZ())
                return;
        }
        if (!bombLeft)
            return;
		bombLeft--;
        IndieBomb bomb(force, newPos, [&]() -> void {
            bombLeft++;
        });
        indie.bombs.push_back(bomb);
    }, []() -> void {}, inGame);
}

void Player::unbindKeys() {
    for (KeyboardKey &key : keys) {
        indie.keyboard.unbind(key);
        key = KEY_NULL;
    }
}

void Player::unbindKeyLeft() {
    indie.keyboard.unbind(keys[LEFT]);
    keys[LEFT] = KEY_NULL;
}

void Player::unbindKeyRight() {
    indie.keyboard.unbind(keys[RIGHT]);
    keys[RIGHT] = KEY_NULL;
}

void Player::unbindKeyUp() {
    indie.keyboard.unbind(keys[UP]);
    keys[UP] = KEY_NULL;
}

void Player::unbindKeyDown() {
    indie.keyboard.unbind(keys[DOWN]);
    keys[DOWN] = KEY_NULL;
}

void Player::unbindKeyBomb() {
    indie.keyboard.unbind(keys[BOMB]);
    keys[BOMB] = KEY_NULL;
}

void Player::Draw() {
    if (!deadAnimation && !dead) {
        frame += _animate ? 2 : 0;
        if (frame >= 110)
            frame = 0;
        UpdateModelAnimation(playerModel, anim[0], frame);
    } else {
        playerModel.getModel().transform = MatrixRotateXYZ({-61.4f, 0.0f +  + (frame * 0.2f), 0.0f});
        if (frame >= 90) {
            frame = 0;
            dead = true;
        }
        frame++;
    }
    if (!dead) {
        if (deadAnimation)
            playerModel.Draw(position, (0.5f - (frame * 0.005f)), IndieColor(RED));
        else
            playerModel.Draw(position, 0.5f, playerColor);
    }
}