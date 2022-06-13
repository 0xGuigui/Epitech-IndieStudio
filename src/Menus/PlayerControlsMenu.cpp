/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** PlayerOneMenu
*/

#include "indie.hpp"
#include "components/button.hpp"
#include "encapsulation/text.hpp"
#include "encapsulation/font.hpp"
#include "Player.hpp"

using namespace bmb;

void Indie::displayPlayerMenu()
{
    static IndieTexture2D mainMenuBackground = loader.textures["background_options_controls"];
    static float middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
    static IndieTexture2D done = loader.textures["done_short"];
    static IndieTexture2D resetKeys = loader.textures["reset_keys"];
    static IndieTexture2D reset = loader.textures["reset"];
    static IndieTexture2D emptyButtonShort = loader.textures["empty_button_short"];
    static IndieTexture2D waitingInputButton = loader.textures["mapping_button_empty"];
    static IndieSound buttonSound = loader.sounds["button"];
    static IndieMusic MainMenuMusic = loader.musics["Moog-City-2"];
    static IndieText fowardText("Foward");

    if (this->_musicPlay)
        MainMenuMusic.Play();

    MainMenuMusic.Update();

    static IndieButton doneButton((IndieRectangle){middle_x + 1000, middle_y + 920, static_cast<float>(done.getWidth()), static_cast<float>(done.getHeight())},
                                  (IndieVector2){middle_x + 1000, middle_y + 920}, done, loader.textures["done_short_highlight"], [&]() -> void
                                  {
        buttonSound.Play();
        this->state = controlsMenu; });

    static IndieButton resetKeysButton((IndieRectangle){middle_x + 300, middle_y + 920, static_cast<float>(resetKeys.getWidth()), static_cast<float>(resetKeys.getHeight())},
                                       (IndieVector2){middle_x + 300, middle_y + 920}, resetKeys, loader.textures["reset_keys_highlight"], [&]() -> void
                                       {
        buttonSound.Play();
        this->players[this->playerSelected].unbindKeys(); });

    static IndieButton resetLeftButton((IndieRectangle){middle_x + 1400, middle_y + 250, static_cast<float>(reset.getWidth()), static_cast<float>(reset.getHeight())},
                                       (IndieVector2){middle_x + 1400, middle_y + 250}, reset, loader.textures["reset_highlight"], [&]() -> void
                                       {
        buttonSound.Play();
        this->players[this->playerSelected].unbindKeyLeft(); });

    static IndieButton resetRightButton((IndieRectangle){middle_x + 1400, middle_y + 375, static_cast<float>(reset.getWidth()), static_cast<float>(reset.getHeight())},
                                        (IndieVector2){middle_x + 1400, middle_y + 375}, reset, loader.textures["reset_highlight"], [&]() -> void
                                        {
        buttonSound.Play();
        this->players[this->playerSelected].unbindKeyRight(); });

    static IndieButton resetUpButton((IndieRectangle){middle_x + 1400, middle_y + 500, static_cast<float>(reset.getWidth()), static_cast<float>(reset.getHeight())},
                                     (IndieVector2){middle_x + 1400, middle_y + 500}, reset, loader.textures["reset_highlight"], [&]() -> void
                                     {
        buttonSound.Play();
        this->players[this->playerSelected].unbindKeyUp(); });

    static IndieButton resetDownButton((IndieRectangle){middle_x + 1400, middle_y + 625, static_cast<float>(reset.getWidth()), static_cast<float>(reset.getHeight())},
                                       (IndieVector2){middle_x + 1400, middle_y + 625}, reset, loader.textures["reset_highlight"], [&]() -> void
                                       {
        buttonSound.Play();
        this->players[this->playerSelected].unbindKeyDown(); });

    static IndieButton resetBombButton((IndieRectangle){middle_x + 1400, middle_y + 750, static_cast<float>(reset.getWidth()), static_cast<float>(reset.getHeight())},
                                       (IndieVector2){middle_x + 1400, middle_y + 750}, reset, loader.textures["reset_highlight"], [&]() -> void
                                       {
        buttonSound.Play();
        this->players[this->playerSelected].unbindKeyBomb(); });

    static IndieButton bindLeftButton((IndieRectangle){middle_x + 1100, middle_y + 250, static_cast<float>(emptyButtonShort.getWidth()), static_cast<float>(emptyButtonShort.getHeight())},
                                      (IndieVector2){middle_x + 1100, middle_y + 250}, emptyButtonShort, loader.textures["empty_button_short_highlight"], [&]() -> void
                                      {
        buttonSound.Play();
        bindLeftButton.setTexture(waitingInputButton, waitingInputButton);
        KeyboardKey key = KEY_NULL;
        do {
            key = static_cast<KeyboardKey>(GetKeyPressed());
        }
        while (key == KEY_NULL);
        this->players[this->playerSelected].setKeyLeft(key);
        bindLeftButton.setTexture(emptyButtonShort, loader.textures["empty_button_short_highlight"]); });

    static IndieButton bindRightButton((IndieRectangle){middle_x + 1100, middle_y + 375, static_cast<float>(emptyButtonShort.getWidth()), static_cast<float>(emptyButtonShort.getHeight())},
                                       (IndieVector2){middle_x + 1100, middle_y + 375}, emptyButtonShort, loader.textures["empty_button_short_highlight"], [&]() -> void
                                       {
        buttonSound.Play();
        bindRightButton.setTexture(waitingInputButton, waitingInputButton); });

    static IndieButton bindUptButton((IndieRectangle){middle_x + 1100, middle_y + 500, static_cast<float>(emptyButtonShort.getWidth()), static_cast<float>(emptyButtonShort.getHeight())},
                                     (IndieVector2){middle_x + 1100, middle_y + 500}, emptyButtonShort, loader.textures["empty_button_short_highlight"], [&]() -> void
                                     {
        buttonSound.Play();
        bindUptButton.setTexture(waitingInputButton, waitingInputButton); });

    static IndieButton bindDownButton((IndieRectangle){middle_x + 1100, middle_y + 625, static_cast<float>(emptyButtonShort.getWidth()), static_cast<float>(emptyButtonShort.getHeight())},
                                      (IndieVector2){middle_x + 1100, middle_y + 625}, emptyButtonShort, loader.textures["empty_button_short_highlight"], [&]() -> void
                                      {
        buttonSound.Play();
        bindDownButton.setTexture(waitingInputButton, waitingInputButton); });

    static IndieButton bindBombButton((IndieRectangle){middle_x + 1100, middle_y + 750, static_cast<float>(emptyButtonShort.getWidth()), static_cast<float>(emptyButtonShort.getHeight())},
                                      (IndieVector2){middle_x + 1100, middle_y + 750}, emptyButtonShort, loader.textures["empty_button_short_highlight"], [&]() -> void
                                      {
        buttonSound.Play();
        bindBombButton.setTexture(waitingInputButton, waitingInputButton); });

    mainMenuBackground.Draw(middle_x, middle_y, WHITE);
    doneButton.update();
    resetKeysButton.update();
    resetLeftButton.update();
    resetRightButton.update();
    resetUpButton.update();
    resetDownButton.update();
    resetBombButton.update();
    fowardText.DrawEx(loader.fonts["Minecraftia"], (IndieVector2){middle_x + 1000, middle_y + 250}, 1.0f, 1.0f, WHITE);
    bindLeftButton.update();
    bindRightButton.update();
    bindUptButton.update();
    bindDownButton.update();
    bindBombButton.update();
}