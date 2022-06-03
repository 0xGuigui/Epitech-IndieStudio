/*
** EPITECH PROJECT, 2022
** ray
** File description:
** ray
*/

#pragma once

#include "raylib.h"

namespace bmb {
    class IndieRay {
    public:
        IndieRay(const Ray &ray) : _ray(ray) {};
        IndieRay(IndieVector3 position, IndieVector3 direction) {
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
