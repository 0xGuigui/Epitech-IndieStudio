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

    indie.players[0].setControls((KeyboardKey[5]){KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT, KEY_SPACE});
    indie.players[1].setControls((KeyboardKey[5]){KEY_W, KEY_S, KEY_D, KEY_A, KEY_Q});
    indie.players[2].setControls((KeyboardKey[5]){KEY_T, KEY_G, KEY_H, KEY_F, KEY_R});
    indie.players[3].setControls((KeyboardKey[5]){KEY_I, KEY_K, KEY_L, KEY_J, KEY_U});
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
