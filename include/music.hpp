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
			IndieMusic(const std::string &filename) {
				music = LoadMusicStream(filename.c_str());
			}
			//Load from memory
			IndieMusic(const std::string &fileType, unsigned char *data, int dataSize) {
				music = LoadMusicStreamFromMemory(fileType.c_str(), data, dataSize);
			}
			~IndieMusic() {
				UnloadMusicStream(music);
			}
			void Load(const std::string &filename) {
				music = LoadMusicStream(filename.c_str());
			}
			void LoadFromMemory(const std::string &fileType, unsigned char *data, int dataSize) {
				music = LoadMusicStreamFromMemory(fileType.c_str(), data, dataSize);
			}
			void Play() {
				PlayMusicStream(music);
			}
			bool isPlaying() {
				return IsMusicStreamPlaying(music);
			}
			void Update() {
				UpdateMusicStream(music);
			}
			void Stop() {
				StopMusicStream(music);
			}
			void Pause() {
				PauseMusicStream(music);
			}
			void Resume() {
				ResumeMusicStream(music);
			}
			void Seek(float position) {
				SeekMusicStream(music, position);
			}
			void setVolume(float volume) {
				SetMusicVolume(music, volume);
			}
			void setPitch(float pitch) {
				SetMusicPitch(music, pitch);
			}
			float getTimeLength() {
				return GetMusicTimeLength(music);
			}
			float getTimePlayed() {
				return GetMusicTimePlayed(music);
			}
			operator Music () {
				return this->music;
			}
		private:
			Music music;
	};
};