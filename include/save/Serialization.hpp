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

namespace bmb {
    class Serialization {
    protected:
        struct saveData {

            std::vector<std::tuple<float, float>> charactersPosition;

        };
        std::list<IndieBomb>
        std::vector<>
    public:
        Serialization();
        ~Serialization();
        void fileWriter();
        void setSaveData();
        saveData getSaveData();
    };
}
