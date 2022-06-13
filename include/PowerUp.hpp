/*
** EPITECH PROJECT, 2022
** bombup
** File description:
** bombup
*/

#include "powerup.hpp"

#pragma once

namespace bmb {
    class IndiePowerUp : public IIndiePowerUp {
        private:
            IndieModel _powerUp;
            IndieVector3 _position;
            PowerUpType _powerUpType;
            bool powerUpPickedUp = false;
            std::function<void(PowerUpType)> _onPick;
        public:
            IndiePowerUp() = default;
            IndiePowerUp(std::function<void(PowerUpType)> _onPick, IndieVector3 position, IndieTexture2D &texturePowerUp);
            ~IndiePowerUp() = default;
            IndieModel getPowerUp() {
                return _powerUp;
            }
            IndieVector3 getPosition() {
                return _position;
            }
            bool powerUpPickedUp() {
                return powerUpPickedUp;
            }
            IndieModel setpowerUp(IndieModel powerUp) {
                _powerUp = powerUp;
            }
            IndieVector3 setPosition(IndieVector3 position) {
                _position = position;
            }
            void setPowerUpPickedUp(bool powerUpPickedUp) {
                this->powerUpPickedUp = powerUpPickedUp;
            }
        protected:
    }
}