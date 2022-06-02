/*
** EPITECH PROJECT, 2022
** sound.hpp
** File description:
** include
*/

#pragma once

#include "includes.hpp"

namespace bmb {
	class IndieSound {
		public:
			IndieSound() {};
			IndieSound(Sound sound) {
				this->sound = sound;
			}
			IndieSound(const std::string &fileName) {
				sound = ::LoadSound(fileName.c_str());
			}
			~IndieSound() {
				UnloadSound(sound);
			}
			void LoadSound(const std::string &fileName) {
				sound = ::LoadSound(fileName.c_str());
			}
			void Update(const void *data, int sampleCount) {
				UpdateSound(sound, data, sampleCount);
			}
			void Play() {
				PlaySound(sound);
			}
			void Stop() {
				StopSound(sound);
			}
			void Pause() {
				PauseSound(sound);
			}
			void Resume() {
				ResumeSound(sound);
			}
			void PlayMulti() {
				PlaySoundMulti(sound);
			}
			void StopMulti() {
				StopSoundMulti();
			}
			bool isPlaying() {
				return IsSoundPlaying(sound);
			}
			void setVolume(float volume) {
				SetSoundVolume(sound, volume);
			}
			void setPitch(float pitch) {
				SetSoundPitch(sound, pitch);
			}
			operator Sound() {
				return sound;
			}
		private:
			Sound sound;
	};
};