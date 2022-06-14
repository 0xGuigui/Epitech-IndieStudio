/*
** EPITECH PROJECT, 2022
** MapController.cpp
** File description:
** IncludeDefinitions
*/

#include "MapController.hpp"
#include "indie.hpp"

using namespace bmb;

MapController::MapController(const IndieImage& mapImage, const IndieImage& mapObstacleImage,
                          const IndieTexture2D& block, const IndieTexture2D& obstacle, const IndieTexture2D& destructible,
                          const IndieVector3& mapPosition, const IndieCamera3D& camera) {
     _environmentHandler.init();
     IndieMesh destructibleMesh;
     destructibleMesh.GenCube(1.0f, 1.0f, 1.0f);
	IndieMesh mapMesh(mapImage, { 1.0f, 1.0f, 1.0f });
	IndieMesh obsMesh(mapObstacleImage, { 1.0f, 1.0f, 1.0f });
	_map.LoadFromMesh(mapMesh);
	_mapObstacle.LoadFromMesh(obsMesh);
	_destructible.LoadFromMesh(destructibleMesh);
	_map.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = block;
	_mapObstacle.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = obstacle;
	_destructible.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = destructible;
	_position = mapPosition;
	_camera = camera;
	this->generateBoxes(75);
	for (IndieVector3 &destructiblePosition : _destructiblePositions) {
		int probability = rand() % 100;
		std::cout << probability << std::endl;
		if (probability > 50 && probability < 65)
			_bonuses.push_back(IndiePowerUp([&](Player &player) -> void {
				player.setBombLeft(player.getBombLeft() + 1);
			}, destructiblePosition, indie.loader.models["bomb_up"], BOMBUP));
		if (probability > 65 && probability < 80)
			_bonuses.push_back(IndiePowerUp([&](Player &player) -> void {
				player.setSpeed(player.getSpeed() + 0.2f);
			}, destructiblePosition, indie.loader.models["speed_up"], SPEEDUP));
		if (probability > 80 && probability < 95)
			_bonuses.push_back(IndiePowerUp([&](Player &player) -> void {
				player.setForce(player.getForce() + 1);
			}, destructiblePosition, indie.loader.models["fire_up"], FIREUP));
		if (probability > 95 && probability < 100)
			_bonuses.push_back(IndiePowerUp([&](Player &player) -> void {
				player.setGhost(true);
			}, destructiblePosition, indie.loader.models["wall_pass"], WALLPASS));
	}
}