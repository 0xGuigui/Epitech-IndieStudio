/*
** EPITECH PROJECT, 2022
** vector
** File description:
** vector
*/

#pragma once

#include "raylib.h"
#include "texture.hpp"
#include "model.hpp"

namespace bmb {
    class IndieMaterial {
    public:
        IndieMaterial() {};
        ~IndieMaterial() {};
        Material *Load(const char *fileName, int *materialCount) {
            return LoadMaterials(fileName, materialCount);
        }
        Material LoadDefault(void) {
            return LoadMaterialDefault();
        }
        void Unload() {
            return UnloadMaterial(this->_material);
        }
        void SetTexture(int mapType, IndieTexture2D texture) {
            return SetMaterialTexture(&this->_material, mapType, texture);
        }
        void SetModelMesh(IndieModel model, int meshId, int materialId) {
            return SetModelMeshMaterial(model, meshId, materialId);
        }
        operator Material() const {
            return _material;
        };

    private:
        Material _material;
    };

    class IndieMaterialMap {
    private:
        MaterialMap _materialMap;
    };
}
