/*
** EPITECH PROJECT, 2022
** Player.hpp
** File description:
** include
*/

#pragma once

#include "indie.hpp"
#include "raymath.h"
#include <cmath>

//ModelGetBoundingBox

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
            int bombLeft = 1;
            KeyboardKey keys[5] = { KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL, KEY_NULL };
            bool checkCollision(float x, float y) {
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
        public:
            Player() = default;
            Player(IndieColor color, IndieVector3 position, direction facing = LEFT) {
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
            void startAnimation() {
                _animate = true;
            }
            void stopAnimation() {
                _animate = false;
            }
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
            void setControls(KeyboardKey controls[5]) {
                setKeyLeft(controls[0]);
                setKeyRight(controls[1]);
                setKeyUp(controls[2]);
                setKeyDown(controls[3]);
                setKeyBomb(controls[4]);
            }
            void setKeyLeft(KeyboardKey key) {
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
            void setKeyRight(KeyboardKey key) {
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
            void setKeyUp(KeyboardKey key) {
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
            void setKeyDown(KeyboardKey key) {
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
            void setKeyBomb(KeyboardKey key) {
                indie.keyboard.unbind(keys[4]);
                keys[4] = key;
                indie.keyboard.bind(key, [&]() -> void {
                    if (!bombLeft)
                        return;
                    IndieVector3 newPos = {
                        static_cast<int>(round(position.getX())),
                        static_cast<int>(round(position.getY())),
                        static_cast<int>(round(position.getZ()))
                    };
                    IndieBomb bomb(indie.loader.textures["tnt"], newPos, [&]() -> void {
                        bombLeft++;
                    });
                    indie.bombs.push_back(bomb);
                }, []() -> void {});
            }
            void unbindKeys() {
                for (KeyboardKey key : keys) {
                    indie.keyboard.unbind(key);
                }
            }
            void Draw() {
                frame += _animate ? 2 : 0;
                if (frame >= 110)
                    frame = 0;
                UpdateModelAnimation(playerModel, anim[0], frame);
                playerModel.Draw(position, 0.5f, playerColor);
            }
    };
}