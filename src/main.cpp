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
    InitWindow(screenWidth, screenHeight, "[PLATANOS STUDIOS] Indie Studio");
    SetWindowMinSize(1, 1);

    float timePlayed = 0.0f;
    bool pause = false;
    bool hasFilter = true;
    bool hasDelay = true;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ESCAPE))
            break;
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}