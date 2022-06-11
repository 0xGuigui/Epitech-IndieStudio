/*
** EPITECH PROJECT, 2022
** bomb
** File description:
** bomb
*/

#pragma once

#include "encapsulation/texture.hpp"

namespace bmb {
    class IndieBomb {
        private:
            int frame = 0;
            //int bombStock = 0;
            //int bombFireUp = 0;
            IndieColor bombColor = WHITE;
            IndieVector3 position;
            IndieModel _bombDestroyed;
            IndieModel _bombCreated;
            bool bombExplosion = false;
        public:
            IndieBomb() = default;
            ~IndieBomb() = default;
            void Draw();
            IndieTexture2D texture = IndieTexture2D("assets/textures/blocks/tnt.png");
            void startExplosion() {
                bombExplosion = true;
            }
            void updateBombAnimation() {
                // Draw cube red or white
                DrawCube(position, 1.0f, 1.0f, 1.0f, bombColor);
            }
            void updateExplosionAnimation() {
                //Draw texture explosion
                DrawTexture(texture, position.getX(), position.getY(), bombColor);
            }
            void update() {
                if (bombExplosion)
                    updateExplosionAnimation();
                else
                    updateBombAnimation();
                frame++;
            }
            int BombCreation(const IndieTexture2D texture, const IndieVector3 position){
                IndieMesh
                _bombDestroyed.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
            }
        protected:
    };
}