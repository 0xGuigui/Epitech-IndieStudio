/*
** EPITECH PROJECT, 2022
** matrix
** File description:
** matrix
*/

#pragma once

#include <raylib.h>

//si besoin de get plusieurs valeurs, add les get
namespace bmb {
	class IndieMatrix {
		public:
            IndieMatrix(float m00, float m01, float m02, float m03, float m04, float m05, float m06, float m07, float m08, float m09, float m10, float m11, float m12, float m13, float m14, float m15) {
                _matrix.m00 = m00;
                _matrix.m01 = m01;
                _matrix.m02 = m02;
                _matrix.m03 = m03;
                _matrix.m04 = m04;
                _matrix.m05 = m05;
                _matrix.m06 = m06;
                _matrix.m07 = m07;
                _matrix.m08 = m08;
                _matrix.m09 = m09;
                _matrix.m10 = m10;
                _matrix.m11 = m11;
                _matrix.m12 = m12;
                _matrix.m13 = m13;
                _matrix.m14 = m14;
                _matrix.m15 = m15;
            };
            ~IndieMatrix() {};
            operator Matrix () {
                return _matrix;
            }
		private:
            Matrix _matrix;
	};
};