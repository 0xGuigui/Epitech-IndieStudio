/*
** EPITECH PROJECT, 2022
** Bomb.cpp
** File description:
** IncludeDefinitions
*/

#include "indie.hpp"

using namespace bmb;

void IndieBomb::updateExplosionAnimation() {
    _bombExplosion.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = indie.loader.textures["explosion_" + frame];
    for (IndieVector3 pos : explosion) {
        _bombExplosion.Draw(pos, 1.0f, WHITE);
    }
}