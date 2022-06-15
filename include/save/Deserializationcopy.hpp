/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** deserialization.hpp
*/

#pragma once

#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>
#include "dataStructcopy.hpp"
#include "../Player.hpp"
#include "../bomb.hpp"

namespace bmb {
    class Deserialization {
    protected:
        char *input;
        std::string pathToSave = "./save/data/save.save";
        std::vector<bmb::playerSave_t> playerSaveArray;
        std::vector<bmb::bombSave_t> bombSaveArray;
        bmb::mapSave_t mapSave;
        bmb::headerSave_t headerSave;

    public:
        Deserialization();
        ~Deserialization();
        void fileReader();
        void setSaveData();
        std::vector<bmb::playerSave_t> getPlayerSaveArray();
        std::vector<bmb::bombSave_t> getBombSaveArray();
        bmb::mapSave_t getMapSave();
    };
}