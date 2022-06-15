/*
** EPITECH PROJECT, 2022
** button
** File description:
** button
*/

#pragma once

#include <functional>
#include "encapsulation/texture.hpp"
#include "encapsulation/text.hpp"

namespace bmb {
    class IndieButton {
    private:
        IndieRectangle _rect;
        IndieVector2 _position;
        IndieTexture2D _texture;
        IndieTexture2D _textureHover;
        std::function<void()> _onPress;
    public:
        IndieButton() = default;

        ~IndieButton() = default;

        IndieButton(IndieRectangle rect, IndieVector2 position, const IndieTexture2D &texture,
                    const IndieTexture2D &textureHover) {
            _rect = rect;
            _position = position;
            _texture = texture;
            _textureHover = textureHover;
        }

        template<typename T>
        IndieButton(IndieRectangle rect, IndieVector2 position, const IndieTexture2D &texture,
                    const IndieTexture2D &textureHover, T onPressFct) {
            _rect = rect;
            _position = position;
            _texture = texture;
            _textureHover = textureHover;
            _onPress = std::function<void()>(onPressFct);
        }

        template<typename T>
        void onPress(T fct) {
            _onPress = std::function<void()>(fct);
        }

        void setTexture(const IndieTexture2D &texture, const IndieTexture2D &textureHover) {
            _texture = texture;
            _textureHover = textureHover;
        }

        void update(bool drawOnly = false, KeyboardKey *controls = nullptr, direction index = LEFT) {
            if (CheckCollisionPointRec(GetMousePosition(), _rect)) {
                _textureHover.Draw(static_cast<int>(_position.getX()), static_cast<int>(_position.getY()), WHITE);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !drawOnly) {
                    _onPress();
                }
            } else {
                _texture.Draw(_position.getX(), _position.getY(), WHITE);
            }
            if (controls) {
                if (controls[index] == KEY_NULL) {
                    IndieText("No key mapped").Draw(_position + IndieVector2(20, 20), 35.0f, RED);
                    return;
                }
                char letter[2] = {static_cast<char>(controls[index]), '\0'};
                IndieText(letter).Draw(_position + IndieVector2(135, 20), 48.0f, WHITE);
            }
        }

        void hideButton() {
            _texture.Draw(static_cast<int>(_position.getX()), static_cast<int>(_position.getY()), WHITE);
        }
    };
}
