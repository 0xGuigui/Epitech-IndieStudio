/*
** EPITECH PROJECT, 2022
** bomb
** File description:
** bomb
*/

#pragma once

#include "indie.hpp"

extern Indie indie;

namespace bmb {
    class IndieBomb {
        private:
            int frame = 0;
            IndieColor bombColor = WHITE;
            IndieVector3 _position;
            std::vector<IndieVector3> explosion = {};
            IndieModel _bombExplosion;
            IndieModel _bomb;
            std::function<void()> _onDetonate;
            bool bombExplosion = false;
        public:
            IndieBomb() = default;
            IndieBomb(IndieTexture2D textureBomb, IndieVector3 position) {
                create(textureBomb, position);
            }
            template<typename F>
            IndieBomb(IndieTexture2D textureBomb, IndieVector3 position, F onDetonate) {
                create(textureBomb, position, onDetonate);
            }
            ~IndieBomb() = default;
            void updateBombAnimation() {
                bombColor = (frame % 30) >= 15 ? RED : WHITE;
                DrawCube(_position, 1.0f, 1.0f, 1.0f, bombColor);
                if (frame > 180) {
                    bombExplosion = true;
                    _onDetonate();
                    frame = 0;
                }
            }
            void updateExplosionAnimation() {
                _bombExplosion.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = indie.loader.textures["explosion_" + frame];
                for (IndieVector3 pos : explosion) {
                    _bombExplosion.Draw(pos, 1.0f, WHITE);
                }
            }
            void update() {
                if (bombExplosion)
                    updateExplosionAnimation();
                else
                    updateBombAnimation();
                frame++;
            }
            void create(IndieTexture2D textureBomb, IndieVector3 position) {
                IndieMesh mesh;
                mesh.GenCube(1.0f, 1.0f, 1.0f);
                _bomb.LoadFromMesh(mesh);
                _bombExplosion.LoadFromMesh(mesh);
                _bomb.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = textureBomb;
            }
            template<typename F>
            void create(IndieTexture2D textureBomb, IndieVector3 position, F func) {
                create(textureBomb, position);
                _onDetonate = func;
            }
        protected:
    };
}