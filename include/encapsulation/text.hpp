/*
** EPITECH PROJECT, 2022
** text.hpp
** File description:
** encapsulation
*/

#pragma once

#include "raylib.h"
#include <string>

namespace bmb {
	class IndieText {
		private:
			std::string _text;
		public:
			IndieText() {
				this->_text = "";
			};
			IndieText(const IndieText &other) {
				this->_text = other._text;
			};
			// void writeText(const char *text, int posX, int posY, int fontSize, Color color) {
			// 	DrawText(_text.c_str(), posX, posY, fontSize, color);
			// }
			operator char *() {
				return (char *)this->_text.c_str();
			}
	};
};