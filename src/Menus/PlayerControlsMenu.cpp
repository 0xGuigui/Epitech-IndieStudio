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
    static IndieTexture2D errorBind = loader.textures["empty_button_short_error"];
    static IndieSound buttonSound = loader.sounds["button"];
    static IndieMusic MainMenuMusic = loader.musics["Moog-City-2"];
    static int control = -1;
    static IndieButton *button = nullptr;

    if (this->_musicPlay)
        MainMenuMusic.Play();

    MainMenuMusic.Update();

    static IndieButton doneButton({middle_x + 1000, middle_y + 920, static_cast<float>(done.getWidth()), static_cast<float>(done.getHeight())},
                                  {middle_x + 1000, middle_y + 920}, done, loader.textures["done_short_highlight"], [&]() -> void
                                  {
        buttonSound.Play();
        this->state = controlsMenu; });

    static IndieButton resetKeysButton({middle_x + 300, middle_y + 920, static_cast<float>(resetKeys.getWidth()), static_cast<float>(resetKeys.getHeight())},
                                       {middle_x + 300, middle_y + 920}, resetKeys, loader.textures["reset_keys_highlight"], [&]() -> void
                                       {
        buttonSound.Play();
        this->players[this->playerSelected].unbindKeys(); });

    static IndieButton resetLeftButton({middle_x + 1400, middle_y + 250, static_cast<float>(reset.getWidth()), static_cast<float>(reset.getHeight())},
                                       {middle_x + 1400, middle_y + 250}, reset, loader.textures["reset_highlight"], [&]() -> void
                                       {
        buttonSound.Play();
        this->players[this->playerSelected].unbindKeyLeft(); });

    static IndieButton resetRightButton({middle_x + 1400, middle_y + 375, static_cast<float>(reset.getWidth()), static_cast<float>(reset.getHeight())},
                                        {middle_x + 1400, middle_y + 375}, reset, loader.textures["reset_highlight"], [&]() -> void
                                        {
        buttonSound.Play();
        this->players[this->playerSelected].unbindKeyRight(); });

    static IndieButton resetUpButton({middle_x + 1400, middle_y + 500, static_cast<float>(reset.getWidth()), static_cast<float>(reset.getHeight())},
                                     {middle_x + 1400, middle_y + 500}, reset, loader.textures["reset_highlight"], [&]() -> void
                                     {
        buttonSound.Play();
        this->players[this->playerSelected].unbindKeyUp(); });

    static IndieButton resetDownButton({middle_x + 1400, middle_y + 625, static_cast<float>(reset.getWidth()), static_cast<float>(reset.getHeight())},
                                       {middle_x + 1400, middle_y + 625}, reset, loader.textures["reset_highlight"], [&]() -> void
                                       {
        buttonSound.Play();
        this->players[this->playerSelected].unbindKeyDown(); });

    static IndieButton resetBombButton({middle_x + 1400, middle_y + 750, static_cast<float>(reset.getWidth()), static_cast<float>(reset.getHeight())},
                                       {middle_x + 1400, middle_y + 750}, reset, loader.textures["reset_highlight"], [&]() -> void
                                       {
        buttonSound.Play();
        this->players[this->playerSelected].unbindKeyBomb(); });

    static IndieButton bindLeftButton({middle_x + 1080, middle_y + 250, static_cast<float>(emptyButtonShort.getWidth()), static_cast<float>(emptyButtonShort.getHeight())},
                                      {middle_x + 1080, middle_y + 250}, emptyButtonShort, loader.textures["empty_button_short_highlight"], [&]() -> void
                                      {
        buttonSound.Play();
        bindLeftButton.setTexture(waitingInputButton, waitingInputButton);
        control = LEFT;
        button = &bindLeftButton;
                                      });


    static IndieButton bindRightButton({middle_x + 1080, middle_y + 375, static_cast<float>(emptyButtonShort.getWidth()), static_cast<float>(emptyButtonShort.getHeight())},
                                       {middle_x + 1080, middle_y + 375}, emptyButtonShort, loader.textures["empty_button_short_highlight"], [&]() -> void
                                       {
        buttonSound.Play();
        bindRightButton.setTexture(waitingInputButton, waitingInputButton);
        control = RIGHT;
        button = &bindRightButton; });

    static IndieButton bindUpButton({middle_x + 1080, middle_y + 500, static_cast<float>(emptyButtonShort.getWidth()), static_cast<float>(emptyButtonShort.getHeight())},
                                     {middle_x + 1080, middle_y + 500}, emptyButtonShort, loader.textures["empty_button_short_highlight"], [&]() -> void
                                     {
        buttonSound.Play();
        bindUpButton.setTexture(waitingInputButton, waitingInputButton);
        control = UP;
        button = &bindUpButton;});

    static IndieButton bindDownButton({middle_x + 1080, middle_y + 625, static_cast<float>(emptyButtonShort.getWidth()), static_cast<float>(emptyButtonShort.getHeight())},
                                      {middle_x + 1080, middle_y + 625}, emptyButtonShort, loader.textures["empty_button_short_highlight"], [&]() -> void
                                      {
        buttonSound.Play();
        bindDownButton.setTexture(waitingInputButton, waitingInputButton);
        control = DOWN;
        button = &bindDownButton;});

    static IndieButton bindBombButton({middle_x + 1080, middle_y + 750, static_cast<float>(emptyButtonShort.getWidth()), static_cast<float>(emptyButtonShort.getHeight())},
                                      {middle_x + 1080, middle_y + 750}, emptyButtonShort, loader.textures["empty_button_short_highlight"], [&]() -> void
                                      {
        buttonSound.Play();
        bindBombButton.setTexture(waitingInputButton, waitingInputButton);
        control = BOMB;
        button = &bindBombButton;});

    mainMenuBackground.Draw(middle_x, middle_y, WHITE);
    doneButton.update();
    resetKeysButton.update();
    resetLeftButton.update();
    resetRightButton.update();
    resetUpButton.update();
    resetDownButton.update();
    resetBombButton.update();
    bindLeftButton.update(false, players[playerSelected].getKeys(), LEFT);
    bindRightButton.update(false, players[playerSelected].getKeys(), RIGHT);
    bindUpButton.update(false, players[playerSelected].getKeys(), UP);
    bindDownButton.update(false, players[playerSelected].getKeys(), DOWN);
    bindBombButton.update(false, players[playerSelected].getKeys(), BOMB);
    if (button) {
        KeyboardKey key = KEY_NULL;
        button->update(true);
        EndDrawing();
        BeginDrawing();
        do {
            PollInputEvents();
            key = static_cast<KeyboardKey>(GetKeyPressed());
            for (int j = 0; j < players.size(); j++) {
                for (int i = 0; i < 5; i++) {
                    if (players[playerSelected].getKeys()[i] == key) {
                        players[playerSelected].getKeys()[i] = KEY_NULL;
                    }
                }
            }
            MainMenuMusic.Update();
        } while (key == KEY_NULL);
        this->players[this->playerSelected].setKey(static_cast<direction>(control), key);
        button->setTexture(emptyButtonShort, loader.textures["empty_button_short_highlight"]);
        button = nullptr;
        control = -1;
    }
}