/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** main
*/

#include "indieStudio.hpp"
#include "MapController.hpp"

namespace bmb {
    KeyboardManager keyboard;
}

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    Indie indie;

    // indie.state = inGame;
    SetExitKey(KEY_NULL);
    for (; !bmb::IndieWindow::isClosed(); indie.timePlayed += GetFrameTime()) {
        bmb::keyboard.update();
        if (IsKeyPressed(KEY_ESCAPE))
            break;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        indie(indie.state);
        EndDrawing();
    }
    return 0;
}
