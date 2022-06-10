/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
*/

#pragma once

#include "encapsulation/window.hpp"
#include "encapsulation/audioDevice.hpp"
#include "encapsulation/mouse.hpp"
#include "components/resourceLoader.hpp"
#include "MapController.hpp"
#include "KeyboardManager.hpp"

enum indieState {
    splashScreen,
    mainMenu,
    playMenu,
    optionsMenu,
    controlsMenu,
    inGame
};

class Indie {
    private:
        void displaySplashScreen();
        void displayMainMenu();
        void displayPlayMenu();
        void displayOptionsMenu();
        void displayControlsMenu();
        void bomberMan();
    public:
        Indie();
        ~Indie() = default;
        float getTimeMusicPlayed() const;
        float setTimeMusicPlayed(int time);
        bmb::IndieWindow window;
        bmb::ResourceLoader loader;
        bmb::IndieScreen screen;
        bmb::IndieMouse mouse;
        bmb::IndieText text;
        bmb::MapController map;
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
                case inGame:
                    this->bomberMan();
                    break;
            };
        }
        float timePlayed = 0.0f;
        float _musicPlayed = 0.0f;
        int screenWidth = 1920;
        int screenHeight = 1032;
        bool _musicPlay = true;
    protected:
};

namespace bmb {
    extern KeyboardManager keyboard;
}