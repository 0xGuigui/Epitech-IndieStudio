/*
** EPITECH PROJECT, 2022
** MapController.cpp
** File description:
** IncludeDefinitions
*/

#include "components/mapController.hpp"
#include <cmath>
#include "indie.hpp"

using namespace bmb;

MapController::MapController(const IndieImage &mapImage, const IndieImage &mapObstacleImage,
                             const IndieTexture2D &block, const IndieTexture2D &obstacle,
                             const IndieTexture2D &destructible, const IndieVector3 &mapPosition,
                             const IndieVector3 &cameraTargetPosition, const IndieVector3 &cameraPosition) {
    _environmentHandler.init();
    IndieMesh destructibleMesh = GenMeshCube(1.0f, 1.0f, 1.0f);
    _destructible.LoadFromMesh(destructibleMesh);
    _destructible.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = destructible;
    _position = mapPosition;
    _camera = IndieAnimatedCamera3D(cameraPosition, cameraTargetPosition, {-9.0f, 0.0f, -1.0f}, {0, 1, 0}, 45, 0.0f,
                                    [](float x) -> float {
                                        return x == 1 ? 1 : 1 - std::pow(2, -10 * x);
                                    }, 120, 40);
    this->generateBoxes(75);
    for (IndieVector3 &destructiblePosition: _destructiblePositions) {
        int probability = rand() % 100;
        if (probability > 50 && probability < 65)
            _bonuses.emplace_back([&](Player &player) -> void {
                player.setBombLeft(player.getBombLeft() + 1);
            }, destructiblePosition, indie.loader.models["bomb_up"], BOMBUP);
        if (probability > 65 && probability < 80)
            _bonuses.emplace_back([&](Player &player) -> void {
                player.setSpeed(player.getSpeed() + 0.2f);
            }, destructiblePosition, indie.loader.models["speed_up"], SPEEDUP);
        if (probability > 80 && probability < 95)
            _bonuses.emplace_back([&](Player &player) -> void {
                player.setForce(player.getForce() + 1);
            }, destructiblePosition, indie.loader.models["fire_up"], FIREUP);
        if (probability > 95 && probability < 100)
            _bonuses.emplace_back([&](Player &player) -> void {
                player.setGhost(true);
            }, destructiblePosition, indie.loader.models["wall_pass"], WALLPASS);
    }
}
