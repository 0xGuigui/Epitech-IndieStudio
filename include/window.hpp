/*
** EPITECH PROJECT, 2022
** window.hpp
** File description:
** include
*/

#pragma once

#include "includes.hpp"

namespace bmb {
	class Window {
		private:
		public:
			Window(int screenHeight = 1080, int screenWidth = 1920, std::string title = "") {
				InitWindow(screenWidth, screenHeight, title.c_str());
			}
			~Window() {
				CloseWindow();
			}
			void setFPS(int fps) {
				SetTargetFPS(fps);
			}
			bool isClosed() {
				return WindowShouldClose();
			}
	};
};