/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
*/

#include "indieStudio.hpp"

Indie::Indie() {}

Indie::~Indie() {}

void Indie::displaySplashScreen() {
    Texture2D splashScreen = LoadTexture("assets/SplashScreen/images/splashscreen.png");
    // if (IsAudioDeviceReady()) {

    // }
    this->_music.looping = false;
    splashScreen.width = 1920;
    splashScreen.height = 1080;
    int x = (GetScreenWidth() - splashScreen.width) / 2;
    int y = (GetScreenHeight() - splashScreen.height) / 2;
    DrawTexture(splashScreen, x, y, WHITE);
    //PlayMusicStream(this->_music);
    //UpdateMusicStream(this->_music);
    return;
}

