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

    for (; !bmb::IndieWindow::isClosed(); indie.timePlayed += GetFrameTime()) {
        if (IsKeyPressed(KEY_ESCAPE))
            break;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        indie(indie.state);
        EndDrawing();
    }
    return 0;
}
