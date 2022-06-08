/*
** EPITECH PROJECT, 2022
** KeyboardManager.hpp
** File description:
** include
*/

#include "raylib.h"
#include <functional>
#include <map>

namespace bmb {
	class KeyboardManager {
		private:
			std::map<KeyboardKey, std::function<void()>> map;
		public:
			KeyboardManager() = default;
			template<typename func>
			void bind(KeyboardKey key, func function) {
				map[key] = function;
			}
			void unbind(KeyboardKey key) {
				map.erase(key);
			}
			void update() {
				for (const auto &[key, func] : map) {
    			    if (IsKeyDown(key))
						func();
    			}
			}
			auto &operator [] (KeyboardKey key) {
				return map[key];
			}
	};
};