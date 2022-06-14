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
#include "dataStruct.hpp"
#include "Player.hpp"
#include "bomb.hpp"

namespace bmb {
    class Deserialization {
    protected:
        char *input;
        std::string pathToSave = "./save/data/save.save";
        std::vector<bmb::playerSave> playerSaveArray;
        std::vector<bmb::bombSave> bombSaveArray;
        bmb::mapSave mapSave;
        bmb::headerSave headerSave;

    public:
        Deserialization();
        ~Deserialization();
        void fileReader();
        void setSaveData();
        std::vector<bmb::playerSave> getPlayerSaveArray();
        std::vector<bmb::bombSave> getBombSaveArray();
        bmb::mapSave getMapSave();
    };
}