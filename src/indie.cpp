/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
*/

#include "indieStudio.hpp"

Indie::Indie() {}

Indie::~Indie() {}

void Indie::soundSplashScreen() {
    Sound SplashScreenSound = LoadSound("assets/SplashScreen/audios/splashscreen.wav");
    PlaySound(SplashScreenSound);
}

void Indie::displaySplashScreen() {
    Texture2D SplashScreenImage = LoadTexture("assets/SplashScreen/images/splashscreen.png");
    SplashScreenImage.width = 1920;
    SplashScreenImage.height = 1080;
    int x = (GetScreenWidth() - SplashScreenImage.width) / 2;
    int y = (GetScreenHeight() - SplashScreenImage.height) / 2;
    DrawTexture(SplashScreenImage, x, y, WHITE);
}

