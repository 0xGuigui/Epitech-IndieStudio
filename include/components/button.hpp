/*
** EPITECH PROJECT, 2022
** button
** File description:
** button
*/

#pragma once

#include <functional>
#include "indieStudio.hpp"

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
            void hideButton()
            {
                texture.Draw(position.getX(), position.getY(), WHITE);
            }
            
        protected:
    };
}
