/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** deserialization.hpp
*/

#pragma once

#include "indieStudio.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
#include "bmbSysCall.hpp"

namespace bmb {
    class Deserialization {
    protected
        std::string *input;
        std::string pathToSave = "./save/data/save.save";
        bmb::systemCall sysCall;
    public:
        Deserialization();
        ~Deserialization();
        void fileReader();
        void setSaveData();
        std::string getSaveData();
    };
}