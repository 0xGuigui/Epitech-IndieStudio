/*
** EPITECH PROJECT, 2022
** button
** File description:
** button
*/

#include "indieStudio.hpp"
#include <functional>

#pragma once

namespace bmb {
    class IndieButton {
        private:
            IndieRectangle rect;
            IndieVector2 position;
            IndieTexture texture;
            IndieTexture textureHover;
            std::function<void()> _onPress;
        public:
            IndieButton() = default;
            ~IndieButton() = default;
            IndieButton(IndieRectangle rect, IndieVector2 position, IndieTexture texture, IndieTexture textureHover) {
                this->rect = rect;
                this->position = position;
                this->texture = texture;
                this->textureHover = textureHover;
            }
            template<typename T>
            void onPress(T fct)
            {
                _onPress = std::function<void()>(fct);
            }
            void update()
            {
                if (CheckCollisionPointRec(GetMousePosition(), rect)) {
                    textureHover.Draw(position.getX(), position.getY(), WHITE);
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        _onPress();
                    }
                } else {
                    texture.Draw(position.getX(), position.getY(), WHITE);
                }
            }
        protected:
    };
}
