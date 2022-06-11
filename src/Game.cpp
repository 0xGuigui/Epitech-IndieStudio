/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** Menus
*/

#include "indie.hpp"

using namespace bmb;

void Indie::bomberMan() {
    if (!this->map.isCameraUpdated())
    this->map.updateCamera();
    this->map.begin3D();
    this->map.Draw();
    for (Player &player : indie.players)
        player.Draw();
    for (IndieBomb &bomb : indie.bombs)
        bomb.update();
    this->map.end3D();
}