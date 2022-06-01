/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
*/

#pragma once

#include "window.hpp"

class Indie {
    public:
        Indie();
        ~Indie();
        void displaySplashScreen();
    protected:
    private:
        bmb::IndieWindow _window;
        Music _music;
};