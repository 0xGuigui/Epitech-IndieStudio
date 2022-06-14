/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** serialization.hpp
*/

#pragma once

#include "../indieStudio.hpp"
#include <vector>
#include <string>
#include <tuple>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>

namespace bmb {
    class Serialization {
    protected:
        std::string *output;
        std::string pathToSave = "./save/data/save.save";
        bmb::systemCall sysCall;
        std::vector<bmb::playerSave_t> playerSaveArray;
        std::vector<bmb::bombSave_t> bombSaveArray;
        bmb::mapSave_t mapSaveArray;
        bmb::headerSave_t headerSave;

    public:
        Serialization();
        ~Serialization();
        void fileWriter();
        void setSaveData(std::vector<bmb::Bomb> bombArray, std::vector<bmb::Player> playerArray, std::vector<IndieVector3> destructibleObstacleArray);
    };
}
