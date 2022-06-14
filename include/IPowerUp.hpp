/*
** EPITECH PROJECT, 2022
** powerup
** File description:
** powerup
*/

#include "indie.hpp"

#pragma once

enum PowerUpType {
    BOMBUP,
    WALLPASS,
    SPEEDUP,
    FIREUP
};

namespace bmb {
    class IIndiePowerUp {
        private:
        public:
            IIndiePowerUp() = default;
            IIndiePowerUp(std::function<void(PowerUpType)> _onPick, IndieVector3 position, IndieTexture2D &texturePowerUp);
            virtual ~IIndiePowerUp() = default;
            virtual void create(IndieTexture2D &texturePowerUp, IndieVector3 position) = 0;
            virtual void update() = 0;
            virtual void draw() = 0;
            virtual void updatePowerUpAnimation() = 0;
            virtual void updatePowerUp() = 0;
            virtual IndieModel getPowerUp() = 0;
            virtual IndieVector3 getPosition() = 0;
            virtual bool getpowerUpPickedUp() = 0;
            virtual std::function<void(PowerUpType)> getOnPick() = 0;
            virtual void setPosition(IndieVector3 position) = 0;
            virtual void setpowerUp(IndieModel powerUp) = 0;
            virtual void setPowerUpPickedUp(bool powerUpPickedUp) = 0;
            virtual void setOnPick(std::function<void(PowerUpType)> onPick) = 0;
        protected:
    };
}