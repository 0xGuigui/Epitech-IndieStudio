/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** HelpMenu
*/

#include "indie.hpp"
#include "components/button.hpp"

using namespace bmb;

void Indie::displayHelpMenu() {
    static IndieTexture2D mainMenuBackground = loader.textures["background_help1"];
    static float middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
    static IndieTexture2D done = loader.textures["done_short"];
    static IndieTexture2D next = loader.textures["next"];
    static IndieSound buttonSound = loader.sounds["button"];
    static IndieMusic music = loader.musics["Moog-City-2"];

    if (this->_musicPlay)
        music.Play();
    music.Update();

    static IndieButton doneButton({middle_x + 300, middle_y + 920, static_cast<float>(done.getWidth()), static_cast<float>(done.getHeight())},
                                  {middle_x + 300, middle_y + 920}, done, loader.textures["done_short_highlight"], [&]() -> void
                                  {
        buttonSound.Play();
        this->state = optionsMenu; });

    static IndieButton nextButton({middle_x + 1000, middle_y + 920, static_cast<float>(next.getWidth()), static_cast<float>(next.getHeight())},
                                  {middle_x + 1000, middle_y + 920}, next, loader.textures["next_highlight"], [&]() -> void
                                  {
        buttonSound.Play();
        this->state = helpMenu2; });

    mainMenuBackground.Draw(middle_x, middle_y, WHITE);
    doneButton.update();
    nextButton.update();
}

void Indie::displayHelpMenu2() {
    static IndieTexture2D mainMenuBackground = loader.textures["background_help2"];
    static float middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
    static IndieTexture2D done = loader.textures["done_short"];
    static IndieTexture2D previous = loader.textures["previous"];
    static IndieSound buttonSound = loader.sounds["button"];
    static IndieMusic music = loader.musics["Moog-City-2"];

    if (this->_musicPlay)
        music.Play();
    music.Update();

    static IndieButton doneButton({middle_x + 1000, middle_y + 920, static_cast<float>(done.getWidth()), static_cast<float>(done.getHeight())},
                                  {middle_x + 1000, middle_y + 920}, done, loader.textures["done_short_highlight"], [&]() -> void
                                  {
        buttonSound.Play();
        this->state = optionsMenu; });

    static IndieButton previousButton({middle_x + 300, middle_y + 920, static_cast<float>(previous.getWidth()), static_cast<float>(previous.getHeight())},
                                  {middle_x + 300, middle_y + 920}, previous, loader.textures["previous_highlight"], [&]() -> void
                                  {
        buttonSound.Play();
        this->state = helpMenu; });

    mainMenuBackground.Draw(middle_x, middle_y, WHITE);
    doneButton.update();
    previousButton.update();
}