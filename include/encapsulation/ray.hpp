/*
** EPITECH PROJECT, 2022
** ray
** File description:
** ray
*/

#pragma once

#include "raylib.h"
#include "vector.hpp"

namespace bmb {
    class IndieRay {
    public:
        IndieRay() = default;
        IndieRay(const Ray &ray) : _ray(ray) {};
        IndieRay(const IndieVector3& position, const IndieVector3& direction) {
            _ray.direction = direction;
            _ray.position = position;
        }
        void Load(const IndieVector3& position, const IndieVector3& direction) {
            _ray.direction = direction;
            _ray.position = position;
        }
        operator Ray() const {
            return _ray;
        }
    private:
        Ray _ray;
    };
}
