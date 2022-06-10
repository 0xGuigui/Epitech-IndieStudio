/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** save menu elements handling
*/

#pragma once
#include <vector>
#include <tuple>

#include "indieStudio.hpp"

namespace bmb {
    class SaveMenu {
    public:

    private:
        const char* _menuBackgroundPath = "assets/MainMenu/images/mainmenu.png";
        const char* _buttonPath = "assets/MainMenu/images/buttons/cancel.png";
        const char* _highlightedButtonPath = "assets/MainMenu/images/buttons/cancel_highlight.png";
        bool _isClicked = false;
        std::tuple<bool, std::vector<int>> _buttonGraphicalState = { false, {0, 0}};
        std::vector<bmb::IndieTexture2D> _menuButtons;
        std::vector<bmb::IndieTexture2D> _menuButtonsHighlight;
        bmb::IndieTexture2D _menuBackground;
        std::vector<std::vector<float>> _buttonsPosition;
        std::vector<Rectangle> _collisionBoxes;

    private:

    protected:

    public:
        SaveMenu() {
            this->init();
        };
        ~SaveMenu() {};
        void init();
        bool getButtonClick();
        void setButtonClick(bool state);
        void setButtonTexture2DArray(int quantity, std::vector<std::vector<float>> position);
        std::vector<bmb::IndieTexture2D> getButtonTexture2DArray();
        void setMenuBackground();
        bmb::IndieTexture2D getMenuBackground();
        void setCollisionBoxes(int quantity, std::vector<std::vector<int>> position);
        std::vector<Rectangle> getCollisionBoxes();
        void drawButtons(float x, float y);
        void updateButtonStatus(int i);
        void collision(int i);
    };
}
