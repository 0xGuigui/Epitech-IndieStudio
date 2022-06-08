/*
** EPITECH PROJECT, 2022
** MapHandler.hpp
** File description:
** include
*/

#pragma once

#include "encapsulation/model.hpp"
#include "encapsulation/camera.hpp"
#include <vector>

namespace bmb {
	class MapController {
		private:
			IndieModel _map;
			IndieModel _mapObstacle;
			IndieModel _destructible;
			IndieCamera3D _camera;
			IndieVector3 _position;
			std::vector<IndieVector3> _destructiblePositions = {};
			bool _updateCamera = false;
			void generateLineHorizontal(float posY, float posX, float posXEnd, int percentage) {
				for (float x = posX; x <= posXEnd; x++) {
					if (((rand() % 100) - 100 + percentage) > 0)
						_destructiblePositions.push_back({ x, 0.5f, posY });
				}
			}
			void generateLineVertical(float posX, float posY, float posYEnd, int percentage) {
				for (float y = posY; y <= posYEnd; y++) {
					if (((rand() % 100) - 100 + percentage) > 0)
						_destructiblePositions.push_back({ posX, 0.5f, y });
				}
			}
			void generateBoxes(int percentage) {
				const float minX = _position.getX() + 1;
				const float maxX = minX + 12;
				const float minY = _position.getZ() + 1;
				const float maxY = minY + 12;

				this->generateLineVertical(maxX, minY + 2, maxY - 2, percentage);
				this->generateLineVertical(minX, minY + 2, maxY - 2, percentage);
				this->generateLineHorizontal(maxY, minX + 2, minY + 2, percentage);
				this->generateLineHorizontal(minY, minX + 2, minY + 2, percentage);
				for (float x = minX + 2; x < maxX; x += 2.0f)
					this->generateLineVertical(x, minY, maxY, percentage);
				for (float y = minY + 2; y < maxY; y += 2.0f)
					this->generateLineHorizontal(y, minX, maxX, percentage);
			}
		public:
			MapController() = default;
			MapController(const IndieImage& mapImage, const IndieImage& mapObstacleImage,
                          const IndieTexture2D& block, const IndieTexture2D& obstacle, const &IndieTexture2D destructible,
                          const IndieVector3& mapPosition, const IndieCamera3D& camera) {
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
			};
			void setPosition(const IndieVector3& position) {
				_position = position;
			}
			void DrawMap() {
				_map.Draw(_position, 1.0f, WHITE);
				_mapObstacle.Draw(_position, 1.0f, WHITE);
			}
			void DrawObstacles() {
				for (IndieVector3 pos : _destructiblePositions)
					_destructible.Draw(pos, 1.0f, WHITE);
			}
			void Draw() {
				_map.Draw(_position, 1.0f, WHITE);
				_mapObstacle.Draw(_position, 1.0f, WHITE);
				for (IndieVector3 pos : _destructiblePositions)
					_destructible.Draw(pos, 1.0f, WHITE);
			}
			bool isCameraUpdated() const {
				return _updateCamera;
			}
			void setCameraUpdate(bool state) {
				_updateCamera = state;
			}
			void setCameraPosition(const IndieVector3& position) {
				_camera.setPosition(position);
				_updateCamera = true;
			}
			void setCameraTarget(const IndieVector3& target) {
				_camera.setTarget(target);
				_updateCamera = true;
			}
			void setCameraMode(int mode) {
				_camera.setMode(mode);
				_updateCamera = true;
			}
			void updateCamera() {
				_camera.update();
			}
			void begin3D() {
				_camera.begin3D();
			}
			void end3D() {
				_camera.end3D();
			}
			void generateDestructible(int percentage) {
				_destructiblePositions.clear();
				generateBoxes(percentage);
			}
	};
};
