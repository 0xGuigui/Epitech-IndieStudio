/*
** EPITECH PROJECT, 2022
** audioDevice.hpp
** File description:
** include
*/

#pragma once

#include "raylib.h"

namespace bmb {
    class IndieAudioDevice {
    public:
        IndieAudioDevice() {
            InitAudioDevice();
        }

        ~IndieAudioDevice() {
            CloseAudioDevice();
        }

        static bool isReady() {
            return IsAudioDeviceReady();
        }

        static void setVolume(float volume) {
            SetMasterVolume(volume);
        }
    };
}
