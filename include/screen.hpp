/*
** EPITECH PROJECT, 2022
** screen
** File description:
** screen
*/

#include "includes.hpp"

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
            Ray GetMouseRay(Vector2 mousePosition, Camera camera) {
                return ::GetMouseRay(Vector2 mousePosition, Camera camera);
            }
            Matrix GetCameraMatrix(Camera camera) {
                return ::GetCameraMatrix(camera);
            }
            Matrix GetCameraMatrix2D(Camera camera) {
                return ::GetCameraMatrix2D(camera);
            }
            Vector2 GetWorldToScreen(Vector3 position, Camera camera) {
                return ::GetMousePosition(position, camera);
            }
            Vector2 GetWorldToScreenEx(Vector3 position, Camera camera) {
                return ::GetWorldToScreenEx(position, camera);
            }
            Vector2 GetWorldToScreen2D(Vector2 position, Camera camera) {
                return ::GetWorldToScreen2D(position, camera);
            }
            Vector2 GetScreenToWorld2D(Vector2 position, Camera camera) {
                return ::GetScreenToWorld2D(position, camera);
            }
		private:
	};
};