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
    static IndieTexture2D optionsMenuBackground = loader.textures["background_options"];
    static float middle_x = (this->screen.GetWidth() - optionsMenuBackground.getWidth()) / 2;
    static float middle_y = (this->screen.GetHeight() - optionsMenuBackground.getHeight()) / 2;
    static IndieTexture2D doneButton = loader.textures["done"];
    static IndieTexture2D musicON = loader.textures["music_on"];
    static IndieTexture2D musicOFF = loader.textures["music_off"];
    static IndieTexture2D musicONHighlight = loader.textures["music_on_highlight"];
    static IndieTexture2D musicOFFHighlight = loader.textures["music_off_highlight"];
    static IndieTexture2D github = loader.textures["github"];
    static IndieTexture2D help = loader.textures["help"];
    static IndieTexture2D controls = loader.textures["controls"];
    static IndieTexture2D credits = loader.textures["credits"];
    static IndieTexture2D SuperSecretSettings = loader.textures["super_secret_settings"];
    static IndieSound buttonSound = loader.sounds["button"];
    static IndieSound closeSound = loader.sounds["close"];
    static IndieMusic MainMenuMusic = loader.musics["Moog-City-2"];

    static IndieButton doneButtonObject({middle_x + 575, middle_y + 850, static_cast<float>(doneButton.getWidth()), static_cast<float>(doneButton.getHeight())},
                                        {middle_x + 575, middle_y + 850}, doneButton, loader.textures["done_highlight"], [&]() -> void
                                        {
        buttonSound.Play();
        this->state = mainMenu; });

    static IndieButton musicOnButtonObject({middle_x + 300, middle_y + 150, static_cast<float>(musicON.getWidth()), static_cast<float>(musicON.getHeight())},
                                           {middle_x + 300, middle_y + 150}, musicON, loader.textures["music_on_highlight"], [&]() -> void
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

    static IndieButton controlsButtonObject({middle_x + 300, middle_y + 250, static_cast<float>(controls.getWidth()), static_cast<float>(controls.getHeight())},
                                            {middle_x + 300, middle_y + 250}, controls, loader.textures["controls_highlight"], [&]() -> void
                                            {
        buttonSound.Play();
        this->state = controlsMenu; });

    static IndieButton githubButton({middle_x + 300, middle_y + 350, static_cast<float>(github.getWidth()), static_cast<float>(github.getHeight())},
                                           {middle_x + 300, middle_y + 350}, github, loader.textures["github_highlight"], [&]() -> void
                                           {
        buttonSound.Play();
        OpenURL("https://bit.ly/3tAMBmy");
        // exit(0);
        });

    static IndieButton helpButtonObject({middle_x + 300, middle_y + 450, static_cast<float>(help.getWidth()), static_cast<float>(help.getHeight())},
                                        {middle_x + 300, middle_y + 450}, help, loader.textures["help_highlight"], [&]() -> void
                                        {
        buttonSound.Play();
        this->state = helpMenu; });

    static IndieButton creditsButtonObject({middle_x + 950, middle_y + 150, static_cast<float>(credits.getWidth()), static_cast<float>(credits.getHeight())},
                                           {middle_x + 950, middle_y + 150}, credits, loader.textures["credits_highlight"], [&]() -> void
                                           {
        buttonSound.Play();
        this->state = creditsMenu; });
        // this->state = creditsMenu; });

    MainMenuMusic.setLoop(true);

    if (this->_musicPlay)
        MainMenuMusic.Update();

    optionsMenuBackground.Draw(middle_x, middle_y, WHITE);
    musicOnButtonObject.update();
    doneButtonObject.update();
    controlsButtonObject.update();
    githubButton.update();
    helpButtonObject.update();
    creditsButtonObject.update();
    SuperSecretSettings.Draw(middle_x + 950, middle_y + 250, WHITE);
}
