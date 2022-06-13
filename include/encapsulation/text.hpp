/*
** EPITECH PROJECT, 2022
** text.hpp
** File description:
** encapsulation
*/

#pragma once

#include "raylib.h"
#include "encapsulation/font.hpp"
#include "encapsulation/vector.hpp"
#include "encapsulation/color.hpp"
#include <string>

namespace bmb {
    class IndieText {
    private:
        std::string _text;
    public:
        IndieText(const std::string text) : _text(text) {};

        IndieText(const IndieText &other) {
            this->_text = other._text;
        };

        void setText(const std::string &text) {
            this->_text = text;
        }

        const std::string &getText() const {
            return this->_text;
        }

        operator char *() {
            return (char *) this->_text.c_str();
        }

        static void Draw(const std::string &text, IndieVector2 position, float fontSize, IndieColor color) {
            DrawText(text.c_str(), position.getX(), position.getY(), fontSize, color);
        }

        void Draw(IndieVector2 position, float fontSize, IndieColor color) {
            DrawText(_text.c_str(), position.getX(), position.getY(), fontSize, color);
        }

        static void DrawEx(const std::string &text, IndieFont font, IndieVector2 position, float fontSize, float spacing, IndieColor color) {
            DrawTextEx(font, text.c_str(), position, fontSize, spacing, color);
        }

        void DrawEx(IndieFont font, IndieVector2 position, float fontSize, float spacing, IndieColor color) {
            DrawTextEx(font, _text.c_str(), position, fontSize, spacing, color);
        }
    };
}
