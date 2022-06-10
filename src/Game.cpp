/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** Menus
*/

#include "Player.hpp"

using namespace bmb;

// -15 -7
// -3 5

void Indie::bomberMan() {
    static KeyboardKey control1[5] = {KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT, KEY_SPACE};
    static KeyboardKey control2[5] = {KEY_W, KEY_S, KEY_D, KEY_A, KEY_SPACE};
    static KeyboardKey control3[5] = {KEY_T, KEY_G, KEY_H, KEY_F, KEY_SPACE};
    static KeyboardKey control4[5] = {KEY_I, KEY_K, KEY_L, KEY_J, KEY_SPACE};
    static Player player(BLUE, {-15.0f, 1.5f, -7.0f}, control1);
    static Player player2(RED, {-15.0f, 1.5f, 5.0f}, control2);
    static Player player3(YELLOW, {-3.0f, 1.5f, 5.0f}, control3);
    static Player player4(GREEN, {-3.0f, 1.5f, -7.0f}, control4);

    if (!this->map.isCameraUpdated())
        this->map.setCameraMode(CAMERA_PERSPECTIVE);
    this->map.updateCamera();
    this->map.begin3D();
    this->map.Draw();
    player.Draw();
    player2.Draw();
    player3.Draw();
    player4.Draw();
    this->map.end3D();
}