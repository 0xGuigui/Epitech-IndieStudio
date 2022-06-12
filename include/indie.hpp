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

enum indieState {
    splashScreen,
    mainMenu,
    singlePlayerMenu,
    multiplayerMenu,
    optionsMenu,
    inGame
};

class Indie {
    private:
        void displaySplashScreen();
        void displayMainMenu(float musicTime);
        void displaySinglePlayerMenu(float musicTime);
        void displayMultiPlayerMenu(float musicTime);
        void displayOptionsMenu();
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
        bmb::MapController map;
        indieState state = inGame;
        void operator () (indieState state) {
            switch (state) {
                case splashScreen:
                    this->screenHeight = this->window.getHeight();
                    this->screenWidth = this->window.getWidth();
                    this->displaySplashScreen();
                    break;
                case mainMenu:
                    this->displayMainMenu(this->getTimeMusicPlayed());
                    break;
                case singlePlayerMenu:
                    this->displaySinglePlayerMenu(this->getTimeMusicPlayed());
                    break;
                case multiplayerMenu:
                    this->displayMultiPlayerMenu(this->getTimeMusicPlayed());
                    break;
                case inGame:
                    this->bomberMan();
                    break;
            };
        }
        float timePlayed = 0.0f;
        float _musicPlayed = 0.0f;
        int screenWidth = 1920;
        int screenHeight = 1080;
    protected:
};