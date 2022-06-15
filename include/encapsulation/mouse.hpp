/*
** EPITECH PROJECT, 2022
** mouse.hpp
** File description:
** encapsulation
*/

#pragma once

#include "ray.hpp"
#include "camera.hpp"

namespace bmb {
	class IndieMouse {
		private:
		public:
			IndieMouse() = default;
			static IndieRay getRay(IndieVector2 mousePosition, IndieCamera3D camera) {
				return GetMouseRay(mousePosition, camera);
			}
			static bool isButtonPressed(int button) {
				return IsMouseButtonPressed(button);
			}
			static bool isButtonDown(int button) {
				return IsMouseButtonDown(button);
			}
			static bool isButtonReleased(int button) {
				return IsMouseButtonReleased(button);
			}
			static bool isButtonUp(int button) {
				return IsMouseButtonUp(button);
			}
			static int getX() {
				return GetMouseX();
			}
			static int getY() {
				return GetMouseY();
			}
			static IndieVector2 getPosition() {
				return GetMousePosition();
			}
			static IndieVector2 getDelta() {
				return GetMouseDelta();
			}
			static void setPosition(int x, int y) {
				SetMousePosition(x, y);
			}
			static void setOffset(int offsetX, int offsetY) {
				SetMouseOffset(offsetX, offsetY);
			}
			static void setScale(float scaleX, float scaleY) {
				SetMouseScale(scaleX, scaleY);
			}
			static float getWheelMove() {
				return GetMouseWheelMove();
			}
			static void setCursor(int cursor) {
				SetMouseCursor(cursor);
			}
	};
}
