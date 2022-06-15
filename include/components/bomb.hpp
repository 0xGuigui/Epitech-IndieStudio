/*
** EPITECH PROJECT, 2022
** bomb
** File description:
** bomb
*/

#pragma once

#include "indie.hpp"

namespace bmb {
    class IndieBomb {
    private:
        int frame = 0;
        int force = 1;
        IndieColor bombColor = WHITE;
        IndieVector3 _position;
        std::vector<IndieVector3> explosion = {};
        IndieModel _bombExplosion;
        IndieModel _bomb;
        IndieSound _sound;
        std::function<void()> _onDetonate;
        bool bombExplosion = false;

        bool isExplosionValid(const IndieVector3& position, int &direction);

    public:
        IndieBomb() = default;

        IndieBomb(int force, IndieVector3 position, const std::function<void()> &onDetonate);

        ~IndieBomb() = default;

        void detonate();

        void updateBombAnimation() {
            bombColor = (frame % 30) >= 15 ? IndieColor(255, 0, 0, 200) : IndieColor(255, 255, 255, 200);
            _bomb.Draw(_position, 1.0f, bombColor);
            if (frame > 180) {
                bombExplosion = true;
                _onDetonate();
                detonate();
                frame = 0;
            }
        }

        void updateExplosionAnimation();

        void update() {
            if (!_sound.isPlaying())
                _sound.Play();
            if (bombExplosion)
                updateExplosionAnimation();
            else
                updateBombAnimation();
            frame++;
        }

        IndieVector3 getPosition() {
            return _position;
        }

        void Delete();
    };
}