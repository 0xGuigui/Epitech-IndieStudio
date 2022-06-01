/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** main
*/

#include "indieStudio.hpp"

int main(void) {
    Indie indie;
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    indie.window.Init(screenHeight, screenWidth, "[PLATANOS STUDIOS] - Indie Studio");
    indie.window.setMinSize(1, 1);
    float timePlayed = 0.0f;
    bool pause = false;
    bool hasFilter = true;
    bool hasDelay = true;

    indie.window.setFPS(60);

    while (!indie.window.isClosed()) {
        if (IsKeyPressed(KEY_ESCAPE))
            break;
        BeginDrawing();
            indie.displaySplashScreen();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }
    return 0;
}