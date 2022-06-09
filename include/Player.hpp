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
			bool _animate = true;
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
				std::cout << "AAAAAAAAAAAAAAAAA  " << count << "  AAAAAAAAAAAAAAAAAAAAA" << std::endl;
				std::cout << "AAAAAAAAAAAAAAAAA  " << IsModelAnimationValid(playerModel, anim[0]) << "  AAAAAAAAAAAAAAAAAAAAA" << std::endl;
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
			void Draw() {
				frame += _animate ? 2 : 0;
				if (frame >= 110)
					frame = 0;
				UpdateModelAnimation(playerModel, anim[0], frame);
				//61.4f
				playerModel.getModel().transform = MatrixRotateXYZ({-61.4f, 0.0f, 0.0f});
				playerModel.Draw(position, 1.0f, playerColor);
			}
	};
}