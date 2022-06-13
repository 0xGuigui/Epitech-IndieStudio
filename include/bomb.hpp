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
        public:
            IndieBomb() = default;
            IndieBomb(IndieTexture2D &textureBomb, IndieVector3 position) {
                create(textureBomb, position);
            }
            template<typename F>
            IndieBomb(IndieTexture2D &textureBomb, IndieVector3 position, F onDetonate) {
                create(textureBomb, position, onDetonate);
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
            void create(IndieTexture2D &textureBomb, IndieVector3 position) {
                IndieMesh mesh;
                mesh.GenCube(1.0f, 1.0f, 1.0f);
                _position = position;
                _bomb.LoadFromMesh(mesh);
                _bombExplosion.LoadFromMesh(mesh);
                _bomb.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = textureBomb;
            }
            template<typename F>
            void create(IndieTexture2D &textureBomb, IndieVector3 position, F func) {
                create(textureBomb, position);
                _onDetonate = func;
            }
            IndieVector3 getPosition() {
                return _position;
            }
        protected:
    };
}