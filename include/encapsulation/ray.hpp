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
        IndieRay(bool hit, float distance) {
            _ray.hit = false;
            _ray.distance = 0;
        };
        operator Ray() const {
            return _ray;
        }
    private:
        Ray _ray;
    };
}
