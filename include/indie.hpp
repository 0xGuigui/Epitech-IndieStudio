/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
*/

#pragma once

#include "window.hpp"
#include "audioDevice.hpp"

class Indie {
    public:
        Indie();
        ~Indie();
        void displaySplashScreen();
        void soundSplashScreen();
        bmb::IndieWindow window;
        bmb::IndieAudioDevice audioDevice;
    protected:
    private:
};