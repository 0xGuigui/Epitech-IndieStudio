/*
** EPITECH PROJECT, 2022
** camera2d
** File description:
** camera2d
*/

#pragma once

#include "vector2.hpp"

namespace bmb {
	class IndieCamera2D {
		public:
            IndieCamera2D(IndieVector2 offset, IndieVector2 target, float rotation, float zoom) {
                _camera2D.zoom = zoom;
                _camera2D.rotation = rotation;
                _camera2D.target = target;
                _camera2D.offset = offset;
                BeginMode2D(_camera2D);
            }
			~IndieCamera2D() {};
            IndieCamera2D(Camera2D camera) {
                _camera2D = camera;
            }
            void Begin() {
                BeginMode2D(_camera2D);
            }
            float getRotation() {
                return _camera2D.rotation;
            }
            float getZoom() {
                return _camera2D.zoom;
            }
            IndieVector2 getOffset() {
                return _camera2D.offset;
            }
            IndieVector2 getTarget() {
                return _camera2D.target;
            }
            operator Camera2D () {
                return _camera2D;
            }
		private:
            Camera2D _camera2D;
	};
};