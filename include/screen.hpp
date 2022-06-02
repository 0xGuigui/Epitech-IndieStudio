/*
** EPITECH PROJECT, 2022
** screen
** File description:
** screen
*/

#pragma once

#include <raylib.h>

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
            Ray GetMouseRay(IndieVector2 mousePosition, IndieCamera camera) {
                return ::GetMouseRay(mousePosition, camera);
            }
            Matrix GetCameraMatrix(IndieCamera camera) {
                return ::GetCameraMatrix(camera);
            }
            Matrix GetCameraMatrix2D(IndieCamera camera) {
                return ::GetCameraMatrix2D(camera);
            }
            IndieVector2 GetWorldToScreen(IndieVector3 position, IndieCamera camera) {
                return ::GetMousePosition(position, camera);
            }
            IndieVector2 GetWorldToScreenEx(IndieVector3 position, IndieCamera camera) {
                return ::GetWorldToScreenEx(position, camera);
            }
            IndieVector2 GetWorldToScreen2D(IndieVector2 position, IndieCamera camera) {
                return ::GetWorldToScreen2D(position, camera);
            }
            IndieVector2 GetScreenToWorld2D(IndieVector2 position, IndieCamera camera) {
                return ::GetScreenToWorld2D(position, camera);
            }
		private:
	};
};