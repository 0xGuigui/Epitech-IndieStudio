/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** main
*/

#include "indieStudio.hpp"
#include "MapController.hpp"

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    Indie indie;

    for (; !indie.window.isClosed(); indie.timePlayed += GetFrameTime()) {
        if (IsKeyPressed(KEY_ESCAPE))
            break;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawFPS(10, 10);
        indie(indie.state);
        EndDrawing();
    }
    return 0;
}
