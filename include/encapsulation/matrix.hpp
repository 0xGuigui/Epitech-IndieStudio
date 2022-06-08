/*
** EPITECH PROJECT, 2022
** matrix
** File description:
** matrix
*/

#pragma once

#include "raylib.h"

//si besoin de get plusieurs valeurs, add les get
namespace bmb {
	class IndieMatrix {
        private:
            Matrix _matrix;

		public:
            IndieMatrix(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15) {
                _matrix.m0 = m0;
                _matrix.m1 = m1;
                _matrix.m2 = m2;
                _matrix.m3 = m3;
                _matrix.m4 = m4;
                _matrix.m5 = m5;
                _matrix.m6 = m6;
                _matrix.m7 = m7;
                _matrix.m8 = m8;
                _matrix.m9 = m9;
                _matrix.m10 = m10;
                _matrix.m11 = m11;
                _matrix.m12 = m12;
                _matrix.m13 = m13;
                _matrix.m14 = m14;
                _matrix.m15 = m15;
            };
            IndieMatrix (const Matrix &matrix) : _matrix(matrix) {};
            ~IndieMatrix() {};
            operator Matrix() const {
                return _matrix;
            }
            operator Matrix *() {
                return &_matrix;
            }
	};
};