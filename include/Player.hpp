/*
** EPITECH PROJECT, 2022
** Player.hpp
** File description:
** include
*/

#pragma once

#include "indieStudio.hpp"
#include "raymath.h"
#include <cmath>

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
				indie.keyboard.bind(key, [&]() -> void {
					turnLeft();
					// Rectangle playerRect = {position.getX(), position.getY(), position.getX() + 0.75f, position.getY() + 0.75f};
					if (position.getZ() > -7.35f && (static_cast<int>(round(position.getX())) % 2 != 0 || static_cast<int>(round(position.getZ() - 0.35f)) % 2 != 0))
						position = { position.getX(), position.getY(), position.getZ() - 0.05f};
					_animate = true;
				}, [&]() -> void {
					_animate = false;
					frame = 0;
				});
			}
			void setKeyRight(KeyboardKey key) {
				hasBinded = true;
				indie.keyboard.bind(key, [&]() -> void {
					turnRight();
					if (position.getZ() < 5.35f && (static_cast<int>(round(position.getX())) % 2 != 0 || static_cast<int>(round(position.getZ() + 0.35f)) % 2 != 0))
						position = { position.getX(), position.getY(), position.getZ() + 0.05f };
					_animate = true;
				}, [&]() -> void {
					_animate = false;
					frame = 0;
				});
			}
			void setKeyUp(KeyboardKey key) {
				hasBinded = true;
				indie.keyboard.bind(key, [&]() -> void {
					turnUp();
					if (position.getX() < -3.0f && (static_cast<int>(round(position.getX() + 0.35f)) % 2 != 0 || static_cast<int>(round(position.getZ())) % 2 != 0))
						position = { position.getX() + 0.05f, position.getY(), position.getZ()};
					_animate = true;
				}, [&]() -> void {
					_animate = false;
					frame = 0;
				});
			}
			void setKeyDown(KeyboardKey key) {
				hasBinded = true;
				indie.keyboard.bind(key, [&]() -> void {
					turnDown();
					if (position.getX() > -15.35f && (static_cast<int>(round(position.getX() - 0.35f)) % 2 != 0 || static_cast<int>(round(position.getZ())) % 2 != 0))
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