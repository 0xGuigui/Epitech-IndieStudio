/*
** EPITECH PROJECT, 2022
** texture.hpp
** File description:
** include
*/

#pragma once

#include "color.hpp"
#include <vector>
#include "rectangle.hpp"
#include "npatchInfo.hpp"
#include <iostream>

namespace bmb {
	class IndieTexture2D {
        private:
            Texture2D _texture{};

		public:
			IndieTexture2D() = default;

			IndieTexture2D(const std::string &fileName) : _texture(LoadTexture(fileName.c_str())) {};

			IndieTexture2D(Image &image) : _texture(LoadTextureFromImage(image)) {};

			IndieTexture2D(const IndieTexture2D &texture) = default;

			IndieTexture2D(Texture2D texture) {
				_texture = texture;
			}
			~IndieTexture2D() = default;
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
			void Draw(int posX, int posY, IndieColor tint) {
				DrawTexture(_texture, posX, posY, tint);
			}
			void DrawV(IndieVector2 &position, IndieColor tint) {
				DrawTextureV(_texture, position, tint);
			}
			void DrawEx(IndieVector2 &position, float rotation, float scale, IndieColor tint) {
				DrawTextureEx(_texture, position, rotation, scale, tint);
			}
			void DrawRec(IndieRectangle source, IndieVector2 offset, IndieVector2 position, IndieColor tint) {
				DrawTextureRec(_texture, source, position, tint);
			}
			void DrawQuad(IndieVector2 tiling, IndieVector2 offset, IndieRectangle quad, IndieColor tint) {
				DrawTextureQuad(_texture, tiling, offset, quad, tint);
			}
			void DrawTiled(IndieRectangle source, IndieRectangle dest, IndieVector2 origin, float rotation, float scale, IndieColor tint) {
				DrawTextureTiled(_texture, source, dest, origin, rotation, scale, tint);
			}
			void DrawPro(IndieRectangle source, IndieRectangle dest, IndieVector2 origin, float rotation, IndieColor tint) {
				DrawTexturePro(_texture, source, dest, origin, rotation, tint);
			}
			void DrawNPatch(IndieNPatchInfo nPatchInfo, IndieRectangle dest, IndieVector2 origin, float rotation, IndieColor tint) {
				DrawTextureNPatch(_texture, nPatchInfo, dest, origin, rotation, tint);
			}
			int getWidth() const {
				return _texture.width;
			}
			void setWidth(int width) {
				_texture.width = width;
			}
			int getHeight() const {
				return _texture.height;
			}
			void setHeight(int height) {
				_texture.height = height;
			}
			operator Texture2D() const {
				return _texture;
			};
	};
}