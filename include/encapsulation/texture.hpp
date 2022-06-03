/*
** EPITECH PROJECT, 2022
** texture.hpp
** File description:
** include
*/

#pragma once

#include "color.hpp"
#include "vector.hpp"

namespace bmb {
	class IndieTexture2D {
        private:
            Texture2D _texture{};

		public:
			IndieTexture2D() = default;

			explicit IndieTexture2D(const char *fileName) : _texture(LoadTexture(fileName)) {};

			explicit IndieTexture2D(Image &image) : _texture(LoadTextureFromImage(image)) {};

			IndieTexture2D(IndieTexture2D &texture) {
				*this = texture;
			};
			~IndieTexture2D() {
				UnloadTexture(_texture);
			};
			void loadTexture(const char *fileName) {
				_texture = LoadTexture(fileName);
			};
			void loadTexture(Image &image) {
				_texture = LoadTextureFromImage(image);
			};
			void updateTexture(const void *pixels) {
				UpdateTexture(_texture, pixels);
			};
			void updateTextureRec(Rectangle source, const void *pixels) {
				UpdateTextureRec(_texture, source, pixels);
			};
			void Draw(int posX, int posY, IndieColor &tint) {
				DrawTexture(_texture, posX, posY, tint);
			}
			void DrawV(IndieVector2 &position, IndieColor &tint) {
				DrawTextureV(_texture, position, tint);
			}
			void DrawEx(IndieVector2 &position, float rotation, float scale, IndieColor &tint) {
				DrawTextureEx(_texture, position, rotation, scale, tint);
			}
			// TODO encapsulate Rectangle
			void DrawRec() {}
			// TODO reste du draw
			operator Texture2D() const {
				return _texture;
			};
	};
}