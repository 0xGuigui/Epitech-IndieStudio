/*
** EPITECH PROJECT, 2022
** vector
** File description:
** vector
*/

#pragma once

#include <raylib.h>

namespace bmb {
	class IndieVector4 {
		public:
            IndieVector4(float x, float y, float z, float w) {
                _vector.y = y;
                _vector.x = x;
                _vector.z = z;
                _vector.w = w;
            }
            IndieVector4(Vector4 vec) {
                _vector = vec;
            }
			~IndieVector4() {};
            float getX() {
                return _vector.x;
            }
            float getY() {
                return _vector.y;
            }
            float getZ() {
                return _vector.z;
            }
            float getW() {
                return _vector.w;
            }
            operator Vector4 () {
                return _vector;
            }
		private:
            Vector4 _vector;
	};
};