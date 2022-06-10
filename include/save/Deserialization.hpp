/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** deserialization.hpp
*/

#pragma once

#include "indieStudio.hpp"

namespace bmb {
    class Deserialization {
    protected
        struct saveData;
    public:
        Deserialization();
        ~Deserialization();
        void fileReader();
        void setSaveData();
        saveData getSaveData();
    };
}