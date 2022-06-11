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
        return true;
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
    IndieTexture2D texture("assets/char.png");

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
	indie.keyboard.unbind(keys[0]);
    keys[0] = key;
    indie.keyboard.bind(key, [&]() -> void {
        turnLeft();
        if (position.getZ() > -7.35f && (static_cast<int>(round(position.getX())) % 2 != 0 || static_cast<int>(round(position.getZ() - 0.35f)) % 2 != 0) && !checkCollision(0.0f, -0.05f))
            position = { position.getX(), position.getY(), position.getZ() - 0.05f};
        _animate = true;
    }, [&]() -> void {
        _animate = false;
        frame = 0;
    });
}

void Player::setKeyRight(KeyboardKey key) {
    indie.keyboard.unbind(keys[1]);
    keys[1] = key;
    indie.keyboard.bind(key, [&]() -> void {
        turnRight();
        if (position.getZ() < 5.35f && (static_cast<int>(round(position.getX())) % 2 != 0 || static_cast<int>(round(position.getZ() + 0.35f)) % 2 != 0) && !checkCollision(0.0f, 0.05f))
            position = { position.getX(), position.getY(), position.getZ() + 0.05f };
        _animate = true;
    }, [&]() -> void {
        _animate = false;
        frame = 0;
    });
}

void Player::setKeyUp(KeyboardKey key) {
    indie.keyboard.unbind(keys[2]);
    keys[2] = key;
    indie.keyboard.bind(key, [&]() -> void {
        turnUp();
        if (position.getX() < -3.0f && (static_cast<int>(round(position.getX() + 0.35f)) % 2 != 0 || static_cast<int>(round(position.getZ())) % 2 != 0) && !checkCollision(0.05f, 0.0f))
            position = { position.getX() + 0.05f, position.getY(), position.getZ()};
        _animate = true;
    }, [&]() -> void {
        _animate = false;
        frame = 0;
    });
}

void Player::setKeyDown(KeyboardKey key) {
    indie.keyboard.unbind(keys[3]);
    keys[3] = key;
    indie.keyboard.bind(key, [&]() -> void {
        turnDown();
        if (position.getX() > -15.35f && (static_cast<int>(round(position.getX() - 0.35f)) % 2 != 0 || static_cast<int>(round(position.getZ())) % 2 != 0) && !checkCollision(-0.05f, 0.0f))
            position = { position.getX() - 0.05f, position.getY(), position.getZ()};
        _animate = true;
    }, [&]() -> void {
        _animate = false;
        frame = 0;
    });
}

void Player::setKeyBomb(KeyboardKey key) {
    indie.keyboard.unbind(keys[4]);
    keys[4] = key;
    indie.keyboard.bind(key, [&]() -> void {
        if (!bombLeft)
            return;
		bombLeft--;
        IndieVector3 newPos(
            round(position.getX()),
            0.5f,
            round(position.getZ())
		);
        IndieBomb bomb(indie.loader.textures["brick"], newPos, [&]() -> void {
            bombLeft++;
        });
        indie.bombs.push_back(bomb);
    }, []() -> void {});
}

void Player::unbindKeys() {
    for (KeyboardKey key : keys) {
        indie.keyboard.unbind(key);
    }
}

void Player::Draw() {
    frame += _animate ? 2 : 0;
    if (frame >= 110)
        frame = 0;
    UpdateModelAnimation(playerModel, anim[0], frame);
    playerModel.Draw(position, 0.5f, playerColor);
}