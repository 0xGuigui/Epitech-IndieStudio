/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** main
*/

#include "indie.hpp"
#include "components/mapController.hpp"
#include <iostream>

Indie indie;

int main() {
    std::srand(std::time(NULL));
    KeyboardKey playerControls[5] = {KEY_UP, KEY_DOWN, KEY_RIGHT, KEY_LEFT, KEY_SPACE};
    indie.players[0].setControls(playerControls);
    indie.state = indieState::splashScreen;
    indie.keyboard.bind(KEY_BACKSPACE, [&]() -> void {
        indie.loader.musics["InGame_Music"].Stop();
        indie.state = gameMenu;
    }, []() -> void {}, inGame);
    SetExitKey(KEY_NULL);
    for (; !bmb::IndieWindow::isClosed(); indie.timePlayed += GetFrameTime()) {
        indie.keyboard.update(static_cast<int>(indie.state));
        if (IsKeyPressed(KEY_ESCAPE))
            break;
        if (IsKeyPressed(KEY_F11))
            indie.window.fullScreen();
        BeginDrawing();
        if (indie.state != gameMenu)
            ClearBackground(RAYWHITE);
        indie(indie.state);
        EndDrawing();
    }
    return 0;
}
