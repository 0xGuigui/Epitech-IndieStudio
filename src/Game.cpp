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
    static Player player("", BLUE, {-15.0f, 1.5f, -7.0f});
    static Player player2("", RED, {-15.0f, 1.5f, 5.0f});
    static Player player3("", YELLOW, {-3.0f, 1.5f, 5.0f});
    static Player player4("", GREEN, {-3.0f, 1.5f, -7.0f});

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