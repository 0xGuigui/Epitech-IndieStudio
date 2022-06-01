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
	static Texture2D singleplayerHighlighted = LoadTexture("assets/MainMenu/images/buttons/singleplayer_highlight.png");
	static Texture2D multiplayer = LoadTexture("assets/MainMenu/images/buttons/multiplayer.png");
	static Texture2D multiplayerHighlighted = LoadTexture("assets/MainMenu/images/buttons/multiplayer_highlight.png");
	static Texture2D options = LoadTexture("assets/MainMenu/images/buttons/options.png");
	static Texture2D optionsHighlighted = LoadTexture("assets/MainMenu/images/buttons/options_highlight.png");
	static Texture2D quitgame = LoadTexture("assets/MainMenu/images/buttons/quitgame.png");
	static Texture2D quitgameHighlighted = LoadTexture("assets/MainMenu/images/buttons/quitgame_highlight.png");
	static Texture2D accessibility = LoadTexture("assets/MainMenu/images/buttons/accessibility.png");
	static Texture2D accessibilityHighlighted = LoadTexture("assets/MainMenu/images/buttons/accessibility_highlight.png");
	static float frameHeightSingleplayer = (float)singleplayer.height/3;
	static float frameHeightMultiplayer = (float)multiplayer.height/3;
	static float frameHeightOptions = (float)options.height/3;
	static float frameHeightQuitgame = (float)quitgame.height/3;
	static float frameHeightAccessibility = (float)accessibility.height/3;
    static Music MainMenuMusic = LoadMusicStream("assets/MainMenu/audios/Moog-City.mp3");
    static bool isPlaying = false;
    MainMenuMusic.looping = true;
    static Vector2 mousePoint = { 0.0f, 0.0f };
	mousePoint = GetMousePosition();


    if (!isPlaying) {
        PlayMusicStream(MainMenuMusic);
        isPlaying = true;
    }
    MainMenuImage.width = 1920;
    MainMenuImage.height = 1080;
    float mainMenuBackground_x = (GetScreenWidth() - MainMenuImage.width) / 2;
    float mainMenuBackground_y = (GetScreenHeight() - MainMenuImage.height) / 2;
	float middle_x = (GetScreenWidth() - TitleImage.width) / 2;
	float middle_y = (GetScreenHeight() - TitleImage.height) / 2;
	// int title_y = (GetScreenHeight() - TitleImage.height) / 2;
    DrawTexture(MainMenuImage, mainMenuBackground_x, mainMenuBackground_y, WHITE);
	DrawTexture(TitleImage, middle_x, 75, WHITE);
	DrawTexture(singleplayer, middle_x, middle_y + 50, WHITE);
	DrawTexture(multiplayer, middle_x, middle_y + 150, WHITE);
	DrawTexture(options, middle_x, middle_y + 250, WHITE);
	DrawTexture(quitgame, middle_x + 408, middle_y + 250, WHITE);
	DrawTexture(accessibility, middle_x + 825, middle_y + 250, WHITE);
	static Rectangle sourceRecSingleplayer = {0, 0, singleplayer.width, singleplayer.height};
	static Rectangle sourceRecMultiplayer = {0, 0, multiplayer.width, multiplayer.height};
	static Rectangle sourceRecOptions = {0, 0, options.width, options.height};
	static Rectangle sourceRecQuitgame = {0, 0, quitgame.width, quitgame.height};
	static Rectangle sourceRecAccessibility = {0, 0, accessibility.width, accessibility.height};
	static Rectangle singleplayerBounds = {middle_x, middle_y + 50, singleplayer.width, singleplayer.height};
	static Rectangle multiplayerBounds = {middle_x, middle_y + 150, multiplayer.width, multiplayer.height};
	static Rectangle optionsBounds = {middle_x, middle_y + 250, options.width, options.height};
	static Rectangle quitgameBounds = {middle_x + 408, middle_y + 250, quitgame.width, quitgame.height};
	static Rectangle accessibilityBounds = {middle_x + 825, middle_y + 250, accessibility.width, accessibility.height};
	if (CheckCollisionPointRec(mousePoint, singleplayerBounds))
		DrawTexture(singleplayerHighlighted, middle_x, middle_y + 50, WHITE);
	if (CheckCollisionPointRec(mousePoint, multiplayerBounds))
		DrawTexture(multiplayerHighlighted, middle_x, middle_y + 150, WHITE);
	if (CheckCollisionPointRec(mousePoint, optionsBounds))
		DrawTexture(optionsHighlighted, middle_x, middle_y + 250, WHITE);
	if (CheckCollisionPointRec(mousePoint, quitgameBounds))
		DrawTexture(quitgameHighlighted, middle_x + 408, middle_y + 250, WHITE);
	if (CheckCollisionPointRec(mousePoint, accessibilityBounds)) {
		DrawTexture(accessibilityHighlighted, middle_x + 825, middle_y + 250, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			OpenURL("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
	}
    UpdateMusicStream(MainMenuMusic);
}

