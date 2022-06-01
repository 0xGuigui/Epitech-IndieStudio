/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
*/

#include "indieStudio.hpp"

Indie::Indie() {}

Indie::~Indie() {}

static void AudioProcessEffectLPF(void *buffer, unsigned int frames)
{
    static float low[2] = { 0.0f, 0.0f };
    static const float cutoff = 70.0f / 44100.0f; // 70 Hz lowpass filter
    const float k = cutoff / (cutoff + 0.1591549431f); // RC filter formula

    for (unsigned int i = 0; i < frames*2; i += 2)
    {
        float l = ((float *)buffer)[i], r = ((float *)buffer)[i + 1];
        low[0] += k * (l - low[0]);
        low[1] += k * (r - low[1]);
        ((float *)buffer)[i] = low[0];
        ((float *)buffer)[i + 1] = low[1];
    }
}

static float *delayBuffer = NULL;
static unsigned int delayBufferSize = 0;
static unsigned int delayReadIndex = 2;
static unsigned int delayWriteIndex = 0;

// Audio effect: delay
static void AudioProcessEffectDelay(void *buffer, unsigned int frames)
{
    for (unsigned int i = 0; i < frames*2; i += 2)
    {
        float leftDelay = delayBuffer[delayReadIndex++];    // ERROR: Reading buffer -> WHY??? Maybe thread related???
        float rightDelay = delayBuffer[delayReadIndex++];

        if (delayReadIndex == delayBufferSize) delayReadIndex = 0;

        ((float *)buffer)[i] = 0.5f*((float *)buffer)[i] + 0.5f*leftDelay;
        ((float *)buffer)[i + 1] = 0.5f*((float *)buffer)[i + 1] + 0.5f*rightDelay;

        delayBuffer[delayWriteIndex++] = ((float *)buffer)[i];
        delayBuffer[delayWriteIndex++] = ((float *)buffer)[i + 1];
        if (delayWriteIndex == delayBufferSize) delayWriteIndex = 0;
    }
}

void Indie::displaySplashScreen() {
	static Texture2D SplashScreenImage = LoadTexture("assets/SplashScreen/images/splashscreen.png");
	static Sound SplashScreenSound = LoadSound("assets/SplashScreen/audios/splashscreen.ogg");
	static bool isPlaying = false;

	if (!isPlaying) {
		PlaySound(SplashScreenSound);
		isPlaying = true;
	}
	SplashScreenImage.width = 1920;
	SplashScreenImage.height = 1080;
	int x = (GetScreenWidth() - SplashScreenImage.width) / 2;
	int y = (GetScreenHeight() - SplashScreenImage.height) / 2;
	DrawTexture(SplashScreenImage, x, y, WHITE);
	if (this->timePlayed > 5.0f) {
		this->state = mainMenu;
		isPlaying = false;
        StopSound(SplashScreenSound);
	}
}

void Indie::displayMainMenu() {
    static Texture2D MainMenuImage = LoadTexture("assets/MainMenu/images/mainmenu.png");
    static Music MainMenuMusic = LoadMusicStream("assets/MainMenu/audios/Moog-City.mp3");
    static bool isPlaying = false;


    if (!isPlaying) {
        PlayMusicStream(MainMenuMusic);
        isPlaying = true;
    }
    MainMenuImage.width = 1920;
    MainMenuImage.height = 1080;
    int x = (GetScreenWidth() - MainMenuImage.width) / 2;
    int y = (GetScreenHeight() - MainMenuImage.height) / 2;
    DrawTexture(MainMenuImage, x, y, WHITE);
}

