/*
** EPITECH PROJECT, 2022
** bombup
** File description:
** bombup
*/

#include "powerup.hpp"

#pragma once

namespace bmb {
    class IndieBombUp : public IIndiePowerUp {
        private:
            IndieModel _powerUp;
            IndieVector3 _position;
            bool powerUpPickedUp = false;
            std::function<void(PowerUpType)> _onPick;
        public:
            IndieBombUp() = default;
            IndieBombUp(std::function<void(PowerUpType)> _onPick, IndieVector3 position);
            ~IndieBombUp() = default;
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