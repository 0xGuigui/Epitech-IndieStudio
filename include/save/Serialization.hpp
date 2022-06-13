/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** serialization.hpp
*/

#pragma once

#include "indieStudio.hpp"
#include <vector>
#include <string>
#include <tuple>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>
#include "bmbSysCall.hpp"

namespace bmb {
    class Serialization {
    protected:
        std::string *output;
        std::string pathToSave = "./save/data/save.save";
        bmb::systemCall sysCall;
    public:
        Serialization();
        ~Serialization();
        void fileWriter();
        void setSaveData();
        std::string getSaveData();
    };
}
