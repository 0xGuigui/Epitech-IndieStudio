/*
** EPITECH PROJECT, 2022
** Player.hpp
** File description:
** include
*/

#include "indieStudio.hpp"
#include "raymath.h"

//ModelGetBoundingBox

namespace bmb {
	class Player {
		private:
			IndieModel playerModel;
			ModelAnimation *anim;
			int frame = 0;
			IndieColor playerColor = WHITE;
			IndieVector3 position;
			bool _animate = false;
		public:
			Player() = default;
			Player(std::string path, IndieColor color, IndieVector3 position) {
				unsigned int count = 0;
				IndieTexture2D texture("assets/char.png");

				playerColor = color;
				this->position = position;
				playerModel.LoadModel("assets/Steve.iqm");
				anim = LoadModelAnimations("assets/Steve.iqm", &count);
				playerModel.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
			}
			void startAnimation() {
				_animate = true;
			}
			void stopAnimation() {
				_animate = false;
			}
			bool isAnimated() {
				return _animate;
			}
			void turnRight() {
				playerModel.getModel().transform = MatrixRotateXYZ({-61.4f, 0.0f, 0.0f});
			}
			void turnLeft() {
				playerModel.getModel().transform = MatrixRotateXYZ({-61.4f, -59.7f, 0.0f});
			}
			void turnUp() {
				playerModel.getModel().transform = MatrixRotateXYZ({-61.4f, 29.85f, -0.3f});
			}
			void turnDown() {
				playerModel.getModel().transform = MatrixRotateXYZ({-61.4f, -29.85f, 0.0f});
			}
			void Draw() {
				frame += _animate ? 2 : 0;
				if (frame >= 110)
					frame = 0;
				UpdateModelAnimation(playerModel, anim[0], frame);
				playerModel.Draw(position, 0.5f, playerColor);
			}
	};
}