/*
** EPITECH PROJECT, 2022
** texture.hpp
** File description:
** include
*/

#pragma once

#include "includes.hpp"

namespace bmb {
	class IndieTexture2D {
		public:
			IndieTexture2D() {};
			IndieTexture2D(const char *fileName) {
				texture = LoadTexture(fileName);
			};
			IndieTexture2D(Image &image) {
				texture = LoadTextureFromImage(image);
			};
			IndieTexture2D(IndieTexture2D &texture) {
				this->texture = texture.texture;
			};
			~IndieTexture2D() {
				UnloadTexture(texture);
			};
			void loadTexture(const char *fileName) {
				texture = LoadTexture(fileName);
			};
			void loadTexture(Image &image) {
				texture = LoadTextureFromImage(image);
			};
			void updateTexture(const void *pixels) {
				UpdateTexture(texture, pixels);
			};
			void updateTextureRec(Rectangle source, const void *pixels) {
				UpdateTextureRec(texture, source, pixels);
			};
			operator Texture2D () {
				return texture;
			};
		private:
			Texture2D texture;
	};
}