/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** serialization.hpp
*/

#pragma once

#include <vector>
#include <string>
#include <tuple>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>
#include "dataStruct.hpp"
#include "../Player.hpp"
#include "../bomb.hpp"

namespace bmb {
    class Serialization {
    protected:
        std::string *output;
        std::string pathToSave = "./save/data/save.save";
        std::vector<bmb::playerSave> playerSaveArray;
        std::vector<bmb::bombSave> bombSaveArray;
        bmb::mapSave mapSave{};
        bmb::headerSave headerSave{};
        bmb::playerSave playerSave{};
        bmb::bombSave bombSave{};

    public:
        Serialization();
        ~Serialization();
        void fileWriter();
        void setSaveData(std::vector<bmb::IndieBomb> bombArray, std::vector<bmb::Player> playerArray, std::vector<IndieVector3> destructibleObstacleArray, std::vector<IndieVector3> bonusArray);
    };
}
