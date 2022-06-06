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
			char *_text;
		public:
			IndieText() {};
			IndieText(std::string fileName) {
				_text = LoadFileText(fileName.c_str());
			}
			void Unload() {
				UnloadFileText(_text);
			}
			// operator char * () {
			// 	return _text.c_str();
			// }
	};
};