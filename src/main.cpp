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

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    indie.window.Init(screenHeight, screenWidth, "[PLATANOS STUDIOS] - IndieCraft");
    indie.window.setMinSize(1, 1);
    bool pause = false;
    bool hasFilter = true;
    bool hasDelay = true;

    indie.window.setFPS(60);

    for (; !indie.window.isClosed(); indie.timePlayed += GetFrameTime()) {
        if (IsKeyPressed(KEY_ESCAPE))
            break;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
        indie(indie.state);
    }
    return 0;
}