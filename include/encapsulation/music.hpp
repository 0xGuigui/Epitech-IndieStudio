/*
** EPITECH PROJECT, 2022
** music.hpp
** File description:
** include
*/

#pragma once

#include <string>
#include "raylib.h"

namespace bmb {
	class IndieMusic {
        private:
            Music _music{};

		public:
			IndieMusic() = default;;
			IndieMusic(const std::string &filename) : _music(LoadMusicStream(filename.c_str())) {};
			//Load from memory
			IndieMusic(const std::string &fileType, unsigned char *data, int dataSize) :
                _music(LoadMusicStreamFromMemory(fileType.c_str(), data, dataSize)) {};
			IndieMusic(Music music) {
				this->_music = music;
			}
			~IndieMusic() {
				UnloadMusicStream(_music);
			}
			void Load(const std::string &filename) {
				_music = LoadMusicStream(filename.c_str());
			}
			void LoadFromMemory(const std::string &fileType, unsigned char *data, int dataSize) {
				_music = LoadMusicStreamFromMemory(fileType.c_str(), data, dataSize);
			}
			void Play() {
				PlayMusicStream(_music);
			}
			bool isPlaying() {
				return IsMusicStreamPlaying(_music);
			}
			void Update() {
				UpdateMusicStream(_music);
			}
			void Stop() {
				StopMusicStream(_music);
			}
			void Pause() {
				PauseMusicStream(_music);
			}
			void Resume() {
				ResumeMusicStream(_music);
			}
			void Seek(float position) {
				SeekMusicStream(_music, position);
			}
			void setVolume(float volume) {
				SetMusicVolume(_music, volume);
			}
			void setPitch(float pitch) {
				SetMusicPitch(_music, pitch);
			}
			float getTimeLength() {
				return GetMusicTimeLength(_music);
			}
			float getTimePlayed() {
				return GetMusicTimePlayed(_music);
			}
			void setLoop(bool loop) {
				_music.looping = loop;
			}
			operator Music() const {
				return _music;
			}
	};
};