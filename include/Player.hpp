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
		public:
			Player() = default;
			Player(std::string path) {
				IndieTexture2D texture("assets/InGame/scene.png");
				playerModel.LoadModel("assets/InGame/scene.gltf");
				playerModel.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
			}
			void Draw() {
				playerModel.Draw({-15.0f, 0.5f, -5.0f}, 1.0f, WHITE);
			}
	};
}