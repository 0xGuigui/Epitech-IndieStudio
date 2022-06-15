/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** SinglePlayerMenu
*/

#include "indie.hpp"
#include "components/button.hpp"

using namespace bmb;

void Indie::displayPlayMenu()
{
    static IndieTexture2D playMenuBackground = loader.textures["background_options"];
    static float middle_x = (this->screen.GetWidth() - playMenuBackground.getWidth()) / 2;
    static float middle_y = (this->screen.GetHeight() - playMenuBackground.getHeight()) / 2;
    static IndieTexture2D playButton = loader.textures["play"];
    static IndieTexture2D cancelButton = loader.textures["cancel"];
    static IndieSound buttonSound = loader.sounds["button"];
    static IndieSound closeSound = loader.sounds["close"];
    static IndieMusic MainMenuMusic = loader.musics["Moog-City-2"];
    static IndieButton playButtonObject({middle_x + 200, middle_y + 850, static_cast<float>(playButton.getWidth()), static_cast<float>(playButton.getHeight())},
                                        {middle_x + 200, middle_y + 850}, playButton, loader.textures["play_highlight"], [&]() -> void
                                        {
        buttonSound.Play();
        this->map.generateDestructible(75);
        this->map.generateBonuses();
        for (Player &player : this->players)
            player.reset();
        this->bombs.clear();
        this->state = inGame;
        MainMenuMusic.Stop(); });
    static IndieButton cancelButtonObject({middle_x + 1100, middle_y + 850, static_cast<float>(cancelButton.getWidth()), static_cast<float>(cancelButton.getHeight())},
                                          {middle_x + 1100, middle_y + 850}, cancelButton, loader.textures["cancel_highlight"], [&]() -> void
                                          {
        buttonSound.Play();
        this->state = mainMenu; });
    MainMenuMusic.setLoop(true);

    if (this->_musicPlay)
        MainMenuMusic.Play();

    MainMenuMusic.Update();
    playMenuBackground.Draw(middle_x, middle_y, WHITE);
    playButtonObject.update();
    cancelButtonObject.update();
}