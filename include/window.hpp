/*
** EPITECH PROJECT, 2022
** window.hpp
** File description:
** include
*/

#pragma once

#include "includes.hpp"

namespace bmb {
	class IndieWindow {
		private:
			int fps = 60;
			int height = 1080;
			int width = 1920;
		public:
			IndieWindow() {};
			IndieWindow(int screenHeight, int screenWidth, std::string title = "") {
				InitWindow(screenWidth, screenHeight, title.c_str());
				height = screenHeight;
				width = screenWidth;
			}
			~IndieWindow() {
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
			bool isFocused() {
				return IsWindowFocused();
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
			void clearState(unsigned int flags = 0) {
				ClearWindowState(flags);
			}
			void setTitle(std::string title) {
				SetWindowTitle(title.c_str());
			}
			void setPosition(int x, int y) {
				SetWindowPosition(x, y);
			}
			void setMinSize(int width, int height) {
				SetWindowMinSize(width, height);
			}
			void setIcon(IndieImage icon) {
				return SetWindowIcon(icon.getImage());
			}
	};
};