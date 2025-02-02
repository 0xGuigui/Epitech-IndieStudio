/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** SplashScreen
*/

#include "indie.hpp"
#include "encapsulation/texture.hpp"

using namespace bmb;

void Indie::displaySplashScreen() {
    static IndieTexture2D &SplashScreenImage = loader.textures["splashscreen"];
    static IndieSound &SplashScreenSound = loader.sounds["splashscreen"];
    static IndieSound &closeSound = loader.sounds["close"];
    static bool isPlaying = false;

    if (!isPlaying && !SplashScreenSound.isPlaying()) {
        SplashScreenSound.Play();
        isPlaying = true;
    }
    // Get screen size
    if (IsKeyPressed(KEY_ESCAPE)) {
        closeSound.Play();
        while (closeSound.isPlaying());
        exit(0);
    }
    SplashScreenImage.setWidth(this->screenWidth);
    SplashScreenImage.setHeight(this->screenHeight);
    int x = (this->screen.GetWidth() - SplashScreenImage.getWidth()) / 2;
    int y = (this->screen.GetHeight() - SplashScreenImage.getHeight()) / 2;
    SplashScreenImage.Draw(x, y, WHITE);
    if (!SplashScreenSound.isPlaying())
        DrawRectangle(x + (SplashScreenImage.getWidth() / 2) - (SplashScreenImage.getWidth() / 4),
                      500 + (SplashScreenImage.getHeight() / 2) - (SplashScreenImage.getHeight() / 4),
                      SplashScreenImage.getWidth() / 2, SplashScreenImage.getHeight() / 32, WHITE);
    else
        DrawRectangle(x + (SplashScreenImage.getWidth() / 2) - (SplashScreenImage.getWidth() / 4),
                      500 + (SplashScreenImage.getHeight() / 2) - (SplashScreenImage.getHeight() / 4),
                      SplashScreenImage.getWidth() / 2 * this->timePlayed / 5.0f, SplashScreenImage.getHeight() / 32,
                      WHITE);
    if (this->screen.GetWidth() != this->screenWidth || this->screen.GetHeight() != this->screenHeight) {
        SplashScreenImage.setWidth(this->screen.GetWidth());
        SplashScreenImage.setHeight(this->screen.GetHeight());
        x = (this->screen.GetWidth() - SplashScreenImage.getWidth()) / 2;
        y = (this->screen.GetHeight() - SplashScreenImage.getHeight()) / 2;
        SplashScreenImage.Draw(x, y, WHITE);
        if (!SplashScreenSound.isPlaying())
            DrawRectangle(x + (SplashScreenImage.getWidth() / 2) - (SplashScreenImage.getWidth() / 4),
                          500 + (SplashScreenImage.getHeight() / 2) - (SplashScreenImage.getHeight() / 4),
                          SplashScreenImage.getWidth() / 2, SplashScreenImage.getHeight() / 32, WHITE);
        else
            DrawRectangle(x + (SplashScreenImage.getWidth() / 2) - (SplashScreenImage.getWidth() / 4),
                          500 + (SplashScreenImage.getHeight() / 2) - (SplashScreenImage.getHeight() / 4),
                          SplashScreenImage.getWidth() / 2 * this->timePlayed / 5.0f,
                          SplashScreenImage.getHeight() / 32, WHITE);
    }
    if (!SplashScreenSound.isPlaying()) {
        this->state = mainMenu;
        SplashScreenSound.Stop();
    }
}
