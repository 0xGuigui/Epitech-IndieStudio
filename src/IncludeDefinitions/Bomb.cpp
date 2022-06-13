/*
** EPITECH PROJECT, 2022
** Bomb.cpp
** File description:
** IncludeDefinitions
*/

#include "indie.hpp"

using namespace bmb;

void IndieBomb::updateExplosionAnimation() {
    if (frame > 15)
        return this->Delete();
    _bombExplosion.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = indie.loader.textures["explosion_" + std::to_string(frame)];
    for (IndieVector3 pos : explosion) {
        _bombExplosion.Draw(pos, 1.0f, WHITE);
    }
}

bool IndieBomb::isExplosionValid(IndieVector3 position, int &direction) {
    if (!(position.getX() >= -15.0f && position.getX() <= -3.0f &&
    position.getZ() <= 5.0f && position.getZ() >= -7.0f &&
    (static_cast<int>(round(position.getX())) % 2 != 0 || static_cast<int>(round(position.getZ())) % 2 != 0)))
        return direction = false;
    for (auto pos = indie.map.getDestructiblePositions().begin(); pos != indie.map.getDestructiblePositions().end(); pos++) {
        if ((*pos).getX() == position.getX() && (*pos).getZ() == position.getZ()) {
            indie.map.getDestructiblePositions().erase(pos);
            direction = false;
        }
    }
    for (Player &player : indie.players) {
        IndieVector3 playerPos(
            round(player.getPosition().getX()),
            0.5f,
            round(player.getPosition().getZ())
		);
        if (playerPos.getX() == position.getX() && playerPos.getZ() == position.getZ()) {
            //player.die();
        }
    }
    if (direction != 2) {
        for (IndieBomb &bomb : indie.bombs) {
            if ((_position.getX() != bomb._position.getX() || position.getZ() != _position.getZ()) &&
            (!bomb.bombExplosion && position.getX() == bomb._position.getX() && position.getZ() == bomb._position.getZ())) {
                bomb.bombExplosion = true;
                bomb._onDetonate();
                bomb.detonate();
                bomb.frame = 0;
            }
        }
    }
    return true;
}

void IndieBomb::detonate() {
    IndieVector3 exPos(_position.getX(), 0.5f, _position.getZ());
    int noDir = 2;
    if (isExplosionValid(exPos, noDir))
        explosion.push_back(exPos);
    for (int i = 1, left = true, right = true, up = true, down = true; i <= this->force; i++) {
        IndieVector3 explosionPos(_position.getX() + i, 0.5f, _position.getZ());
        IndieVector3 explosionPos2(_position.getX() - i, 0.5f, _position.getZ());
        IndieVector3 explosionPos3(_position.getX(), 0.5f, _position.getZ() + i);
        IndieVector3 explosionPos4(_position.getX(), 0.5f, _position.getZ() - i);
        if (down && isExplosionValid(explosionPos, down))
            this->explosion.push_back(explosionPos);
        if (up && isExplosionValid(explosionPos2, up))
            this->explosion.push_back(explosionPos2);
        if (right && isExplosionValid(explosionPos3, right))
            this->explosion.push_back(explosionPos3);
        if (left && isExplosionValid(explosionPos4, left))
            this->explosion.push_back(explosionPos4);
    }
}

void IndieBomb::Delete() {
    std::vector<bmb::IndieBomb>::iterator iterator;
    for (std::vector<bmb::IndieBomb>::iterator it = indie.bombs.begin(); it != indie.bombs.end(); it++) {
        IndieVector3 pos = (*it).getPosition();
        if (pos.getX() == _position.getX() && pos.getZ() == _position.getZ())
            iterator = it;
    }
    indie.bombs.erase(iterator);
}
