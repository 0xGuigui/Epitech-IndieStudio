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
            IndieRectangle rect;
            IndieVector2 position;
            IndieTexture2D texture;
            IndieTexture2D textureHover;
            std::function<void()> _onPress;
        public:
            IndieButton() = default;
            ~IndieButton() = default;
            IndieButton(IndieRectangle rect, IndieVector2 position, IndieTexture2D texture, IndieTexture2D textureHover) {
                this->rect = rect;
                this->position = position;
                this->texture = texture;
                this->textureHover = textureHover;
            }
            template<typename T>
            IndieButton(IndieRectangle rect, IndieVector2 position, IndieTexture2D texture, IndieTexture2D textureHover, T onPressFct) {
                this->rect = rect;
                this->position = position;
                this->texture = texture;
                this->textureHover = textureHover;
                _onPress = std::function<void()>(onPressFct);
            }
            template<typename T>
            void onPress(T fct)
            {
                _onPress = std::function<void()>(fct);
            }
            void setTexture(IndieTexture2D texture, IndieTexture2D textureHover) {
                this->texture = texture;
                this->textureHover = textureHover;
            }
            void update(bool drawOnly = false, KeyboardKey *controls = nullptr, direction index = LEFT) {
                if (CheckCollisionPointRec(GetMousePosition(), rect)) {
                    textureHover.Draw(position.getX(), position.getY(), WHITE);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !drawOnly) {
                        _onPress();
                    }
                } else {
                    texture.Draw(position.getX(), position.getY(), WHITE);
                }
                if (controls) {
                    char letter = static_cast<int>(controls[index]);
                    IndieText(std::string(&letter)).Draw(position, 48.0f, WHITE);
                }
            }
            void hideButton()
            {
                texture.Draw(position.getX(), position.getY(), WHITE);
            }
            
        protected:
    };
}
