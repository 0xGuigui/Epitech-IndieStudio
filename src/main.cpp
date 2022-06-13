/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** main
*/

#include "indie.hpp"
#include "MapController.hpp"

Indie indie;

int main(void) {
    ToggleFullscreen();
    KeyboardKey playerControls[5] = {KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT, KEY_SPACE};
    KeyboardKey playerControls2[5] = {KEY_W, KEY_S, KEY_D, KEY_A, KEY_Q};
    KeyboardKey playerControls3[5] = {KEY_T, KEY_G, KEY_H, KEY_F, KEY_R};
    KeyboardKey playerControls4[5] = {KEY_I, KEY_K, KEY_L, KEY_J, KEY_U};
    indie.players[0].setControls(playerControls);
    indie.players[1].setControls(playerControls2);
    indie.players[2].setControls(playerControls3);
    indie.players[3].setControls(playerControls4);
    indie.state = indieState::splashScreen;
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
