/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** indie
*/



#pragma once

#include "encapsulation/window.hpp"
#include "encapsulation/audioDevice.hpp"
#include "encapsulation/mouse.hpp"
#include "encapsulation/screen.hpp"
#include "components/resourceLoader.hpp"
#include "components/mapController.hpp"
#include "components/keyboardManager.hpp"
#include "components/player.hpp"
#include "components/bomb.hpp"
#include "enums.hpp"

class Indie {
    private:
        void displaySplashScreen();
        void displayMainMenu();
        void displayPlayMenu();
        void displayOptionsMenu();
        void displayControlsMenu();
        void displayPlayerMenu();
        void displayHelpMenu();
        void displayHelpMenu2();
        void displayHelpMenu3();
        void displayGameMenu();
        void displayCreditsMenu();
        void displayEndMenu();
        void bomberMan();
    public:
        Indie();
        ~Indie() = default;
        float getTimeMusicPlayed() const;
        float setTimeMusicPlayed(int time);
        bmb::IndieWindow window;
        bmb::ResourceLoader loader;
        bmb::IndieScreen screen;
        bmb::KeyboardManager keyboard;
        bmb::IndieMouse mouse;
        bmb::MapController map;
        std::vector<bmb::Player> players = {
            bmb::Player(VIOLET, {-15.0f, 1.5f, -7.0f}, DOWN), // bottom-left
            bmb::Player(SKYBLUE, {-15.0f, 1.5f, 5.0f}, DOWN), // bottom-right
            bmb::Player(GREEN, {-3.0f, 1.5f, -7.0f}, DOWN), // top-left
            bmb::Player(GOLD, {-3.0f, 1.5f, 5.0f}, DOWN) // top-right
        };
        std::vector<bmb::IndieBomb> bombs;
        indieState state = splashScreen;
        void operator () (indieState state) {
            switch (state) {
                case splashScreen:
                    this->screenHeight = this->window.getHeight();
                    this->screenWidth = this->window.getWidth();
                    this->displaySplashScreen();
                    break;
                case mainMenu:
                    this->displayMainMenu();
                    break;
                case playMenu:
                    this->displayPlayMenu();
                    break;
                case optionsMenu:
                    this->displayOptionsMenu();
                    break;
                case controlsMenu:
                    this->displayControlsMenu();
                    break;
                case playerMenu:
                    this->displayPlayerMenu();
                    break;
                case helpMenu:
                    this->displayHelpMenu();
                    break;
                case helpMenu2:
                    this->displayHelpMenu2();
                    break;
                case helpMenu3:
                    this->displayHelpMenu3();
                    break;
                case gameMenu:
                    this->displayGameMenu();
                    break;
                case creditsMenu:
                    this->displayCreditsMenu();
                    break;
                case endMenu:
                    this->displayEndMenu();
                    break;
                case inGame:
                    this->bomberMan();
                    break;
                default:
                    break;
            }
        }
        float timePlayed = 0.0f;
        float _musicPlayed = 0.0f;
        int screenWidth = 1920;
        int screenHeight = 1080;
        bool _musicPlay = true;
        int playerSelected = 0;
};

extern Indie indie;