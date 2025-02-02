/*
** EPITECH PROJECT, 2022
** vector
** File description:
** vector
*/

#pragma once

#include "texture.hpp"

namespace bmb {
    class IndieMaterial {
    public:
        IndieMaterial() = default;
        ~IndieMaterial() = default;
        static Material *Load(const char *fileName, int *materialCount) {
            return LoadMaterials(fileName, materialCount);
        }
        static Material LoadDefault() {
            return LoadMaterialDefault();
        }
        void Unload() {
            return UnloadMaterial(this->_material);
        }
        void SetTexture(int mapType, const IndieTexture2D& texture) {
            return SetMaterialTexture(&this->_material, mapType, texture);
        }
        // void SetModelMesh(IndieModel model, int meshId, int materialId) {
        //     return SetModelMeshMaterial(model, meshId, materialId);
        // }
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
