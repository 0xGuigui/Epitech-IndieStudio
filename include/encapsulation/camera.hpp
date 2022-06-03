/*
** EPITECH PROJECT, 2022
** camera2d
** File description:
** camera2d
*/

#pragma once

#include "raylib.h"
#include "vector.hpp"

namespace bmb {
	class IndieCamera2D {
        private:
            Camera2D _camera2D;

		public:
            IndieCamera2D(IndieVector2 offset, IndieVector2 target, float rotation, float zoom) {
                _camera2D.zoom = zoom;
                _camera2D.rotation = rotation;
                _camera2D.target = target;
                _camera2D.offset = offset;
                BeginMode2D(_camera2D);
            }
			~IndieCamera2D() {};
            IndieCamera2D(const Camera2D &camera) : _camera2D(camera) {};
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
            operator Camera2D() const {
                return _camera2D;
            }
	};

    class IndieCamera3D {
    private:
        Camera _camera{};

    public:
        IndieCamera3D(IndieVector3 position, IndieVector3 target, IndieVector3 up, float fovy, int projection) {
            _camera.position = position;
            _camera.target = target;
            _camera.up = up;
            _camera.fovy = fovy;
            _camera.projection = projection;
        }
        void setControls(int keyFront, int keyBack, int keyRight, int keyLeft, int keyUp, int keyDown) {
            SetCameraMoveControls(keyFront, keyBack, keyRight, keyLeft, keyUp, keyDown);
        }
        void SetPanControl(int keyPan) {
            SetCameraPanControl(keyPan);
        }
        void SetAltControl(int keyAlt) {
            SetCameraAltControl(keyAlt);
        }
        void SetCameraSmoothZoomControl(int keySmoothZoom) {
            ::SetCameraSmoothZoomControl(keySmoothZoom);
        }
        ~IndieCamera3D() {};
        operator Camera() const {
            return _camera;
        }
    };
};