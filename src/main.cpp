/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** main
*/

#include "indieStudio.hpp"
#include "MapController.hpp"

Indie indie;

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    indie.state = inGame;
    SetExitKey(KEY_NULL);
    for (; !bmb::IndieWindow::isClosed(); indie.timePlayed += GetFrameTime()) {
        indie.keyboard.update();
        if (IsKeyPressed(KEY_ESCAPE))
            break;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        indie(indie.state);
        EndDrawing();
    }
    return 0;
}
