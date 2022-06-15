/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** endMenu
*/

#include "indie.hpp"
#include "components/button.hpp"


using namespace bmb;

void Indie::displayEndMenu() {
    static IndieTexture2D endMenuBackground = loader.textures["winpage"];
    static float middle_x = (this->screen.GetWidth() - endMenuBackground.getWidth()) / 2;
    static float middle_y = (this->screen.GetHeight() - endMenuBackground.getHeight()) / 2;
    static IndieTexture2D backToMenu = loader.textures["quit_to_title"];
    static IndieSound buttonSound = loader.sounds["button"];
    static IndieSound winSound = loader.sounds["fireworks"];

    if (!winSound.isPlaying())
        winSound.Play();

    static IndieButton backToMenuButton({middle_x + 1375, middle_y + 920, static_cast<float>(backToMenu.getWidth()), static_cast<float>(backToMenu.getHeight())},
                                        {middle_x + 1375, middle_y + 920}, backToMenu, loader.textures["quit_to_title_highlight"], [&]() -> void
                                        {
        buttonSound.Play();
        winSound.Stop();
        this->state = mainMenu; });

    int playerWon = 0;
    int i = 0;
    for (Player &player : this->players) {
        if (player.isAlive())
            playerWon = i + 1;
        i++;
    }
    IndieText winText("Player " + std::to_string(playerWon) + " won!");
    endMenuBackground.Draw(middle_x, middle_y, WHITE);
    backToMenuButton.update();
    winText.DrawEx(loader.fonts["Minecraftia"], (IndieVector2){middle_x + 1400, middle_y + 150}, 48.0f, 1.0f, WHITE);
}