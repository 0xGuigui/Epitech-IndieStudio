/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** camera
*/

#pragma once

#include "vector3.hpp"

namespace bmb {
    class IndieCamera3D {
        public:
            IndieCamera3D(IndieVector3 position, IndieVector3 target, IndieVector3 up, float fovy, int projection) {
                this->camera = {
                    .position = position,
                    .target = target,
                    .up = up,
                    .fovy = fovy,
                    .projection = projection
                };
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
                SetCameraSmoothZoomControl(keySmoothZoom);
            }
            ~IndieCamera3D() {};
            operator Camera () {
                return this->camera;
            }
        private:
            Camera camera;
    };
}