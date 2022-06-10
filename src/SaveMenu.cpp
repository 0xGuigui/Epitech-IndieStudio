/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** SaveMenu
*/

#include "../../include/menu/SaveMenu.hpp"

bool bmb::SaveMenu::getButtonClick() {
    return this->_isClicked;
}

void bmb::SaveMenu::setButtonClick(bool state) {
    this->_isClicked = state;
}

void bmb::SaveMenu::setButtonTexture2DArray(int quantity, std::vector<std::vector<float>> position) {
    for (int i = 0; i < quantity; i++) {
        static IndieTexture2D saveMenuButton(this->_buttonPath);
        static IndieTexture2D saveMenuButtonHighLight(this->_highlightedButtonPath);
        this->_buttonsPosition.push_back(position[i]);
        this->_menuButtons.push_back(saveMenuButton);
        this->_menuButtonsHighlight.push_back(saveMenuButtonHighLight);
    }
}

std::vector<bmb::IndieTexture2D> bmb::SaveMenu::getButtonTexture2DArray() {
    return this->_menuButtons;
}

void bmb::SaveMenu::setMenuBackground() {
    static IndieTexture2D saveMenuBackground(this->_menuBackgroundPath);
    this->_menuBackground = saveMenuBackground;
}

bmb::IndieTexture2D bmb::SaveMenu::getMenuBackground() {
    return this->_menuBackground;
}

void bmb::SaveMenu::setCollisionBoxes(int quantity, std::vector<std::vector<int>> position) {
    for (int i = 0; i < quantity; i++) {
        static Rectangle collisionBox = {
                static_cast<float>(position[i][0]),
                static_cast<float>(position[i][1]),
                static_cast<float>(20),
                static_cast<float>(20)
        };
        this->_collisionBoxes.push_back(collisionBox);
    }
}

std::vector<Rectangle> bmb::SaveMenu::getCollisionBoxes() {
    return this->_collisionBoxes;
}

void bmb::SaveMenu::updateButtonStatus(int i) {
    std::get<0>(this->_buttonGraphicalState) = true;
    std::get<1>(this->_buttonGraphicalState)[0] = this->_buttonsPosition[i][0];
    std::get<1>(this->_buttonGraphicalState)[1] = this->_buttonsPosition[i][1];
}

void bmb::SaveMenu::collision(int i) {
    if (CheckCollisionPointRec(GetMousePosition(), this->_collisionBoxes[i])) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            //here call saveLoader on click
            this->updateButtonStatus(i);
        }
    }
}

void bmb::SaveMenu::drawButtons(float x, float y) {
    this->_menuBackground.Draw(static_cast<int>(x), static_cast<int>(y), WHITE);
    for (int i = 0; i < this->_menuButtons.size(); i++) {
        this->_menuButtons[i].Draw(this->_buttonsPosition[i][0],this->_buttonsPosition[i][1], WHITE);
        this->collision(i);
    }
}

void bmb::SaveMenu::init() {
    this->setButtonTexture2DArray(4, {{10, 10}, {20, 20}, {30, 30}, {40, 40}});
    this->setMenuBackground();
    this->setCollisionBoxes(4, {{10, 10}, {20, 20}, {30, 30}, {40, 40}});
}
