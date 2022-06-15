/*
** EPITECH PROJECT, 2022
** Bomb.cpp
** File description:
** IncludeDefinitions
*/

#include "indie.hpp"

using namespace bmb;

IndieBomb::IndieBomb(int force, IndieVector3 position, const std::function<void()> &onDetonate) {
    this->force = force;
    _bomb = indie.loader.models["tnt"];
    IndieMesh mesh;
    mesh.GenCube(1.0f, 1.0f, 1.0f);
    _bombExplosion.LoadFromMesh(mesh);
    _position = position;
    _onDetonate = onDetonate;
}

void IndieBomb::updateExplosionAnimation() {
    if (frame > 15)
        return this->Delete();
    _bombExplosion.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = indie.loader.textures["explosion_" + std::to_string(frame)];
    for (const IndieVector3& pos : explosion) {
        _bombExplosion.Draw(pos, 1.0f, WHITE);
    }
}

bool IndieBomb::isExplosionValid(const IndieVector3& position, int &direction) {
    if (!(position.getX() >= -15.0f && position.getX() <= -3.0f &&
    position.getZ() <= 5.0f && position.getZ() >= -7.0f &&
    (static_cast<int>(round(position.getX())) % 2 != 0 || static_cast<int>(round(position.getZ())) % 2 != 0))) {
        direction = false;
        return false;
    }
    bool removed = false;
    for (auto pos = indie.map.getDestructiblePositions().begin(); pos != indie.map.getDestructiblePositions().end(); pos++) {
        if (pos->getX() == position.getX() && pos->getZ() == position.getZ()) {
            pos = indie.map.getDestructiblePositions().erase(pos);
            direction = false;
            removed = true;
            if (pos == indie.map.getDestructiblePositions().end())
                break;
        }
    }
    if (removed)
        return true;
    if (direction != 2) {
        for (IndieBomb &bomb : indie.bombs) {
            if ((_position.getX() != bomb._position.getX() || position.getZ() != _position.getZ()) &&
            (!bomb.bombExplosion && position.getX() == bomb._position.getX() && position.getZ() == bomb._position.getZ())) {
                bomb.bombExplosion = true;
                bomb._onDetonate();
                bomb.detonate();
                bomb.frame = 0;
                return true;
            }
        }
    }
    for (Player &player : indie.players) {
        IndieVector3 playerPos(
            round(player.getPosition().getX()),
            0.5f,
            round(player.getPosition().getZ())
		);
        if (playerPos.getX() == position.getX() && playerPos.getZ() == position.getZ()) {
            player.die();
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
        IndieVector3 explosionPos(_position.getX() + static_cast<float>(i), 0.5f, _position.getZ());
        IndieVector3 explosionPos2(_position.getX() - static_cast<float>(i), 0.5f, _position.getZ());
        IndieVector3 explosionPos3(_position.getX(), 0.5f, _position.getZ() + static_cast<float>(i));
        IndieVector3 explosionPos4(_position.getX(), 0.5f, _position.getZ() - static_cast<float>(i));
        if (down && isExplosionValid(explosionPos, down))
            this->explosion.push_back(explosionPos);
        if (up && isExplosionValid(explosionPos2, up))
            this->explosion.push_back(explosionPos2);
        if (right && isExplosionValid(explosionPos3, right))
            this->explosion.push_back(explosionPos3);
        if (left && isExplosionValid(explosionPos4, left))
            this->explosion.push_back(explosionPos4);
        if (!left && !right && !up && !down)
            break;
    }
}

void IndieBomb::Delete() {
    for (auto it = indie.bombs.begin(); it != indie.bombs.end(); it++) {
        IndieVector3 pos = (*it).getPosition();
        if (pos.getX() == _position.getX() && pos.getZ() == _position.getZ())
            it = indie.bombs.erase(it);
        if (it == indie.bombs.end())
            break;
    }
}
