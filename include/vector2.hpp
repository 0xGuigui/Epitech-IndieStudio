/*
** EPITECH PROJECT, 2022
** vector
** File description:
** vector
*/

#pragma once

#include <raylib.h>

namespace bmb {
	class IndieVector2 {
		public:
            IndieVector2(float x, float y) {
                _vector.y = y;
                _vector.x = x;
            }
			~IndieVector2() {};
            float getX() {
                return _vector.x;
            }
            float getY() {
                return _vector.y;
            }
		private:
            Vector2 _vector;
	};
};