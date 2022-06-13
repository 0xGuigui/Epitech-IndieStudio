/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** ControlsMenu
*/

#include "indie.hpp"
#include "components/button.hpp"
#include "Player.hpp"


using namespace bmb;

void Indie::displayControlsMenu()
{
    static IndieTexture2D mainMenuBackground = loader.textures["background_options"];
    static float middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
    static IndieTexture2D doneButton = loader.textures["done"];
    static IndieTexture2D player1 = loader.textures["player1"];
    static IndieTexture2D player2 = loader.textures["player2"];
    static IndieTexture2D player3 = loader.textures["player3"];
    static IndieTexture2D player4 = loader.textures["player4"];
    static IndieSound buttonSound = loader.sounds["button"];
    static IndieMusic MainMenuMusic = loader.musics["Moog-City"];

    if (this->_musicPlay)
        MainMenuMusic.Play();

    MainMenuMusic.Update();

    static IndieButton doneButtonObject((IndieRectangle){middle_x + 575, middle_y + 850, static_cast<float>(doneButton.getWidth()), static_cast<float>(doneButton.getHeight())},
                                        (IndieVector2){middle_x + 575, middle_y + 850}, doneButton, loader.textures["done_highlight"], [&]() -> void
                                        {
        buttonSound.Play();
        this->state = optionsMenu; });

    static IndieButton player1Button((IndieRectangle){middle_x + 200, middle_y + 150, static_cast<float>(player1.getWidth()), static_cast<float>(player1.getHeight())},
                                    (IndieVector2){middle_x + 200, middle_y + 150}, player1, loader.textures["player1_highlight"], [&]() -> void
                                    {
        buttonSound.Play();
        this->state = playerOne; });

    static IndieButton player2Button((IndieRectangle){middle_x + 200, middle_y + 250, static_cast<float>(player2.getWidth()), static_cast<float>(player2.getHeight())},
                                    (IndieVector2){middle_x + 200, middle_y + 250}, player2, loader.textures["player2_highlight"], [&]() -> void
                                    {
        buttonSound.Play();
        this->state = playerTwo; });

    static IndieButton player3Button((IndieRectangle){middle_x + 200, middle_y + 350, static_cast<float>(player3.getWidth()), static_cast<float>(player3.getHeight())},
                                    (IndieVector2){middle_x + 200, middle_y + 350}, player3, loader.textures["player3_highlight"], [&]() -> void
                                    {
        buttonSound.Play();
        this->state = playerThree; });

    static IndieButton player4Button((IndieRectangle){middle_x + 200, middle_y + 450, static_cast<float>(player4.getWidth()), static_cast<float>(player4.getHeight())},
                                    (IndieVector2){middle_x + 200, middle_y + 450}, player4, loader.textures["player4_highlight"], [&]() -> void
                                    {
        buttonSound.Play();
        this->state = playerFour; });

    mainMenuBackground.Draw(middle_x, middle_y, WHITE);
    doneButtonObject.update();
    player1Button.update();
    player2Button.update();
    player3Button.update();
    player4Button.update();
}