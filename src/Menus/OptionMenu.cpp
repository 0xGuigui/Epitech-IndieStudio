/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** OptionMenu
*/

#include "indie.hpp"
#include "components/button.hpp"

using namespace bmb;

void Indie::displayOptionsMenu()
{
    static IndieTexture2D mainMenuBackground = loader.textures["background_options"];
    static float middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
    static IndieTexture2D doneButton = loader.textures["done"];
    static IndieTexture2D musicON = loader.textures["music_on"];
    static IndieTexture2D musicOFF = loader.textures["music_off"];
    static IndieTexture2D musicONHighlight = loader.textures["music_on_highlight"];
    static IndieTexture2D musicOFFHighlight = loader.textures["music_off_highlight"];
    static IndieTexture2D controls = loader.textures["controls"];
    static IndieSound buttonSound = loader.sounds["button"];
    static IndieSound closeSound = loader.sounds["close"];
    static IndieMusic MainMenuMusic = loader.musics["Moog-City"];

    static IndieButton doneButtonObject((IndieRectangle){middle_x + 575, middle_y + 850, static_cast<float>(doneButton.getWidth()), static_cast<float>(doneButton.getHeight())},
                                        (IndieVector2){middle_x + 575, middle_y + 850}, doneButton, loader.textures["done_highlight"], [&]() -> void
                                        {
        buttonSound.Play();
        this->state = mainMenu; });

    static IndieButton musicOnButtonObject((IndieRectangle){middle_x + 200, middle_y + 150, static_cast<float>(musicON.getWidth()), static_cast<float>(musicON.getHeight())},
                                           (IndieVector2){middle_x + 200, middle_y + 150}, musicON, loader.textures["music_on_highlight"], [&]() -> void
                                           {
        buttonSound.Play();
        if (this->_musicPlay) {
            this->_musicPlay = false;
            this->_musicPlayed = MainMenuMusic.getTimePlayed();
            MainMenuMusic.Stop();
            musicOnButtonObject.setTexture(musicOFF, musicOFFHighlight);
        } else {
            this->_musicPlay = true;
            MainMenuMusic.Seek(this->_musicPlayed);
            MainMenuMusic.Play();
            musicOnButtonObject.setTexture(musicON, musicONHighlight);
        } });

    static IndieButton controlsButtonObject((IndieRectangle){middle_x + 200, middle_y + 250, static_cast<float>(controls.getWidth()), static_cast<float>(controls.getHeight())},
                                            (IndieVector2){middle_x + 200, middle_y + 250}, controls, loader.textures["controls_highlight"], [&]() -> void
                                            {
        buttonSound.Play();
        this->state = controlsMenu; });


    MainMenuMusic.setLoop(true);

    if (this->_musicPlay)
        MainMenuMusic.Update();

    mainMenuBackground.Draw(middle_x, middle_y, WHITE);
    musicOnButtonObject.update();
    doneButtonObject.update();
    controlsButtonObject.update();
}
