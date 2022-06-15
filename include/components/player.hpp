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
        bool _animate = false;
        bool _ghost = false; // WALLPASS
        int _bombLeft = 1;
        int _force = 1;
        float _speed = 1.0f;
        bool deadAnimation = false;
        bool dead = false;
        KeyboardKey keys[5] = {KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL};

        bool checkCollision(float x, float y);

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

        KeyboardKey *getKeys() {
            return keys;
        }
    };
}