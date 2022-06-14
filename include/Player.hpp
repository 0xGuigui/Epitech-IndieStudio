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

// ModelGetBoundingBox

namespace bmb {
    class Player {
        private:
            IndieModel playerModel;
            ModelAnimation *anim;
            int frame = 0;
            IndieColor playerColor = WHITE;
            IndieVector3 position;
            bool _animate = false;
            bool ghost = false; // WALLPASS
            int bombLeft = 3;
            int force = 4;
            int speed = 1.0f;
            KeyboardKey keys[5] = { KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL };
            bool checkCollision(float x, float y);
        public:
            Player() = default;
            Player(IndieColor color, IndieVector3 position, direction facing = LEFT);
            ~Player() {
                unbindKeys();
            };
            bool isAnimated() {
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