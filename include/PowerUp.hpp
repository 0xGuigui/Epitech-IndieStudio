/*
** EPITECH PROJECT, 2022
** bombup
** File description:
** bombup
*/

#pragma once

enum PowerUpType {
    BOMBUP,
    WALLPASS,
    SPEEDUP,
    FIREUP,
    NONE
};

#include <functional>

namespace bmb {
    class IndiePowerUp {
        private:
            int frame = 0;
            IndieModel _powerUp;
            IndieVector3 _position;
            PowerUpType _powerUpType;
            bool powerUpPickedUp = false;
            std::function<void(Player &)> _onPick;
        public:
            IndiePowerUp() = default;
            IndiePowerUp(std::function<void(Player &)> onPick, IndieVector3 &position, IndieModel &model, PowerUpType type) {
                _onPick = onPick;
                _position = position;
                _powerUp = model;
                _powerUpType = type;
            }
            ~IndiePowerUp() = default;
            IndieVector3 getPosition() {
                return _position;
            }
            void Load(std::function<void(Player &)> onPick, IndieVector3 &position, IndieModel &model, PowerUpType type) {
                _onPick = onPick;
                _position = position;
                _powerUp = model;
                _powerUpType = type;
            };
            IndieVector3 getPosition() {
                return _position;
            }
            void setPosition(IndieVector3 position) {
                _position = position;
            }
            void updatePowerUpAnimation() {
                _powerUp.Draw(_position, 1.0f, WHITE);
            };
            void updatePowerUpPickedUpAnimation() {
                // nothing
            }
            void update() {
                if (powerUpPickedUp)
                    updatePowerUpAnimation();
                else
                    updatePowerUpPickedUpAnimation();
                frame++;
            }
        protected:
    };
};