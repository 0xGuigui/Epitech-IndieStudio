/*
** EPITECH PROJECT, 2022
** screen
** File description:
** screen
*/

#pragma once

#include "vector.hpp"
#include "ray.hpp"
#include "camera3d.hpp"
#include "camera.hpp"
#include "matrix.hpp"

//Rajouter le Indie devant les matrix etc..
namespace bmb {
	class IndieScreen {
		public:
			IndieScreen() {};
			~IndieScreen() {};
            int GetWidth() {
                return GetScreenWidth();
            }
            int GetHeight() {
                return GetScreenHeight();
            }
            IndieRay GetMouseRay(IndieVector2 mousePosition, IndieCamera3D camera) {
                return ::GetMouseRay(mousePosition, camera);
            }
            IndieMatrix GetCameraMatrix(IndieCamera3D camera) {
                return ::GetCameraMatrix(camera);
            }
            IndieMatrix GetCameraMatrix2D(IndieCamera2D camera) {
                return ::GetCameraMatrix2D(camera);
            }
            IndieVector2 GetWorldToScreen() {
                return ::GetMousePosition();
            }
            IndieVector2 GetWorldToScreenEx(IndieVector3 position, IndieCamera3D camera, int width, int height) {
                return ::GetWorldToScreenEx(position, camera, width, height);
            }
            IndieVector2 GetWorldToScreen2D(IndieVector2 position, IndieCamera2D camera) {
                return ::GetWorldToScreen2D(position, camera);
            }
            IndieVector2 GetScreenToWorld2D(IndieVector2 position, IndieCamera2D camera) {
                return ::GetScreenToWorld2D(position, camera);
            }
	};
}
