/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** OptionMenu
*/

#include "indieStudio.hpp"

using namespace bmb;

void Indie::displayOptionsMenu(float musicTime)
{
    static IndieTexture2D mainMenuBackground = loader.textures["background_options"];
    static IndieTexture2D doneButton = loader.textures["done"];
    static IndieTexture2D doneButtonHighlighted = loader.textures["done_highlight"];
    static IndieSound buttonSound = loader.sounds["button"];
    static IndieSound closeSound = loader.sounds["close"];
    static IndieMusic MainMenuMusic = loader.musics["Moog-City"];
    static float frameHeightPlayButton = (float)doneButton.getHeight() / 3;
    Vector2 mousePoint = GetMousePosition();
    static float musicPlayed = this->_musicPlayed;
    static bool isPlaying = false;
    MainMenuMusic.setLoop(true);
    this->_musicPlayed = MainMenuMusic.getTimePlayed();

    if (musicTime != 0 && !isPlaying)
    {
        MainMenuMusic.Seek(musicTime);
        this->setTimeMusicPlayed(musicTime);
        MainMenuMusic.Play();
        isPlaying = true;
    }
    else
        MainMenuMusic.Play();
    MainMenuMusic.Update();

    if (IsKeyPressed(KEY_ESCAPE))
    {
        closeSound.Play();
        while (closeSound.isPlaying());
        std::cout << "INFO: EXITING: QUIT GAME BY USER" << std::endl;
        exit(0);
    }

    static float middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
    static float mainMenuBackground_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float mainMenuBackground_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;

    mainMenuBackground.Draw(mainMenuBackground_x, mainMenuBackground_y, WHITE);
    doneButton.Draw(middle_x + 200, middle_y + 850, WHITE);
}