/*
** EPITECH PROJECT, 2022
** PowerUp.cpp
** File description:
** IncludeDefinitions
*/

#include "indie.hpp"
#include "components/powerUp.hpp"

using namespace bmb;

void IndiePowerUp::update() {
	for (IndieVector3 &obstaclePos : indie.map.getDestructiblePositions()) {
		if (obstaclePos.getX() == _position.getX() && obstaclePos.getZ() == _position.getZ())
			return;
	}
	_powerUp.Draw(_position, 1.3f, WHITE);
	IndieRectangle rectangleBonus(_position.getX(), _position.getZ(), 0.75f, 0.75f);
	for (Player &player : indie.players) {
		IndieRectangle rectanglePlayer(player.getPosition().getX(), player.getPosition().getZ(), 0.75f, 0.75f);
		if (CheckCollisionRecs(rectangleBonus, rectanglePlayer)) {
			_onPick(player);
			return this->Delete();
		}
	}
	frame++;
}

void IndiePowerUp::Delete()  {
	for (auto it = indie.map.getBonuses().begin(); it != indie.map.getBonuses().end(); it++) {
		IndieVector3 pos = (*it).getPosition();
		if (pos.getX() == _position.getX() && pos.getZ() == _position.getZ())
			it = indie.map.getBonuses().erase(it);
		if (it == indie.map.getBonuses().end())
			break;
	}
}