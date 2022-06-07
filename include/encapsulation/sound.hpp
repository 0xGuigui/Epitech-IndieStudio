/*
** EPITECH PROJECT, 2022
** sound.hpp
** File description:
** include
*/

#pragma once

#include "raylib.h"
#include <string>

namespace bmb {
	class IndieSound {
        private:
            Sound _sound{};

		public:
			IndieSound() = default;;
			IndieSound(const Sound &sound) : _sound(sound) {};
			explicit IndieSound(const std::string &fileName) : _sound(::LoadSound(fileName.c_str())) {};
			~IndieSound() {
				// UnloadSound(_sound);
			}
			void LoadSound(const std::string &fileName) {
				_sound = ::LoadSound(fileName.c_str());
			}
			void Update(const void *data, int sampleCount) {
				UpdateSound(_sound, data, sampleCount);
			}
			void Play() {
				PlaySound(_sound);
			}
			void Stop() {
				StopSound(_sound);
			}
			void Pause() {
				PauseSound(_sound);
			}
			void Resume() {
				ResumeSound(_sound);
			}
			void PlayMulti() {
				PlaySoundMulti(_sound);
			}
			static void StopMulti() {
				StopSoundMulti();
			}
			bool isPlaying() {
				return IsSoundPlaying(_sound);
			}
			void setVolume(float volume) {
				SetSoundVolume(_sound, volume);
			}
			void setPitch(float pitch) {
				SetSoundPitch(_sound, pitch);
			}
			operator Sound() const {
				return _sound;
			}
	};
};