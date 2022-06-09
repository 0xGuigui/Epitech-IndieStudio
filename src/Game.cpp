/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** Menus
*/

#include "Player.hpp"

using namespace bmb;

void Indie::bomberMan() {
    static Player player("", BLUE, {-10.0f, 4.0f, -4.0f});
    static Player player2("", RED, {-10.0f, 4.0f, -10.0f});
    static Player player3("", YELLOW, {-10.0f, 4.0f, 2.0f});
    static Player player4("", GREEN, {-10.0f, 4.0f, 7.0f});

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