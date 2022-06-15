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
        std::function<void()> _onDetonate;
        bool bombExplosion = false;

        bool isExplosionValid(const IndieVector3& position, int &direction);

    public:
        IndieBomb() = default;

        IndieBomb(int force, const IndieVector3 &position) {
            create(position);
            this->force = force;
        }

        template<typename F>
        IndieBomb(int force, IndieVector3 position, F onDetonate) {
            create(position, onDetonate);
            this->force = force;
        }

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
            if (bombExplosion)
                updateExplosionAnimation();
            else
                updateBombAnimation();
            frame++;
        }

        void create(const IndieVector3 &position) {
            _bomb = IndieModel("assets/models/blocks/tnt.glb");
            IndieMesh mesh;
            mesh.GenCube(1.0f, 1.0f, 1.0f);
            _bombExplosion.LoadFromMesh(mesh);
            _position = position;
        }

        template<typename F>
        void create(const IndieVector3 &position, F func) {
            create(position);
            _onDetonate = func;
        }

        IndieVector3 getPosition() {
            return _position;
        }

        int getFrame() {
            return this->frame;
        }

        IndieColor getColor() {
            return this->bombColor;
        }

        void Delete();
    };
}