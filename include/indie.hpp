/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
            bmb::Player(RED, {-15.0f, 1.5f, 5.0f}, DOWN), // top-right
            bmb::Player(YELLOW, {-3.0f, 1.5f, 5.0f}, LEFT), // bottom-right
*/

#pragma once

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

#include "encapsulation/window.hpp"
#include "encapsulation/audioDevice.hpp"
#include "encapsulation/mouse.hpp"
#include "encapsulation/screen.hpp"
#include "components/resourceLoader.hpp"
#include "MapController.hpp"
#include "KeyboardManager.hpp"
#include "Player.hpp"
#include "bomb.hpp"

enum indieState {
    splashScreen,
    mainMenu,
    singlePlayerMenu,
    multiplayerMenu,
    optionsMenu,
    inGame,
    any
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
        bmb::KeyboardManager keyboard;
        bmb::MapController map;
        std::vector<bmb::Player> players = {
            bmb::Player(VIOLET, {-15.0f, 1.5f, -7.0f}, RIGHT), // bottom-left
            bmb::Player(SKYBLUE, {-15.0f, 1.5f, 5.0f}, DOWN), // bottom-right
            bmb::Player(GREEN, {-3.0f, 1.5f, -7.0f}, UP), // top-left
            bmb::Player(GOLD, {-3.0f, 1.5f, 5.0f}, LEFT) // top-right
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

extern Indie indie;