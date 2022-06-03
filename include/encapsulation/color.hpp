/*
** EPITECH PROJECT, 2022
** color.hpp
** File description:
** include
*/

#pragma once

#include "raylib.h"

namespace bmb {
	class IndieColor {
        private:
            Color _color{};

		public:
			IndieColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
                _color.r = r;
                _color.g = g;
                _color.b = b;
                _color.a = a;
			}
			// From HSV
			IndieColor(float hue, float saturation, float value) : _color(ColorFromHSV(hue, saturation, value)) {}
			explicit IndieColor(unsigned int hexValue) : _color(GetColor(hexValue)) {}

			void Fade(float alpha) {
				_color = ::Fade(this->_color, alpha);
			}
			int ToInt() {
				return ColorToInt(this->_color);
			}
			void Alpha(float alpha) {
				this->_color = ColorAlpha(this->_color, alpha);
			}
			operator Color() const {
				return _color;
			}
	};
};