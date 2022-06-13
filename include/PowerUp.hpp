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
            int frame = 0;
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
            void updatePowerUpAnimation();
            void update() {
                if (powerUpPickedUp)
                    updatePowerUpAnimation();
                else
                    updatePowerUpPickedUpAnimation();
                frame++;
            }
            void create(IndieTexture2D &texturePowerUp, IndieVector3 position) {
                IndieMesh mesh;
                mesh.GenCube(1.0f, 1.0f, 1.0f);
                _position = position;
                _powerUp.LoadFromMesh(mesh);
                _powerUp.getModel().materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texturePowerUp;
            }
            template<typename F>
            void create(IndieTexture2D &texturePowerUp, IndieVector3 position, F onPick) {
                create(texturePowerUp, position);
                _onPick = onPick;
            }
        protected:
    }
}