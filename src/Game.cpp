/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** Menus
*/

#include "indieStudio.hpp"

using namespace bmb;

void generateLineHorizontal(std::vector<IndieVector3> &map, float posY, float posX, float posXEnd) {
    for (float x = posX; x <= posXEnd; x++) {
        if (rand() % 4 > 0)
            map.push_back({ x, 0.5f, posY });
    }
}

void generateLineVertical(std::vector<IndieVector3> &map, float posX, float posY, float posYEnd) {
    for (float y = posY; y <= posYEnd; y++) {
        if (rand() % 4 > 0)
            map.push_back({ posX, 0.5f, y });
    }
}

std::vector<IndieVector3> generateBoxes() {
    std::vector<IndieVector3> map;

    generateLineVertical(map, -3.0f, -5.0f, 3.0f);
    generateLineVertical(map, -15.0f, -5.0f, 3.0f);
    generateLineHorizontal(map, 5.0f, -13.0f, -5.0f);
    generateLineHorizontal(map, -7.0f, -13.0f, -5.0f);
    for (float x = -13.0f; x < -3.0f; x += 2.0f)
        generateLineVertical(map, x, -7.0f, 5.0f);
    for (float y = -5.0f; y < 5.0f; y += 2.0f)
        generateLineHorizontal(map, y, -15.0f, -3.0f);
    return map;
}

void Indie::bomberMan() {
    static std::vector<IndieVector3> map = generateBoxes();

    if (!this->map.isCameraUpdated()) {
        this->map.setCameraMode(CAMERA_FREE);
    }
    this->map.updateCamera();
    this->map.begin3D();
    this->map.Draw();
    for (IndieVector3 &BoxPos : map) {
        DrawCube(BoxPos, 1.0f, 1.0f, 1.0f, GRAY);
        DrawCubeWires(BoxPos, 1.0f, 1.0f, 1.0f, DARKGRAY);
    }
    this->map.end3D();
}