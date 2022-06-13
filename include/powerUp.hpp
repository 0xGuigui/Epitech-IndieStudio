/*
** EPITECH PROJECT, 2022
** powerup
** File description:
** powerup
*/

#include "indie.hpp"

#pragma once

namespace bmb {
    class IndiePowerUp {
        private:
            IndieModel _powerUp;
            IndieVector3 _position;
        public:
            IndiePowerUp() = default;
            virtual ~IndiePowerUp() = default;
            void create(IndieTexture2D &texturePowerUp, IndieVector3 position) = 0;
            void update() = 0;
            void draw() = 0;
    };
}

//display powerup | collision player/powerup
// namespace bmb {
//     class IndiePowerUp {
//         private:
//             int frame = 0;
//             IndieColor powerUpColor = WHITE;
//             IndieVector3 _position;
//             IndieModel _powerUp;
//             std::function<void()> _onPick;
//             bool powerUpPickedUp = false;
//         public:
//             IndiePowerUp() = default;
//             ~IndiePowerUp();
//             void updatePowerUpAnimation();
//             void update() {
//                 if (powerUpPickedUp)
//                     updatePowerUpAnimation();
//                 else
//                     updatePowerUpPickedUpAnimation();
//                 frame++;
//             }
//             void create(IndieTexture2D &texturePowerUp, IndieVector3 position) {
//                 IndieMesh mesh;
//                 mesh.GenCube(1.0f, 1.0f, 1.0f);
//                 //_position = position; gen à revoir pour le rand sur la map
//                 _powerUp.LoadFromMesh(mesh);
//                 _powerUp.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texturePowerUp;
//             }
//             template<typename F>
//             void create(IndieTexture2D &texturePowerUp, IndieVector3 position, F onPick) {
//                 create(texturePowerUp, position);
//                 _onPick = onPick;
//             }
//         protected:
//     };
// }