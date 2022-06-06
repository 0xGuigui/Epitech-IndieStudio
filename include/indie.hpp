/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
*/

#pragma once

#include "encapsulation/window.hpp"
#include "encapsulation/audioDevice.hpp"

enum indieState {
    splashScreen,
    mainMenu,
    singlePlayerMenu,
    multiplayerMenu,
    optionsMenu,
    inGame
};

class Indie {
    public:
        Indie();
        ~Indie();
        void displaySplashScreen();
        void displayMainMenu(float musicTime);
        void displaySinglePlayerMenu(float musicTime);
        void displayMultiplayerMenu();
        void displayOptionsMenu();
        float getTimeMusicPlayed();
        float setTimeMusicPlayed(int time);
        bmb::IndieWindow window;
        bmb::IndieAudioDevice audioDevice;
        bmb::IndieScreen screen;
        indieState state = splashScreen;
        void operator () (indieState state) {
            switch (state) {
                case splashScreen:
                    this->displaySplashScreen();
                    break;
                case mainMenu:
                    this->displayMainMenu(this->getTimeMusicPlayed());
                    break;
                case singlePlayerMenu:
                    this->displaySinglePlayerMenu(this->getTimeMusicPlayed());
                    break;
                case inGame:
                    break;
            };
        }
        float timePlayed = 0.0f;
        float _musicPlayed = 0.0f;
    protected:
    private:

};