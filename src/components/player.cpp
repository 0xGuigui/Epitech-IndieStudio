/*
** EPITECH PROJECT, 2022
** Player.cpp
** File description:
** IncludeDefinitions
*/

#include "indie.hpp"
#include "components/player.hpp"

using namespace bmb;

bool Player::checkCollision(float x, float y) {
    if (_ghost)
        return false;
    Rectangle playerRect = {position.getX() + x, position.getZ() + y, 0.75f, 0.75f};
    return std::any_of(indie.map.getDestructiblePositions().begin(), indie.map.getDestructiblePositions().end(),
                [&playerRect](const IndieVector3 &pos) {
                    Rectangle destructibleRect = {pos.getX(), pos.getZ(), 0.75f, 0.75f};
                    return CheckCollisionRecs(playerRect, destructibleRect);
                });
}

Player::Player(IndieColor color, const IndieVector3& position, direction facing) {
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
        default:
            break;
    }
}

void Player::setControls(KeyboardKey *controls) {
    setKeyUp(controls[0]);
    setKeyDown(controls[1]);
    setKeyRight(controls[2]);
    setKeyLeft(controls[3]);
    setKeyBomb(controls[4]);
    ai = false;
}

void Player::setKeyLeft(KeyboardKey key) {
    indie.keyboard.unbind(keys[LEFT]);
    keys[LEFT] = key;
    indie.keyboard.bind(key, [&]() -> void {
        if (!ai)
            moveLeft();
    }, [&]() -> void {
        stop();
    }, inGame);
    setAI();
}

void Player::setKeyRight(KeyboardKey key) {
    indie.keyboard.unbind(keys[RIGHT]);
    keys[RIGHT] = key;
    indie.keyboard.bind(key, [&]() -> void {
        if (!ai)
            moveRight();
    }, [&]() -> void {
        stop();
    }, inGame);
    setAI();
}

void Player::setKeyUp(KeyboardKey key) {
    indie.keyboard.unbind(keys[UP]);
    keys[UP] = key;
    indie.keyboard.bind(key, [&]() -> void {
        if (!ai)
            moveUp();
    }, [&]() -> void {
        stop();
    }, inGame);
    setAI();
}

void Player::setKeyDown(KeyboardKey key) {
    indie.keyboard.unbind(keys[DOWN]);
    keys[DOWN] = key;
    indie.keyboard.bind(key, [&]() -> void {
        if (!ai)
            moveDown();
    }, [&]() -> void {
        stop();
    }, inGame);
    setAI();
}

void Player::setKeyBomb(KeyboardKey key) {
    indie.keyboard.unbind(keys[BOMB]);
    keys[BOMB] = key;
    indie.keyboard.bind(key, [&]() -> void {
        if (!ai)
            dropBomb();
    }, []() -> void {}, inGame);
    setAI();
}

void Player::dropBomb() {
    if (dead || deadAnimation)
        return;
    IndieVector3 newPos(
            round(position.getX()),
            0.5f,
            round(position.getZ())
    );
    for (IndieBomb &bomb: indie.bombs) {
        IndieVector3 pos = bomb.getPosition();
        if (pos.getX() == newPos.getX() && pos.getZ() == newPos.getZ())
            return;
    }
    for (IndieVector3 &pos: indie.map.getDestructiblePositions()) {
        if (pos.getX() == newPos.getX() && pos.getZ() == newPos.getZ())
            return;
    }
    if (!_bombLeft)
        return;
    _bombLeft--;
    IndieBomb bomb(_force, newPos, [&]() -> void {
        _bombLeft++;
    });
    indie.bombs.push_back(bomb);
}

void Player::unbindKeys() {
    for (KeyboardKey &key: keys) {
        indie.keyboard.unbind(key);
        key = KEY_NULL;
    }
    ai = true;
}

void Player::unbindKeyLeft() {
    indie.keyboard.unbind(keys[LEFT]);
    keys[LEFT] = KEY_NULL;
    ai = true;
}

void Player::unbindKeyRight() {
    indie.keyboard.unbind(keys[RIGHT]);
    keys[RIGHT] = KEY_NULL;
    ai = true;
}

void Player::unbindKeyUp() {
    indie.keyboard.unbind(keys[UP]);
    keys[UP] = KEY_NULL;
    ai = true;
}

void Player::unbindKeyDown() {
    indie.keyboard.unbind(keys[DOWN]);
    keys[DOWN] = KEY_NULL;
    ai = true;
}

void Player::unbindKeyBomb() {
    indie.keyboard.unbind(keys[BOMB]);
    keys[BOMB] = KEY_NULL;
    ai = true;
}

void Player::Draw() {
    if (ai)
        AI();
    if (!deadAnimation && !dead) {
        frame += _animate ? 2 : 0;
        if (frame >= 110)
            frame = 0;
        UpdateModelAnimation(playerModel, anim[0], frame);
    } else {
        playerModel.getModel().transform = MatrixRotateXYZ({-61.4f, 0.0f + (static_cast<float>(frame) * 0.2f), 0.0f});
        if (frame >= 90) {
            frame = 0;
            dead = true;
        }
        frame++;
    }
    if (!dead) {
        if (deadAnimation)
            playerModel.Draw(position, (0.5f - (static_cast<float>(frame) * 0.005f)), IndieColor(RED));
        else
            playerModel.Draw(position, 0.5f, playerColor);
    }
}

std::vector<direction> Player::checkDanger(IndieVector3 playerPosition) {
    std::vector<direction> danger;
    bool up, down, left, right = false;
    for (IndieBomb &bomb: indie.bombs) {
        IndieVector3 bombPosition = bomb.getPosition();
        if (!right && bombPosition.getX() == round(playerPosition.getX()) && bombPosition.getZ() > round(playerPosition.getZ()) && round(playerPosition.getZ()) < bombPosition.getZ() + bomb.getForce()) {
            danger.push_back(RIGHT);
            right = true;
        } else if (!left && bombPosition.getX() == round(playerPosition.getX()) && bombPosition.getZ() < round(playerPosition.getZ()) && round(playerPosition.getZ()) > bombPosition.getZ() - bomb.getForce()) {
            danger.push_back(LEFT);
            left = true;
        } else if (!up && bombPosition.getZ() == round(playerPosition.getZ()) && bombPosition.getX() > round(playerPosition.getX()) && round(playerPosition.getX()) < bombPosition.getX() + bomb.getForce()) {
            danger.push_back(UP);
            up = true;
        } else if (!down && bombPosition.getZ() == round(playerPosition.getZ()) && bombPosition.getX() < round(playerPosition.getX()) && round(playerPosition.getX()) > bombPosition.getX() - bomb.getForce()) {
            danger.push_back(DOWN);
            down = true;
        }
    }
    return danger;
}

std::vector<direction> Player::canMove() {
    std::vector<direction> canMove;
    if (position.getZ() > -7.35f && (static_cast<int>(round(position.getX())) % 2 != 0 ||
        static_cast<int>(round(position.getZ() - 0.35f)) % 2 != 0) && !checkCollision(0.0f, -0.05f)) {
        std::vector<direction> dir = checkDanger({position.getX(), 0.5f, position.getZ() - 0.35f});
        if (std::find(dir.begin(), dir.end(), LEFT) == dir.end())
            canMove.push_back(LEFT);
    }
    if (position.getZ() < 5.35f && (static_cast<int>(round(position.getX())) % 2 != 0 ||
        static_cast<int>(round(position.getZ() + 0.35f)) % 2 != 0) && !checkCollision(0.0f, 0.05f)) {
        std::vector<direction> dir = checkDanger({position.getX(), 0.5f, position.getZ() + 0.35f});
        if (std::find(dir.begin(), dir.end(), RIGHT) == dir.end())
            canMove.push_back(RIGHT);
    }
    if (position.getX() < -3.0f && (static_cast<int>(round(position.getX() + 0.35f)) % 2 != 0 ||
        static_cast<int>(round(position.getZ())) % 2 != 0) && !checkCollision(0.05f, 0.0f)) {
        std::vector<direction> dir = checkDanger({position.getX() + 0.35f, 0.5f, position.getZ()});
        if (std::find(dir.begin(), dir.end(), UP) == dir.end())
            canMove.push_back(UP);
    }
    if (position.getX() > -15.35f && (static_cast<int>(round(position.getX() - 0.35f)) % 2 != 0 ||
        static_cast<int>(round(position.getZ())) % 2 != 0) && !checkCollision(-0.05f, 0.0f)) {
        std::vector<direction> dir = checkDanger({position.getX() - 0.35f, 0.5f, position.getZ()});
        if (std::find(dir.begin(), dir.end(), DOWN) == dir.end())
            canMove.push_back(DOWN);
    }
    return canMove;
}

void Player::AI() {
    if (dead || deadAnimation)
        return;
    if (frame % 15 != 0) {
        switch (direc) {
        case UP:
            moveUp();
            break;
        case DOWN:
            moveDown();
            break;
        case LEFT:
            moveLeft();
            break;
        case RIGHT:
            moveRight();
            break;
        }
        return;
    }
    std::vector<direction> danger = checkDanger(position);
    std::vector<direction> canMove = this->canMove();
    for (auto it = canMove.begin(); it != canMove.end();) {
        if (std::find(danger.begin(), danger.end(), *it) != danger.end())
            it = canMove.erase(it);
        else
            it++;
    }
    if (canMove.size() == 0)
        return dropBomb();
    int randDirection = rand() % canMove.size();
    direc = canMove[randDirection];
    switch (canMove[randDirection]) {
        case UP:
            moveUp();
            break;
        case DOWN:
            moveDown();
            break;
        case LEFT:
            moveLeft();
            break;
        case RIGHT:
            moveRight();
            break;
    }
}