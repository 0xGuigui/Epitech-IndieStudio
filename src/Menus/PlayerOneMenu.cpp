/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** PlayerOneMenu
*/

#include "indieStudio.hpp"

using namespace bmb;

void Indie::displayPlayerOne()
{
    static IndieTexture2D mainMenuBackground = loader.textures["background_options_controls"];
    static float middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
    static IndieTexture2D done = loader.textures["done_short"];
    static IndieTexture2D resetKeys = loader.textures["reset_keys"];
    static IndieSound buttonSound = loader.sounds["button"];
    static IndieMusic MainMenuMusic = loader.musics["Moog-City"];

    if (this->_musicPlay)
        MainMenuMusic.Play();

    MainMenuMusic.Update();

    static IndieButton doneButton((IndieRectangle){middle_x + 1000, middle_y + 920, static_cast<float>(done.getWidth()), static_cast<float>(done.getHeight())},
                                  (IndieVector2){middle_x + 1000, middle_y + 920}, done, loader.textures["done_short_highlight"], [&]() -> void
                                  {
        buttonSound.Play();
        this->state = optionsMenu; });

    static IndieButton resetKeysButton((IndieRectangle){middle_x + 300, middle_y + 920, static_cast<float>(resetKeys.getWidth()), static_cast<float>(resetKeys.getHeight())},
                                       (IndieVector2){middle_x + 300, middle_y + 920}, resetKeys, loader.textures["reset_keys_highlight"], [&]() -> void
                                       { buttonSound.Play(); });

    mainMenuBackground.Draw(middle_x, middle_y, WHITE);
    doneButton.update();
    resetKeysButton.update();
}