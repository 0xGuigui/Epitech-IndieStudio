/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** ControlsMenu
*/

#include "indieStudio.hpp"

using namespace bmb;

void Indie::displayControlsMenu()
{
    static IndieTexture2D mainMenuBackground = loader.textures["background_options"];
    static float middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
    static IndieTexture2D doneButton = loader.textures["done"];
    static IndieSound buttonSound = loader.sounds["button"];
    static IndieMusic MainMenuMusic = loader.musics["Moog-City"];

    static IndieButton doneButtonObject((IndieRectangle){middle_x + 575, middle_y + 850, static_cast<float>(doneButton.getWidth()), static_cast<float>(doneButton.getHeight())},
                                        (IndieVector2){middle_x + 575, middle_y + 850}, doneButton, loader.textures["done_highlight"], [&]() -> void
                                        {
        buttonSound.Play();
        this->state = optionsMenu; });

    mainMenuBackground.Draw(middle_x, middle_y, WHITE);
    doneButtonObject.update();
}