/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
*/

#include "indieStudio.hpp"

SplashScreen::SplashScreen()
{
}

SplashScreen::~SplashScreen()
{
}

int SplashScreen::SplashScreenAudio()
{
    return 0;
}

int SplashScreen::SplashScreenImage(const int screenWidth, const int screenHeight) {
    Texture2D texture = LoadTexture("assets/SplashScreen/images/splashscreen.png");
    texture.width = screenWidth;
    texture.height = screenHeight;
    int x = (screenWidth - texture.width) / 2;
    int y = (screenHeight - texture.height) / 2;
    DrawTexture(texture, x, y, WHITE);
    SplashScreenAudio();
    return 0;
}