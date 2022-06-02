/*
** EPITECH PROJECT, 2022
** audioDevice.hpp
** File description:
** include
*/

#pragma once

#include "includes.hpp"

namespace bmb {
	class IndieAudioDevice {
		public:
			IndieAudioDevice() {
				InitAudioDevice();
			}
			~IndieAudioDevice() {
				CloseAudioDevice();
			}
			bool isReady() {
				return IsAudioDeviceReady();
			}
			void setVolume(float volume) {
				SetMasterVolume(volume);
			}
		private:
	};
};