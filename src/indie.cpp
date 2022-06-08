/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
*/

#include "indieStudio.hpp"

using namespace bmb;

Indie::Indie() : window(1080, 1920, "[PLATANOS STUDIOS] - IndieCraft"), loader("assets") {
    window.setMinSize(1, 1);
    window.setFPS(60);
}

Indie::~Indie() {}

float Indie::getTimeMusicPlayed() {
	return this->_musicPlayed;
}

float Indie::setTimeMusicPlayed(int time) {
	this->_musicPlayed = time;
	return this->_musicPlayed;
}