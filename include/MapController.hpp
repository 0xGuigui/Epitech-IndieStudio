/*
** EPITECH PROJECT, 2022
** MapHandler.hpp
** File description:
** include
*/

#pragma once

#include "encapsulation/model.hpp"
#include "encapsulation/camera.hpp"

namespace bmb {
	class MapController {
		private:
			IndieModel _map;
			IndieModel _mapObstacle;
			IndieCamera3D _camera;
			IndieVector3 _position;
			bool _updateCamera = false;
		public:
			MapController() = default;
			MapController(const IndieImage& mapImage, const IndieImage& mapObstacleImage,
                          const IndieTexture2D& block, const IndieTexture2D& obstacle,
                          const IndieVector3& mapPosition, const IndieCamera3D& camera) {
				IndieMesh mapMesh(mapImage, { 1.0f, 1.0f, 1.0f });
				IndieMesh obsMesh(mapObstacleImage, { 1.0f, 1.0f, 1.0f });
				_map.LoadFromMesh(mapMesh);
				_mapObstacle.LoadFromMesh(obsMesh);
				_map.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = block;
    			_mapObstacle.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = obstacle;
				_position = mapPosition;
				_camera = camera;
			};
			void setPosition(const IndieVector3& position) {
				_position = position;
			}
			void Draw() {
				_map.Draw(_position, 1.0f, WHITE);
				_mapObstacle.Draw(_position, 1.0f, WHITE);
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
	};
}
