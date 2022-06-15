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
#include <string.h>

namespace bmb {
    typedef struct playerSave_s {
    public:
        IndieVector3 position;
        int fireUp;
        int speedUp;
        int bombUp;
        int wallPass;
        IndieColor color = WHITE;
    }playerSave_t;

    typedef struct bombSave_s {
    public:
        IndieVector3 position;
        int frame;
        IndieColor color = WHITE;
    }bombSave_t;

    typedef struct mapSave_s {
    public:
        std::vector<IndieVector3> map;
        std::vector<IndiePowerUp> bonus;
    }mapSave_t;

    typedef struct headerSave_s { //struct quantity
    public:
        int mapNumber;
        size_t sizeOfMap;
        size_t sizeOfBonus;
        int playerNumber;
        int bombNumber;
    }headerSave_t;
}