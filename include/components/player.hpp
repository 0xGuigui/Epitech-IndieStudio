/*
** EPITECH PROJECT, 2022
** Player.hpp
** File description:
** include
*/

#pragma once

#include "encapsulation/model.hpp"
#include "raymath.h"
#include <cmath>
#include "enums.hpp"

// ModelGetBoundingBox

namespace bmb {
    class Player {
    private:
        IndieModel playerModel;
        ModelAnimation *anim = nullptr;
        int frame = 0;
        IndieColor playerColor = WHITE;
        IndieVector3 position;
        IndieVector3 defaultPosition;
        direction direc = LEFT;
        bool _animate = false;
        bool _ghost = false; // WALLPASS
        int _bombLeft = 1;
        int _force = 1;
        float _speed = 1.0f;
        bool deadAnimation = false;
        bool dead = false;
        bool ai = true;
        KeyboardKey keys[5] = {KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL};

        bool checkCollision(float x, float y);

        void moveLeft() {
            if (dead || deadAnimation)
                return;
            turnLeft();
            if (position.getZ() > -7.35f && (static_cast<int>(round(position.getX())) % 2 != 0 ||
                                             static_cast<int>(round(position.getZ() - 0.35f)) % 2 != 0) &&
                !checkCollision(0.0f, -0.05f))
                position = {position.getX(), position.getY(), position.getZ() - (0.05f * _speed)};
            _animate = true;
        }

        void moveRight() {
            if (dead || deadAnimation)
                return;
            turnRight();
            if (position.getZ() < 5.35f && (static_cast<int>(round(position.getX())) % 2 != 0 ||
                                            static_cast<int>(round(position.getZ() + 0.35f)) % 2 != 0) &&
                !checkCollision(0.0f, 0.05f))
                position = {position.getX(), position.getY(), position.getZ() + (0.05f * _speed)};
            _animate = true;
        }

        void moveUp() {
            if (dead || deadAnimation)
                return;
            turnUp();
            if (position.getX() < -3.0f && (static_cast<int>(round(position.getX() + 0.35f)) % 2 != 0 ||
                                            static_cast<int>(round(position.getZ())) % 2 != 0) &&
                !checkCollision(0.05f, 0.0f))
                position = {position.getX() + (0.05f * _speed), position.getY(), position.getZ()};
            _animate = true;
        }

        void moveDown() {
            if (dead || deadAnimation)
                return;
            turnDown();
            if (position.getX() > -15.35f && (static_cast<int>(round(position.getX() - 0.35f)) % 2 != 0 ||
                                              static_cast<int>(round(position.getZ())) % 2 != 0) &&
                !checkCollision(-0.05f, 0.0f))
                position = {position.getX() - (0.05f * _speed), position.getY(), position.getZ()};
            _animate = true;
        }

        void stop() {
            if (dead || deadAnimation)
                return;
            _animate = false;
            frame = 0;
        }

        void dropBomb();

    public:
        Player() = default;

        Player(IndieColor color, const IndieVector3& position, direction facing = LEFT);

        ~Player() {
            unbindKeys();
        };

        bool isAnimated() const {
            return _animate;
        }

        void turnRight() {
            playerModel.getModel().transform = MatrixRotateXYZ({-61.4f, 0.0f, 0.0f});
        }

        void turnLeft() {
            playerModel.getModel().transform = MatrixRotateXYZ({-61.4f, -59.7f, 0.0f});
        }

        void turnUp() {
            playerModel.getModel().transform = MatrixRotateXYZ({-61.4f, 29.85f, -0.3f});
        }

        void turnDown() {
            playerModel.getModel().transform = MatrixRotateXYZ({-61.4f, -29.85f, 0.0f});
        }

        IndieVector3 getPosition() {
            return position;
        }

        void die() {
            deadAnimation = true;
            frame = 0;
        }

        int getBombLeft() const {
            return _bombLeft;
        }

        void setBombLeft(int bombLeft) {
            _bombLeft = bombLeft;
        }

        int getForce() const {
            return _force;
        }

        void setForce(int force) {
            _force = force;
        }

        float getSpeed() const {
            return _speed;
        }

        void setSpeed(float speed) {
            _speed = speed;
        }

        bool getGhost() const {
            return _ghost;
        }

        void setGhost(bool ghost) {
            _ghost = ghost;
        }

        void setAI() {
            for (int i = 0; i < 5; i++) {
                if (keys[i] == KEY_NULL) {
                    ai = true;
                    return;
                }
            }
            ai = false;
        }

        void setControls(KeyboardKey *controls);

        void setKeyLeft(KeyboardKey key);

        void setKeyRight(KeyboardKey key);

        void setKeyUp(KeyboardKey key);

        void setKeyDown(KeyboardKey key);

        void setKeyBomb(KeyboardKey key);

        void setKey(direction direction, KeyboardKey key) {
            switch (direction) {
                case LEFT:
                    setKeyLeft(key);
                    break;
                case RIGHT:
                    setKeyRight(key);
                    break;
                case UP:
                    setKeyUp(key);
                    break;
                case DOWN:
                    setKeyDown(key);
                    break;
                case BOMB:
                    setKeyBomb(key);
                    break;
            }
        }

        void unbindKeys();

        void unbindKeyLeft();

        void unbindKeyRight();

        void unbindKeyUp();

        void unbindKeyDown();

        void unbindKeyBomb();

        void Draw();

        void AI();

        static std::vector<direction> checkDanger(const IndieVector3&);

        std::vector<direction> canMove();

        KeyboardKey *getKeys() {
            return keys;
        }
        bool isAlive() {
            return !dead;
        }

        void reset() {
            this->_force = 1;
            this->position = defaultPosition;
            this->_speed = 1.0f;
            this->_ghost = false;
            this->_bombLeft = 1;
            this->dead = false;
            this->deadAnimation = false;
            this->frame = false;
            this->_animate = false;
        }
    };
}