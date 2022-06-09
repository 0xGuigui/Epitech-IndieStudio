/*
** EPITECH PROJECT, 2022
** Player.hpp
** File description:
** include
*/

#include "indieStudio.hpp"

//ModelGetBoundingBox

namespace bmb {
	class Player {
		private:
			IndieModel playerModel;
			ModelAnimation *anim;
		public:
			Player() = default;
			Player(std::string path) {
				unsigned int count = 1;

				playerModel.LoadModel("assets/Steve.iqm");
				anim = LoadModelAnimations("assets/Steve.iqm", &count);
				std::cout << "AAAAAAAAAAAAAAAAA  " << IsModelAnimationValid(playerModel, *anim) << "  AAAAAAAAAAAAAAAAAAAAA" << std::endl;
			}
			void Draw() {
				playerModel.Draw({-15.0f, 0.5f, -5.0f}, 1.0f, WHITE);
			}
	};
}