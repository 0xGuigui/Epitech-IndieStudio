/*
** EPITECH PROJECT, 2022
** vector
** File description:
** vector
*/

#pragma once

#include "raylib.h"

namespace bmb {
	class IndieVector2 {
		public:
            IndieVector2(float x = 0.0f, float y = 0.0f) {
                _vector.y = y;
                _vector.x = x;
            }
            IndieVector2(const Vector2 &vec) : _vector(vec) {}
			~IndieVector2() = default;;
            float getX() const {
                return _vector.x;
            }
            float getY() const {
                return _vector.y;
            }
            operator Vector2() const {
                return _vector;
            }
            IndieVector2 operator + (const IndieVector2 &vec) const {
                return IndieVector2(_vector.x + vec.getX(), _vector.y + vec.getY());
            }
		private:
            Vector2 _vector{};
	};

    class IndieVector3 {
    public:
        IndieVector3() {};
        IndieVector3(float x, float y, float z) {
            _vector.y = y;
            _vector.x = x;
            _vector.z = z;
        }
        IndieVector3(const Vector3 &vec) {
            _vector = vec;
        }
        ~IndieVector3() {};
        float getX() const {
            return _vector.x;
        }
        float getY() const {
            return _vector.y;
        }
        float getZ() const {
            return _vector.z;
        }
        void incrementZ(float z) {
            _vector.z += z;
        }
        void setZ(float z) {
            _vector.z = z;
        }
        void decrementX(float x) {
            _vector.x -= x;
        }
        Vector3 &getVector() {
            return _vector;
        }
        operator Vector3() const {
            return _vector;
        }
        bool operator == (const IndieVector3 &vec) const {
            return _vector.x == vec.getX() && _vector.z == vec.getZ();
        }
    private:
        Vector3 _vector{};
    };

    class IndieVector4 {
    public:
        IndieVector4(float x, float y, float z, float w) {
            _vector.y = y;
            _vector.x = x;
            _vector.z = z;
            _vector.w = w;
        }
        IndieVector4(const Vector4 &vec) {
            _vector = vec;
        }
        ~IndieVector4() {};
        float getX() const {
            return _vector.x;
        }
        float getY() const {
            return _vector.y;
        }
        float getZ() const {
            return _vector.z;
        }
        float getW() const {
            return _vector.w;
        }
        operator Vector4() const {
            return _vector;
        }
    private:
        Vector4 _vector{};
    };
}
