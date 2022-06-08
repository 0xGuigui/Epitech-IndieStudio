/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** Menus
*/

#include "indieStudio.hpp"

using namespace bmb;

void Indie::bomberMan() {
    if (!this->map.isCameraUpdated())
        this->map.setCameraMode(CAMERA_PERSPECTIVE);
    this->map.updateCamera();
    this->map.begin3D();
    this->map.Draw();
    this->map.end3D();
}