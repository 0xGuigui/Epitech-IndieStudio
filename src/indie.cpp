/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
*/

#include "indie.hpp"

using namespace bmb;

Indie::Indie() :
        window(1080, 1920, "[PLATANOS STUDIOS] - IndieCraft"),
        loader("assets"),
        map(loader.images["map"], loader.images["map_obstacles"],
            loader.textures["block"], loader.textures["brick"], loader.textures["oak_planks"],
            {-16.0f, 0.0f, -8.0f},
            {
            { -15.0f, 24.0f, -1.0f },
            { -9.0f, 0.0f, -1.0f },
            { 0.0f, 1.0f, 0.0f },
            45.0f, 0}) {
    bmb::IndieWindow::setMinSize(1, 1);
    window.setFPS(60);
}

float Indie::getTimeMusicPlayed() const {
	return this->_musicPlayed;
}

float Indie::setTimeMusicPlayed(int time) {
	this->_musicPlayed = time;
	return this->_musicPlayed;
}
