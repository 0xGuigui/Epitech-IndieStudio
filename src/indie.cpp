/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
*/

#include "indieStudio.hpp"

Indie::Indie() {}

Indie::~Indie() {}

float Indie::getTimeMusicPlayed() {
	return this->_musicPlayed;
}

float Indie::setTimeMusicPlayed(int time) {
	this->_musicPlayed = time;
	return this->_musicPlayed;
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
	if (this->timePlayed > 5.0f)
		DrawRectangle(x + (SplashScreenImage.width / 2) - (SplashScreenImage.width / 4), 500 + (SplashScreenImage.height / 2) - (SplashScreenImage.height / 4), SplashScreenImage.width / 2, SplashScreenImage.height / 32, WHITE);
	else
		DrawRectangle(x + (SplashScreenImage.width / 2) - (SplashScreenImage.width / 4), 500 + (SplashScreenImage.height / 2) - (SplashScreenImage.height / 4), SplashScreenImage.width / 2 * this->timePlayed / 5.0f, SplashScreenImage.height / 32, WHITE);
	//if the window is resized, the splashscreen and the progress bar are resized too
	if (GetScreenWidth() != 1920 || GetScreenHeight() != 1080) {
		SplashScreenImage.width = GetScreenWidth();
		SplashScreenImage.height = GetScreenHeight();
		x = (GetScreenWidth() - SplashScreenImage.width) / 2;
		y = (GetScreenHeight() - SplashScreenImage.height) / 2;
		DrawTexture(SplashScreenImage, x, y, WHITE);
		if (this->timePlayed > 5.0f)
			DrawRectangle(x + (SplashScreenImage.width / 2) - (SplashScreenImage.width / 4), 500 + (SplashScreenImage.height / 2) - (SplashScreenImage.height / 4), SplashScreenImage.width / 2, SplashScreenImage.height / 32, WHITE);
		else
			DrawRectangle(x + (SplashScreenImage.width / 2) - (SplashScreenImage.width / 4), 500 + (SplashScreenImage.height / 2) - (SplashScreenImage.height / 4), SplashScreenImage.width / 2 * this->timePlayed / 5.0f, SplashScreenImage.height / 32, WHITE);
	}
	if (this->timePlayed > 5.0f) {
		this->state = mainMenu;
		isPlaying = false;
        StopSound(SplashScreenSound);
	}
}

void Indie::displayMainMenu(float musicTime) {
    static Texture2D mainMenuBackground = LoadTexture("assets/MainMenu/images/mainmenu.png");
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
	static Sound buttonSound = LoadSound("assets/MainMenu/audios/button.ogg");
    static bool isPlaying = false;
    MainMenuMusic.looping = true;
    static Vector2 mousePoint = { 0.0f, 0.0f };
	mousePoint = GetMousePosition();


    if (!isPlaying) {
        if (musicTime != 0) {
		SeekMusicStream(MainMenuMusic, musicTime);
		PlayMusicStream(MainMenuMusic);
		isPlaying = true;
		} else
			PlayMusicStream(MainMenuMusic);
	}

	timePlayed += GetFrameTime();
	mainMenuBackground.width = 1920;
    mainMenuBackground.height = 1080;
    static float mainMenuBackground_x = (GetScreenWidth() - mainMenuBackground.width) / 2;
    static float mainMenuBackground_y = (GetScreenHeight() - mainMenuBackground.height) / 2;
	static float middle_x = (GetScreenWidth() - TitleImage.width) / 2;
	static float middle_y = (GetScreenHeight() - TitleImage.height) / 2;
    DrawTexture(mainMenuBackground, mainMenuBackground_x, mainMenuBackground_y, WHITE);
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
	if (GetScreenWidth() != mainMenuBackground.width || GetScreenHeight() != mainMenuBackground.height) {
		mainMenuBackground.width = GetScreenWidth();
		mainMenuBackground.height = GetScreenHeight();
		mainMenuBackground_x = (GetScreenWidth() - mainMenuBackground.width) / 2;
		mainMenuBackground_y = (GetScreenHeight() - mainMenuBackground.height) / 2;
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

	if (CheckCollisionPointRec(mousePoint, singleplayerBounds)) {
		DrawTexture(singleplayerHighlighted, middle_x, middle_y + 50, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			PlaySound(buttonSound);
			this->_musicPlayed = GetMusicTimePlayed(MainMenuMusic);
			StopMusicStream(MainMenuMusic);
			this->state = singlePlayerMenu;
		}
	}
	if (CheckCollisionPointRec(mousePoint, multiplayerBounds)) {
		DrawTexture(multiplayerHighlighted, middle_x, middle_y + 150, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			PlaySound(buttonSound);
			//this->state = multiPlayerMenu;
		}
	}
	if (CheckCollisionPointRec(mousePoint, optionsBounds)) {
		DrawTexture(optionsHighlighted, middle_x, middle_y + 250, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			PlaySound(buttonSound);
			//this->state = optionsMenu;
		}
	}
	if (CheckCollisionPointRec(mousePoint, quitgameBounds)) {
		DrawTexture(quitgameHighlighted, middle_x + 408, middle_y + 250, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			PlaySound(buttonSound);
			//this->state = quitGameMenu;
		}
	}
	if (CheckCollisionPointRec(mousePoint, accessibilityBounds)) {
		DrawTexture(accessibilityHighlighted, middle_x + 825, middle_y + 250, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			PlaySound(buttonSound);
			OpenURL("https://bit.ly/3PSsHwZ");
		}
	}
    UpdateMusicStream(MainMenuMusic);
}

void Indie::displaySinglePlayerMenu(float musicTime) {
	static Texture2D mainMenuBackground = LoadTexture("assets/MainMenu/images/background_options.png");
	static Texture2D playButton = LoadTexture("assets/MainMenu/images/buttons/play.png");
	static Texture2D playButtonHighlighted = LoadTexture("assets/MainMenu/images/buttons/play_highlight.png");
	static Texture2D cancelButton = LoadTexture("assets/MainMenu/images/buttons/cancel.png");
	static Texture2D cancelButtonHighlighted = LoadTexture("assets/MainMenu/images/buttons/cancel_highlight.png");
	static Sound buttonSound = LoadSound("assets/MainMenu/audios/button.ogg");
    static Music MainMenuMusic = LoadMusicStream("assets/MainMenu/audios/Moog-City.mp3");
	static float frameHeightPlayButton = (float)playButton.height/3;
	static float frameHeightCancelButton = (float)cancelButton.height/3;
	static Vector2 mousePoint = { 0.0f, 0.0f };
	mousePoint = GetMousePosition();

	static float musicPlayed = this->_musicPlayed;
	static bool isPlaying = false;
    MainMenuMusic.looping = true;

	if (musicTime != 0 && !isPlaying) {
		SeekMusicStream(MainMenuMusic, musicTime);
		PlayMusicStream(MainMenuMusic);
		isPlaying = true;
	}

	static float middle_x = (GetScreenWidth() - mainMenuBackground.width) / 2;
	static float middle_y = (GetScreenHeight() - mainMenuBackground.height) / 2;
	static float mainMenuBackground_x = (GetScreenWidth() - mainMenuBackground.width) / 2;
    static float mainMenuBackground_y = (GetScreenHeight() - mainMenuBackground.height) / 2;

	DrawTexture(mainMenuBackground, mainMenuBackground_x, mainMenuBackground_y, WHITE);
	DrawTexture(playButton, middle_x + 200, middle_y + 850, WHITE);
	DrawTexture(cancelButton, middle_x + 1100, middle_y + 850, WHITE);

	static Rectangle playButtonBounds = { middle_x + 200, middle_y + 850, playButton.width, playButton.height };
	static Rectangle playButtonHighlightedBounds = { middle_x + 200, middle_y + 850, playButtonHighlighted.width, playButtonHighlighted.height };
	static Rectangle cancelButtonBounds = { middle_x + 1100, middle_y + 850, cancelButton.width, cancelButton.height };
	static Rectangle cancelButtonHighlightedBounds = { middle_x + 1100, middle_y + 850, cancelButtonHighlighted.width, cancelButtonHighlighted.height };

	if (GetScreenWidth() != mainMenuBackground.width || GetScreenHeight() != mainMenuBackground.height) {
		middle_x = (GetScreenWidth() - mainMenuBackground.width) / 2;
		middle_y = (GetScreenHeight() - mainMenuBackground.height) / 2;
		mainMenuBackground_x = (GetScreenWidth() - mainMenuBackground.width) / 2;
		mainMenuBackground_y = (GetScreenHeight() - mainMenuBackground.height) / 2;
		playButtonBounds.x = middle_x + 200;
		playButtonBounds.y = middle_y + 850;
		playButtonHighlightedBounds.x = middle_x + 200;
		playButtonHighlightedBounds.y = middle_y + 850;
		cancelButtonBounds.x = middle_x + 1100;
		cancelButtonBounds.y = middle_y + 850;
		cancelButtonHighlightedBounds.x = middle_x + 1100;
		cancelButtonHighlightedBounds.y = middle_y + 850;
	}


	if (CheckCollisionPointRec(mousePoint, playButtonBounds))
		DrawTexture(playButtonHighlighted, middle_x + 200, middle_y + 850, WHITE);
	if (CheckCollisionPointRec(mousePoint, cancelButtonBounds)) {
		DrawTexture(cancelButtonHighlighted, middle_x + 1100, middle_y + 850, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			PlaySound(buttonSound);
			StopMusicStream(MainMenuMusic);
			this->state = mainMenu;
		}
	}
	UpdateMusicStream(MainMenuMusic);
}