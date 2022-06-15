/*
** EPITECH PROJECT, 2022
** KeyboardManager.hpp
** File description:
** include
*/

#pragma once

#include "raylib.h"
#include <functional>
#include <map>
#include <iostream>

namespace bmb {
    class KeyboardManager {
    private:
        std::map<KeyboardKey, std::tuple<std::function<void()>, std::function<void()>, int>> map;
    public:
        KeyboardManager() = default;

        template<typename F, typename F2>
        void bind(KeyboardKey key, F onPress, F2 onRelease, int state = 6) {
            map[key] = {std::function<void()>(onPress), std::function<void()>(onRelease), state};
        }

        void unbind(KeyboardKey key) {
            map.erase(key);
        }

        void update(int state) {
            for (const auto &[key, funcTuple]: map) {
                if (IsKeyDown(key) && (std::get<2>(funcTuple) == 6 || std::get<2>(funcTuple) == state)) {
                    std::get<0>(funcTuple)();
                }
                if (IsKeyReleased(key) && (std::get<2>(funcTuple) == 6 || std::get<2>(funcTuple) == state)) {
                    std::get<1>(funcTuple)();
                }
            }
        }

        auto &operator[](KeyboardKey key) {
            return map[key];
        }
    };
}
