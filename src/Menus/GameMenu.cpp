/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** GameMenu
*/

#include "indie.hpp"
#include "components/button.hpp"

using namespace bmb;

void Indie::displayGameMenu()
{
    static IndieTexture2D mainMenuBackground = loader.textures["game_menu"];
    static float middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
    static IndieTexture2D backToGame = loader.textures["back_to_game"];
    static IndieTexture2D saveGame = loader.textures["save_game"];
    static IndieTexture2D quitGame = loader.textures["quit_to_title"];
    static IndieTexture2D saveAndQuit = loader.textures["save_and_quit"];
    static IndieSound buttonSound = loader.sounds["button"];

    static IndieButton backToGameButton((IndieRectangle){middle_x + 575, middle_y + 425, static_cast<float>(backToGame.getWidth()), static_cast<float>(backToGame.getHeight())},
                                        (IndieVector2){middle_x + 575, middle_y + 425}, backToGame, loader.textures["back_to_game_highlight"], [&]() -> void
                                        {
        buttonSound.Play();
        this->state = inGame; });

    static IndieButton saveGameButton((IndieRectangle){middle_x + 575, middle_y + 525, static_cast<float>(saveGame.getWidth()), static_cast<float>(saveGame.getHeight())},
                                      (IndieVector2){middle_x + 575, middle_y + 525}, saveGame, loader.textures["save_game_highlight"], [&]() -> void
                                      { buttonSound.Play(); });

    static IndieButton quitGameButton((IndieRectangle){middle_x + 999, middle_y + 525, static_cast<float>(quitGame.getWidth()), static_cast<float>(quitGame.getHeight())},
                                      (IndieVector2){middle_x + 999, middle_y + 525}, quitGame, loader.textures["quit_to_title_highlight"], [&]() -> void
                                      {
        buttonSound.Play();
        this->state = mainMenu;});

    static IndieButton saveAndQuitButton((IndieRectangle){middle_x + 575, middle_y + 625, static_cast<float>(saveAndQuit.getWidth()), static_cast<float>(saveAndQuit.getHeight())},
                                         (IndieVector2){middle_x + 575, middle_y + 625}, saveAndQuit, loader.textures["save_and_quit_highlight"], [&]() -> void
                                         {
        buttonSound.Play();
        this->state = mainMenu; });

    mainMenuBackground.Draw(middle_x, middle_y, WHITE);
    backToGameButton.update();
    saveGameButton.update();
    quitGameButton.update();
    saveAndQuitButton.update();
}