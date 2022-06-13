/*
** EPITECH PROJECT, 2022
** window.hpp
** File description:
** include
*/

#pragma once

#include "image.hpp"
#include "audioDevice.hpp"
#include "music.hpp"

namespace bmb {
	class IndieWindow {
		private:
			int _fps = 60;
			int _height = 1080;
			int _width = 920;
            bmb::IndieAudioDevice audioDevice;
		public:
			IndieWindow() = default;
			IndieWindow(int screenHeight, int screenWidth, const std::string& title = "") {
				InitWindow(screenWidth, screenHeight, title.c_str());
				_height = screenHeight;
				_width = screenWidth;
			}
			~IndieWindow() {
				CloseWindow();
			}
			void Init(int screenHeight, int screenWidth, const std::string& title = "") {
				InitWindow(screenWidth, screenHeight, title.c_str());
				_height = screenHeight;
				_width = screenWidth;
			}
			int getHeight() const {
				return _height;
			}
			int getWidth() const {
				return _width;
			}
			void setFPS(int fps) {
				SetTargetFPS(fps);
				_fps = fps;
			}
			int getFPS() const {
				return _fps;
			}
			static bool isClosed() {
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
			static void setTitle(const std::string& title) {
				SetWindowTitle(title.c_str());
			}
			void setPosition(int x, int y) {
				SetWindowPosition(x, y);
			}
			static void setMinSize(int width, int height) {
				SetWindowMinSize(width, height);
			}
			static void setIcon(const IndieImage& icon) {
				return SetWindowIcon(icon.getImage());
			}
	};
}
