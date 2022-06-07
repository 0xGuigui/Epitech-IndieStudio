/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** Menus
*/

#include "indieStudio.hpp"

using namespace bmb;

// std::vector<Vector3[2]> generateMap() {
//     // TODO
// }

void Indie::bomberMan() {
    const int screenWidth = this->screen.GetWidth();
    const int screenHeight = this->screen.GetHeight();

    if (!this->map.isCameraUpdated()) {
        this->map.setCameraMode(CAMERA_FREE);
    }
    this->map.updateCamera();
    this->map.begin3D();
    this->map.Draw();
    // // DrawCube(BoxPos, BoxSize.getVector().x, BoxSize.getVector().y, BoxSize.getVector().z, GRAY);
    // // DrawCubeWires(BoxPos, BoxSize.getVector().x, BoxSize.getVector().y, BoxSize.getVector().z, DARKGRAY);
    this->map.end3D();
}