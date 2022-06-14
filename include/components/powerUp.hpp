/*
** EPITECH PROJECT, 2022
** bombup
** File description:
** bombup
*/

#pragma once

#include <functional>
#include "player.hpp"

enum PowerUpType {
    BOMBUP,
    WALLPASS,
    SPEEDUP,
    FIREUP,
    NONE
};

namespace bmb {
    class IndiePowerUp {
    private:
        int frame = 0;
        IndieModel _powerUp;
        IndieVector3 _position;
        PowerUpType _powerUpType = NONE;
        std::function<void(Player &)> _onPick;
    public:
        IndiePowerUp() = default;

        IndiePowerUp(std::function<void(Player &)> onPick, IndieVector3 &position, IndieModel &model,
                     PowerUpType type) {
            _onPick = onPick;
            _position = position;
            _powerUp = model;
            // _powerUp.getModel().transform; TODO mettre le bonus à plat
            _powerUpType = type;
        }

        ~IndiePowerUp() = default;

        IndieVector3 getPosition() {
            return _position;
        }

        void setPosition(IndieVector3 position) {
            _position = position;
        }

        void Delete();

        void update();

    protected:
    };
};