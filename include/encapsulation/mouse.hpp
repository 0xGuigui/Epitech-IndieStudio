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
			IndieMouse() {};
			IndieRay getRay(IndieVector2 mousePosition, IndieCamera3D camera) {
				return GetMouseRay(mousePosition, camera);
			}
			bool isButtonPressed(int button) {
				return IsMouseButtonPressed(button);
			}
			bool isButtonDown(int button) {
				return IsMouseButtonDown(button);
			}
			bool isButtonReleased(int button) {
				return IsMouseButtonReleased(button);
			}
			bool isButtonUp(int button) {
				return IsMouseButtonUp(button);
			}
			int getX() {
				return GetMouseX();
			}
			int getY() {
				return GetMouseY();
			}
			IndieVector2 getPosition() {
				return GetMousePosition();
			}
			IndieVector2 getDelta() {
				return GetMouseDelta();
			}
			void setPosition(int x, int y) {
				SetMousePosition(x, y);
			}
			void setOffset(int offsetX, int offsetY) {
				SetMouseOffset(offsetX, offsetY);
			}
			void setScale(float scaleX, float scaleY) {
				SetMouseScale(scaleX, scaleY);
			}
			float getWheelMove() {
				return GetMouseWheelMove();
			}
			void setCursor(int cursor) {
				SetMouseCursor(cursor);
			}
	};
};