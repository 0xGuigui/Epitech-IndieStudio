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
			int fps = 60;
			int height = 1080;
			int width = 1920;
		public:
			Window(int screenHeight = 1080, int screenWidth = 1920, std::string title = "") {
				InitWindow(screenWidth, screenHeight, title.c_str());
				height = screenHeight;
				width = screenWidth;
			}
			~Window() {
				CloseWindow();
			}
			int getHeight() {
				return this->height;
			}
			int getWidth() {
				return this->width;
			}
			void setFPS(int fps) {
				SetTargetFPS(fps);
				this->fps = fps;
			}
			int getFPS() {
				return this->fps;
			}
			bool isClosed() {
				return WindowShouldClose();
			}
			bool isReady() {
				return IsWindowReady();
			}
			bool isHidden() {
				return IsWindowHidden();
			}
			bool isMinimized() {
				return IsWindowMinimized();
			}
			bool isMaximized() {
				return IsWindowMaximized();
			}
			bool isResized() {
				return IsWindowResized();
			}
			bool isState(unsigned int flag) {
				return IsWindowState(flag);
			}
			void setState(unsigned int flags) {
				SetWindowState(flags);
			}
	};
};