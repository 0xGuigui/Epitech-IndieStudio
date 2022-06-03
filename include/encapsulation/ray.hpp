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
        operator Ray() const {
            return _ray;
        }

        IndieRay(const Ray &ray) : _ray(ray) {};
    private:
        Ray _ray;
    };
}
