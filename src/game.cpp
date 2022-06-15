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
    if (this->_musicPlay && !loader.musics["InGame_Music"].isPlaying())
        loader.musics["InGame_Music"].Play();
    int nbAlive = 0;
    for (Player &player : indie.players) {
        player.Draw();
        if (player.isAlive())
            nbAlive++;
    }
    if (nbAlive == 1) {
        indie.state = endMenu;
        loader.musics["InGame_Music"].Stop();
    }
    for (IndieBomb &bomb : indie.bombs)
        bomb.update();
    for (IndiePowerUp &powerUp : indie.map.getBonuses())
        powerUp.update();
    this->map.end3D();
}