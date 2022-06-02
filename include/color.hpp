/*
** EPITECH PROJECT, 2022
** color.hpp
** File description:
** include
*/

#pragma once

#include "includes.hpp"

namespace bmb {
	class IndieColor {
		public:
			IndieColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
				this->color = {
					.r = r,
					.g = g,
					.b = b,
					.a = a
				};
			}
			// From HSV
			IndieColor(float hue, float saturation, float value) {
				this->color = ColorFromHSV(hue, saturation, value);
			}
			IndieColor(unsigned int hexValue) {
				this->color = GetColor(hexValue);
			}
			void Fade(float alpha) {
				this->color = ::Fade(this->color, alpha);
			}
			int ToInt() {
				return ColorToInt(this->color);
			}
			void Alpha(float alpha) {
				this->color = ColorAlpha(this->color, alpha);
			}
			operator Color () {
				return this->color;
			}
		private:
			Color color;
	};
};