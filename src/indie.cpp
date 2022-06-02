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
	static Texture2D SplashText = LoadTexture("assets/MainMenu/images/splashtext.png");
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
	timePlayed += GetFrameTime();
	MainMenuImage.width = 1920;
    MainMenuImage.height = 1080;
    float mainMenuBackground_x = (GetScreenWidth() - MainMenuImage.width) / 2;
    float mainMenuBackground_y = (GetScreenHeight() - MainMenuImage.height) / 2;
	float middle_x = (GetScreenWidth() - TitleImage.width) / 2;
	float middle_y = (GetScreenHeight() - TitleImage.height) / 2;
    DrawTexture(MainMenuImage, mainMenuBackground_x, mainMenuBackground_y, WHITE);
	DrawTexture(TitleImage, middle_x, 75, WHITE);
	DrawTexture(singleplayer, middle_x, middle_y + 50, WHITE);
	DrawTexture(multiplayer, middle_x, middle_y + 150, WHITE);
	DrawTexture(options, middle_x, middle_y + 250, WHITE);
	DrawTexture(quitgame, middle_x + 408, middle_y + 250, WHITE);
	DrawTexture(accessibility, middle_x + 825, middle_y + 250, WHITE);
	// Ici faudrait faire une sorte d'effet de bpm pour le splashtext
	DrawTexture(SplashText, middle_x + 675, 10, WHITE);
	DrawText("IndieCraft is an Epitech project, based on the bomberman", GetScreenWidth() - 600, GetScreenHeight() - 30, 20, WHITE);

	static Rectangle sourceRecSingleplayer = {0, 0, singleplayer.width, singleplayer.height};
	static Rectangle destinationRecSingleplayer = {middle_x, middle_y + 50, singleplayer.width, singleplayer.height};
	static Rectangle sourceRecMultiplayer = {0, 0, multiplayer.width, multiplayer.height};
	static Rectangle destinationRecMultiplayer = {middle_x, middle_y + 150, multiplayer.width, multiplayer.height};
	static Rectangle sourceRecOptions = {0, 0, options.width, options.height};
	static Rectangle destinationRecOptions = {middle_x, middle_y + 250, options.width, options.height};
	static Rectangle sourceRecQuitgame = {0, 0, quitgame.width, quitgame.height};
	static Rectangle destinationRecQuitgame = {middle_x + 408, middle_y + 250, quitgame.width, quitgame.height};
	static Rectangle sourceRecAccessibility = {0, 0, accessibility.width, accessibility.height};
	static Rectangle destinationRecAccessibility = {middle_x + 825, middle_y + 250, accessibility.width, accessibility.height};
	static Rectangle singleplayerBounds = {middle_x, middle_y + 50, singleplayer.width, singleplayer.height};
	static Rectangle singleplayerHighlightedBounds = {middle_x, middle_y + 50, singleplayerHighlighted.width, singleplayerHighlighted.height};
	static Rectangle multiplayerBounds = {middle_x, middle_y + 150, multiplayer.width, multiplayer.height};
	static Rectangle multiplayerHighlightedBounds = {middle_x, middle_y + 150, multiplayerHighlighted.width, multiplayerHighlighted.height};
	static Rectangle optionsBounds = {middle_x, middle_y + 250, options.width, options.height};
	static Rectangle optionsHighlightedBounds = {middle_x, middle_y + 250, optionsHighlighted.width, optionsHighlighted.height};
	static Rectangle quitgameBounds = {middle_x + 408, middle_y + 250, quitgame.width, quitgame.height};
	static Rectangle quitgameHighlightedBounds = {middle_x + 408, middle_y + 250, quitgameHighlighted.width, quitgameHighlighted.height};
	static Rectangle accessibilityBounds = {middle_x + 825, middle_y + 250, accessibility.width, accessibility.height};
	static Rectangle accessibilityHighlightedBounds = {middle_x + 825, middle_y + 250, accessibilityHighlighted.width, accessibilityHighlighted.height};


	// Ce truc sera a adapter partout pour éviter de péter le jeu et les boutons si la window est redimensionnée
	if (GetScreenWidth() != MainMenuImage.width || GetScreenHeight() != MainMenuImage.height) {
		MainMenuImage.width = GetScreenWidth();
		MainMenuImage.height = GetScreenHeight();
		mainMenuBackground_x = (GetScreenWidth() - MainMenuImage.width) / 2;
		mainMenuBackground_y = (GetScreenHeight() - MainMenuImage.height) / 2;
		middle_x = (GetScreenWidth() - TitleImage.width) / 2;
		middle_y = (GetScreenHeight() - TitleImage.height) / 2;
		singleplayerBounds.x = middle_x;
		singleplayerBounds.y = middle_y + 50;
		singleplayerHighlightedBounds.x = middle_x;
		singleplayerHighlightedBounds.y = middle_y + 50;
		multiplayerBounds.x = middle_x;
		multiplayerBounds.y = middle_y + 150;
		multiplayerHighlightedBounds.x = middle_x;
		multiplayerHighlightedBounds.y = middle_y + 150;
		optionsBounds.x = middle_x;
		optionsBounds.y = middle_y + 250;
		optionsHighlightedBounds.x = middle_x;
		optionsHighlightedBounds.y = middle_y + 250;
		quitgameBounds.x = middle_x + 408;
		quitgameBounds.y = middle_y + 250;
		quitgameHighlightedBounds.x = middle_x + 408;
		quitgameHighlightedBounds.y = middle_y + 250;
		accessibilityBounds.x = middle_x + 825;
		accessibilityBounds.y = middle_y + 250;
		accessibilityHighlightedBounds.x = middle_x + 825;
		accessibilityHighlightedBounds.y = middle_y + 250;
	}

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
			OpenURL("https://bit.ly/3PSsHwZ");
	}
    UpdateMusicStream(MainMenuMusic);
}

