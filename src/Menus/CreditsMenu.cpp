/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** CreditsMenu
*/

#include "indie.hpp"
#include "components/button.hpp"

using namespace bmb;

void Indie::displayCreditsMenu() {
    static IndieTexture2D creditsMenuBackground = loader.textures["background_credits"];
    static float middle_x = (this->screen.GetWidth() - creditsMenuBackground.getWidth()) / 2;
    static float middle_y = (this->screen.GetHeight() - creditsMenuBackground.getHeight()) / 2;
    static IndieTexture2D done = loader.textures["done"];
    static IndieSound buttonSound = loader.sounds["button"];
    static IndieMusic music = loader.musics["Moog-City-2"];

    static IndieButton doneButtonObject(
            {middle_x + 575, middle_y + 920, static_cast<float>(done.getWidth()), static_cast<float>(done.getHeight())},
            {middle_x + 575, middle_y + 920}, done, loader.textures["done_highlight"], [&]() -> void {
                buttonSound.Play();
                this->state = optionsMenu;
            });

    if (this->_musicPlay)
        music.Play();
    music.Update();

    creditsMenuBackground.Draw(middle_x, middle_y, WHITE);
    doneButtonObject.update();
}