/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** MainMenu
*/

#include "indie.hpp"
#include "components/button.hpp"

using namespace bmb;

void Indie::displayMainMenu() {
    static IndieTexture2D mainMenuBackground = loader.textures["mainmenu"];
    static IndieTexture2D titleImage = loader.textures["IndieCraft"];
    static float middle_x = (this->screen.GetWidth() - titleImage.getWidth()) / 2;
    static float middle_y = (this->screen.GetHeight() - titleImage.getHeight()) / 2;
    static IndieTexture2D singleplayer = loader.textures["singleplayer"];
    static IndieSound buttonSound = loader.sounds["button"];
    static IndieSound closeSound = loader.sounds["close"];
    static IndieMusic MainMenuMusic = loader.musics["Moog-City-2"];
    static IndieTexture2D options = loader.textures["options"];
    static IndieTexture2D quitgame = loader.textures["quitgame"];
    static IndieTexture2D accessibility = loader.textures["accessibility"];
    static IndieTexture2D SplashText = loader.textures["splashtext"];

    static IndieButton singlePlayerButton({middle_x, middle_y + 100, static_cast<float>(singleplayer.getWidth()),
                                           static_cast<float>(singleplayer.getHeight())},
                                          {middle_x, middle_y + 100}, singleplayer,
                                          loader.textures["singleplayer_highlight"], [&]() -> void {
                buttonSound.Play();
                this->state = playMenu;
            });

    static IndieButton optionsButton(
            {middle_x, middle_y + 200, static_cast<float>(options.getWidth()), static_cast<float>(options.getHeight())},
            {middle_x, middle_y + 200}, options, loader.textures["options_highlight"], [&]() -> void {
                buttonSound.Play();
                this->state = optionsMenu;
            });

    static IndieButton quitButton({middle_x + 408, middle_y + 200, static_cast<float>(quitgame.getWidth()),
                                   static_cast<float>(quitgame.getHeight())},
                                  {middle_x + 408, middle_y + 200}, quitgame, loader.textures["quitgame_highlight"],
                                  [&]() -> void {
                                      buttonSound.Play();
                                      while (buttonSound.isPlaying());
                                      closeSound.Play();
                                      while (closeSound.isPlaying());
                                      MainMenuMusic.Stop();
                                      exit(0);
                                  });

    static IndieButton accessibilityButton(
            {middle_x + 825, middle_y + 200, static_cast<float>(accessibility.getWidth()),
             static_cast<float>(accessibility.getHeight())},
            {middle_x + 825, middle_y + 200}, accessibility, loader.textures["accessibility_highlight"], [&]() -> void {
                buttonSound.Play();
                OpenURL("https://bit.ly/3PSsHwZ");
                std::cout << "EXIT: EXITED FROM ACCESSIBILITY" << std::endl;
                exit(0);
            });

    if (this->_musicPlay)
        MainMenuMusic.Play();

    MainMenuMusic.Update();

    keyboard.bind(
            KEY_ESCAPE, [&]() -> void {
                closeSound.Play();
                while (closeSound.isPlaying());
                exit(0);
            },
            []() -> void {});

    mainMenuBackground.Draw(0, 0, WHITE);
    titleImage.Draw(middle_x, 75, WHITE);
    SplashText.Draw(middle_x + 645, 25, WHITE);
    DrawText("IndieCraft is an Epitech project, based on the bomberman", this->screen.GetWidth() - 600,
             this->screen.GetHeight() - 30, 20, WHITE);

    static float timer = 0;
    timer += 0.05f;
    static float defaultSizeSplashTextWidth = SplashText.getWidth();
    static float defaultSizeSplashTextHeight = SplashText.getHeight();
    if (timer > 0.0f && timer < 1.0f) {
        SplashText.setHeight(SplashText.getHeight() + 1);
        SplashText.setWidth(SplashText.getWidth() + 1);
    }
    if (timer > 1.0f && timer < 2.0f) {
        SplashText.setHeight(SplashText.getHeight() - 1);
        SplashText.setWidth(SplashText.getWidth() - 1);
    }
    if (timer > 2.0f) {
        SplashText.setHeight(defaultSizeSplashTextHeight);
        SplashText.setWidth(defaultSizeSplashTextWidth);
        timer = 0;
    }
    singlePlayerButton.update();
    optionsButton.update();
    quitButton.update();
    accessibilityButton.update();
}