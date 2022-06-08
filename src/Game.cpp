/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** Menus
*/

#include "Player.hpp"

using namespace bmb;

void Indie::bomberMan() {
    static Player player("");

    if (!this->map.isCameraUpdated())
        this->map.setCameraMode(CAMERA_PERSPECTIVE);
    this->map.updateCamera();
    this->map.begin3D();
    this->map.Draw();
    player.Draw();
    this->map.end3D();
}