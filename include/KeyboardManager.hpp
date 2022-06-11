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
			std::map<KeyboardKey, std::tuple<std::function<void()>, std::function<void()>>> map;
		public:
			KeyboardManager() = default;
			template<typename F, typename F2>
			void bind(KeyboardKey key, F onPress, F2 onRelease) {
				map[key] = { std::function<void()>(onPress), std::function<void()>(onRelease) };
			}
			void unbind(KeyboardKey key) {
				map.erase(key);
			}
			void update() {
				for (const auto &[key, funcTuple] : map) {
					if (IsKeyDown(key)) {
						std::get<0>(funcTuple)();
					}
					if (IsKeyReleased(key)) {
						std::get<1>(funcTuple)();
					}
				}
			}
			auto &operator [] (KeyboardKey key) {
				return map[key];
			}
	};
};