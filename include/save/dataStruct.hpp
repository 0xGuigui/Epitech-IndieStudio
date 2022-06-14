/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** dataStruct.hpp
*/

#pragma once

#include "../indieStudio.hpp"
#include <vector>
#include <string>
#include <tuple>
#include <list>
#include <fstream>

namespace bmb {
    struct playerSave_t {
        IndieVector3 position;
        int fireUp;
        int speedUp;
        int bombUp;
        int wallPass;
        int bombs;
        IndieColor color;
    };

    struct bombSave_t {
        IndieVector3 position;
        int frame;
        IndieColor color;
    };

    struct mapSave_t {
        std::vector<IndieVector3> map;
    };

    struct headerSave_t { //struct quantity
        int mapNumber;
        int playerNumber;
        int bombNumber;
    };
}