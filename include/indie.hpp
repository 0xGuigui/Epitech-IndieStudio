/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
*/

#pragma once

#include "window.hpp"
#include "audioDevice.hpp"

enum indieState {
    splashScreen,
    mainMenu,
    inGame
};

class Indie {
    public:
        Indie();
        ~Indie();
        void displaySplashScreen();
        void displayMainMenu();
        bmb::IndieWindow window;
        bmb::IndieAudioDevice audioDevice;
        indieState state = splashScreen;
        void operator [] (indieState state) {
            switch (state) {
                case splashScreen:
                    this->displaySplashScreen();
                    break;
                case mainMenu:
                    this->displayMainMenu();
                    break;
                case inGame:
                    break;
            };
        }
        float timePlayed = 0.0f;
    protected:
    private:

};