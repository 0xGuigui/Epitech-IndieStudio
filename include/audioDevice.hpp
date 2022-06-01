/*
** EPITECH PROJECT, 2022
** audioDevice.hpp
** File description:
** include
*/

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