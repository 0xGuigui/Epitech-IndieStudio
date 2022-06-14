/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** dataStruct.hpp
*/

#pragma once

#include "indie.hpp"
#include <vector>
#include <string>
#include <tuple>
#include <fstream>

namespace bmb {
    class playerSave {
    public:
        IndieVector3 position;
        int fireUp;
        int speedUp;
        int bombUp;
        int wallPass;
        IndieColor color = WHITE;
        playerSave() {};
        ~playerSave() {};
    };

    class bombSave {
    public:
        IndieVector3 position;
        int frame;
        IndieColor color = WHITE;
        bombSave() {};
        ~bombSave() {};
    };

    class mapSave {
    public:
        std::vector<IndieVector3> map;
        std::vector<IndieVector3> bonus;
        mapSave() {};
        ~mapSave() {};
    };

    class headerSave { //struct quantity
    public:
        int mapNumber;
        int playerNumber;
        int bombNumber;
        headerSave() {};
        ~headerSave() {};
    };
}