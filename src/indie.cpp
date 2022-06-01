/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
*/

#include "indieStudio.hpp"

Indie::Indie() {}

Indie::~Indie() {}

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
	static Texture2D TitleImage = LoadTexture("assets/MainMenu/images/IndieCraft.png");
	static Texture2D singleplayer = LoadTexture("assets/MainMenu/images/buttons/singleplayer.png");
	static Texture2D multiplayer = LoadTexture("assets/MainMenu/images/buttons/multiplayer.png");
	static Texture2D options = LoadTexture("assets/MainMenu/images/buttons/options.png");
	static Texture2D quitgame = LoadTexture("assets/MainMenu/images/buttons/quitgame.png");
	static Texture2D accessibility = LoadTexture("assets/MainMenu/images/buttons/accessibility.png");

    static Music MainMenuMusic = LoadMusicStream("assets/MainMenu/audios/Moog-City.mp3");
    static bool isPlaying = false;
    MainMenuMusic.looping = true;


    if (!isPlaying) {
        PlayMusicStream(MainMenuMusic);
        isPlaying = true;
    }
    MainMenuImage.width = 1920;
    MainMenuImage.height = 1080;
    int mainMenuBackground_x = (GetScreenWidth() - MainMenuImage.width) / 2;
    int mainMenuBackground_y = (GetScreenHeight() - MainMenuImage.height) / 2;
	int middle_x = (GetScreenWidth() - TitleImage.width) / 2;
	int middle_y = (GetScreenHeight() - TitleImage.height) / 2;
	// int title_y = (GetScreenHeight() - TitleImage.height) / 2;
    DrawTexture(MainMenuImage, mainMenuBackground_x, mainMenuBackground_y, WHITE);
	DrawTexture(TitleImage, middle_x, 75, WHITE);
	DrawTexture(singleplayer, middle_x, middle_y + 50, WHITE);
	DrawTexture(multiplayer, middle_x, middle_y + 150, WHITE);
	DrawTexture(options, middle_x, middle_y + 250, WHITE);
	DrawTexture(quitgame, middle_x + 408, middle_y + 250, WHITE);
	DrawTexture(accessibility, middle_x + 825, middle_y + 250, WHITE);
    UpdateMusicStream(MainMenuMusic);
}

