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
			bool hasBinded = false;
		public:
			Player() = default;
			Player(IndieColor color, IndieVector3 position, KeyboardKey controls[5]) {
				unsigned int count = 0;
				IndieTexture2D texture("assets/char.png");

				playerColor = color;
				this->position = position;
				playerModel.LoadModel("assets/Steve.iqm");
				anim = LoadModelAnimations("assets/Steve.iqm", &count);
				playerModel.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
				setKeyUp(controls[0]);
				setKeyDown(controls[1]);
				setKeyRight(controls[2]);
				setKeyLeft(controls[3]);
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
			void setKeyLeft(KeyboardKey key) {
				hasBinded = true;
				bmb::keyboard.bind(key, [&]() -> void {
					turnLeft();
					position = { position.getX(), position.getY(), position.getZ() - 0.05f};
					_animate = true;
				}, [&]() -> void {
					_animate = false;
					frame = 0;
				});
			}
			void setKeyRight(KeyboardKey key) {
				hasBinded = true;
				bmb::keyboard.bind(key, [&]() -> void {
					turnRight();
					position = { position.getX(), position.getY(), position.getZ() + 0.05f };
					_animate = true;
				}, [&]() -> void {
					_animate = false;
					frame = 0;
				});
			}
			void setKeyUp(KeyboardKey key) {
				hasBinded = true;
				bmb::keyboard.bind(key, [&]() -> void {
					turnUp();
					position = { position.getX() + 0.05f, position.getY(), position.getZ()};
					_animate = true;
				}, [&]() -> void {
					_animate = false;
					frame = 0;
				});
			}
			void setKeyDown(KeyboardKey key) {
				hasBinded = true;
				bmb::keyboard.bind(key, [&]() -> void {
					turnDown();
					position = { position.getX() - 0.05f, position.getY(), position.getZ()};
					_animate = true;
				}, [&]() -> void {
					_animate = false;
					frame = 0;
				});
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