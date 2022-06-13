/*
** EPITECH PROJECT, 2022
** font.hpp
** File description:
** Handle fonts for indie
*/

#pragma once

#include "raylib.h"

namespace bmb {
    class IndieFont {
    private:
        Font _font;

    public:
        IndieFont(const std::string &fileName) {
            _font = LoadFont(fileName.c_str());
        }

        ~IndieFont() = default;

        IndieFont(const Font &font) : _font(font) {};

        operator Font() const {
            return _font;
        }
    };
}
