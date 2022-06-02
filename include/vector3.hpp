/*
** EPITECH PROJECT, 2022
** vector
** File description:
** vector
*/

#pragma once

#include <raylib.h>

namespace bmb {
	class IndieVector3 {
		public:
            IndieVector3(float x, float y, float z) {
                _vector.y = y;
                _vector.x = x;
                _vector.z = z;
            }
			~IndieVector3() {};
            float getX() {
                return _vector.x;
            }
            float getY() {
                return _vector.y;
            }
            float getZ() {
                return _vector.z;
            }
            operator Vector3 () {
                return _vector;
            }
		private:
            Vector3 _vector;
	};
};