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

    bool pause = false;
    bool hasFilter = true;
    bool hasDelay = true;

	indie.map = bmb::MapController("assets/InGame/map.png", "assets/InGame/block.png", "assets/InGame/map_obstacles.png", "assets/InGame/brick.png", { -16.0f, 0.0f, -8.0f}, { { 0.0f, 17.0f, 5.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 });
    for (; !indie.window.isClosed(); indie.timePlayed += GetFrameTime()) {
        if (IsKeyPressed(KEY_ESCAPE))
            break;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        indie(indie.state);
        EndDrawing();
    }
    return 0;
}
