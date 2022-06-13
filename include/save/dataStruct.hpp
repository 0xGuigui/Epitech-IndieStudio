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
    struct player {
        IndieVector3 position;
        bool fireUp;
        bool speedUp;
        bool bombUp;
        bool wallPass;
        int bombs;
        IndieColor color;
    };

    struct bomb {
        IndieVector3 position;
        int frame;
        IndieColor color;
    };

    struct map {
        std::vector<IndieVector3> map;
    };

    struct header { //struct quantity
        int playerNumber = 4;
        int mapNumber = 1;
        int bombNumber;
    };
}