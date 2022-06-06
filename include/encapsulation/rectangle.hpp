/*
** EPITECH PROJECT, 2022
** rectangle.hpp
** File description:
** encapsulation
*/

#include "color.hpp"
#include "vector.hpp"

namespace bmb {
	class IndieRectangle {
		private:
			Rectangle _rec;
		public:
			IndieRectangle() {};
			IndieRectangle(float x, float y, float width, float height) {
				_rec = {
					.x = x,
					.y = y,
					.width = width,
					.height = height
				};
			};
			IndieRectangle(Rectangle rec) {
				_rec = rec;
			}
			void Draw(IndieColor color) {
				DrawRectangle(static_cast<int>(_rec.x), static_cast<int>(_rec.y), static_cast<int>(_rec.width), static_cast<int>(_rec.height), color);
			}
			void DrawPro(IndieVector2 origin, float rotation, IndieColor color) {
				DrawRectanglePro(_rec, origin, rotation, color);
			}
			void DrawGradientEx(IndieColor col1, IndieColor col2, IndieColor col3, IndieColor col4) {
				DrawRectangleGradientEx(_rec, col1, col2, col3, col4);
			}
			void DrawLinesEx(float lineThick, IndieColor color) {
				DrawRectangleLinesEx(_rec, lineThick, color);
			}
			void DrawRounded(float roundness, int segments, IndieColor color) {
				DrawRectangleRounded(_rec, roundness, segments, color);
			}
			void DrawRoundedLines(float roundness, int segments, float lineThick, IndieColor color) {
				DrawRectangleRoundedLines(_rec, roundness, segments, lineThick, color);
			}
			void setCollisionRect(IndieRectangle rec, IndieRectangle rec2) {
				_rec = GetCollisionRec(rec, rec2);
			}
			operator Rectangle () {
				return this->_rec;
			}
	};
};