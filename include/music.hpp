/*
** EPITECH PROJECT, 2022
** music.hpp
** File description:
** include
*/

#pragma once

#include "includes.hpp"

namespace bmb {
	class IndieMusic {
		public:
			IndieMusic() {};
			IndieMusic(Music music) {
				this->music = music;
			}
			operator Music () {
				return this->music;
			}
		private:
			Music music;
	};
};