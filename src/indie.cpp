/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** splashscreen
*/

#include "indieStudio.hpp"

using namespace bmb;

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
	static IndieTexture2D SplashScreenImage("assets/SplashScreen/images/splashscreen.png");
	static IndieSound SplashScreenSound("assets/SplashScreen/audios/splashscreen.ogg");

	if (!SplashScreenSound.isPlaying())
		SplashScreenSound.Play();
	SplashScreenImage.setWidth(1920);
	SplashScreenImage.setHeight(1080);
	int x = (this->screen.GetWidth() - SplashScreenImage.getWidth()) / 2;
	int y = (this->screen.GetHeight() - SplashScreenImage.getHeight()) / 2;
	SplashScreenImage.Draw(x, y, WHITE);
	if (this->timePlayed > 5.0f)
		DrawRectangle(x + (SplashScreenImage.getWidth() / 2) - (SplashScreenImage.getWidth() / 4), 500 + (SplashScreenImage.getHeight() / 2) - (SplashScreenImage.getHeight() / 4), SplashScreenImage.getWidth() / 2, SplashScreenImage.getHeight() / 32, WHITE);
	else
		DrawRectangle(x + (SplashScreenImage.getWidth() / 2) - (SplashScreenImage.getWidth() / 4), 500 + (SplashScreenImage.getHeight() / 2) - (SplashScreenImage.getHeight() / 4), SplashScreenImage.getWidth() / 2 * this->timePlayed / 5.0f, SplashScreenImage.getHeight() / 32, WHITE);
	//if the window is resized, the splashscreen and the progress bar are resized too
	if (this->screen.GetWidth() != 1920 || this->screen.GetHeight() != 1080) {
		SplashScreenImage.setWidth(this->screen.GetWidth());
		SplashScreenImage.setHeight(this->screen.GetHeight());
		x = (this->screen.GetWidth() - SplashScreenImage.getWidth()) / 2;
		y = (this->screen.GetHeight() - SplashScreenImage.getHeight()) / 2;
		DrawTexture(SplashScreenImage, x, y, WHITE);
		if (this->timePlayed > 5.0f)
			DrawRectangle(x + (SplashScreenImage.getWidth() / 2) - (SplashScreenImage.getWidth() / 4), 500 + (SplashScreenImage.getHeight() / 2) - (SplashScreenImage.getHeight() / 4), SplashScreenImage.getWidth() / 2, SplashScreenImage.getHeight() / 32, WHITE);
		else
			DrawRectangle(x + (SplashScreenImage.getWidth() / 2) - (SplashScreenImage.getWidth() / 4), 500 + (SplashScreenImage.getHeight() / 2) - (SplashScreenImage.getHeight() / 4), SplashScreenImage.getWidth() / 2 * this->timePlayed / 5.0f, SplashScreenImage.getHeight() / 32, WHITE);
	}
	if (this->timePlayed > 5.0f) {
		this->state = mainMenu;
        SplashScreenSound.Stop();
	}
}

void Indie::displayMainMenu(float musicTime) {
    static IndieTexture2D mainMenuBackground("assets/MainMenu/images/mainmenu.png");
	static IndieTexture2D TitleImage("assets/MainMenu/images/IndieCraft.png");
	static IndieTexture2D singleplayer("assets/MainMenu/images/buttons/singleplayer.png");
	static IndieTexture2D singleplayerHighlighted("assets/MainMenu/images/buttons/singleplayer_highlight.png");
	static IndieTexture2D multiplayer("assets/MainMenu/images/buttons/multiplayer.png");
	static IndieTexture2D multiplayerHighlighted("assets/MainMenu/images/buttons/multiplayer_highlight.png");
	static IndieTexture2D options("assets/MainMenu/images/buttons/options.png");
	static IndieTexture2D optionsHighlighted("assets/MainMenu/images/buttons/options_highlight.png");
	static IndieTexture2D quitgame("assets/MainMenu/images/buttons/quitgame.png");
	static IndieTexture2D quitgameHighlighted("assets/MainMenu/images/buttons/quitgame_highlight.png");
	static IndieTexture2D accessibility("assets/MainMenu/images/buttons/accessibility.png");
	static IndieTexture2D accessibilityHighlighted("assets/MainMenu/images/buttons/accessibility_highlight.png");
	static IndieTexture2D SplashText("assets/MainMenu/images/splashtext.png");
	static float frameHeightSingleplayer = (float)singleplayer.getHeight()/3;
	static float frameHeightMultiplayer = (float)multiplayer.getHeight()/3;
	static float frameHeightOptions = (float)options.getHeight()/3;
	static float frameHeightQuitgame = (float)quitgame.getHeight()/3;
	static float frameHeightAccessibility = (float)accessibility.getHeight()/3;
    static IndieMusic MainMenuMusic("assets/MainMenu/audios/Moog-City.mp3");
	static IndieSound buttonSound("assets/MainMenu/audios/button.ogg");
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
	mainMenuBackground.setWidth(1920);
    mainMenuBackground.setHeight(1080);
    static float mainMenuBackground_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float mainMenuBackground_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
	static float middle_x = (this->screen.GetWidth() - TitleImage.getWidth()) / 2;
	static float middle_y = (this->screen.GetHeight() - TitleImage.getHeight()) / 2;
    DrawTexture(mainMenuBackground, mainMenuBackground_x, mainMenuBackground_y, WHITE);
	DrawTexture(TitleImage, middle_x, 75, WHITE);
	DrawTexture(singleplayer, middle_x, middle_y + 50, WHITE);
	DrawTexture(multiplayer, middle_x, middle_y + 150, WHITE);
	DrawTexture(options, middle_x, middle_y + 250, WHITE);
	DrawTexture(quitgame, middle_x + 408, middle_y + 250, WHITE);
	DrawTexture(accessibility, middle_x + 825, middle_y + 250, WHITE);
	// Ici faudrait faire une sorte d'effet de bpm pour le splashtext
	DrawTexture(SplashText, middle_x + 675, 10, WHITE);
	DrawText("IndieCraft is an Epitech project, based on the bomberman", this->screen.GetWidth() - 600, this->screen.GetHeight() - 30, 20, WHITE);

	static Rectangle sourceRecSingleplayer = {0, 0, singleplayer.getWidth(), singleplayer.getHeight()};
	static Rectangle destinationRecSingleplayer = {middle_x, middle_y + 50, singleplayer.getWidth(), singleplayer.getHeight()};
	static Rectangle sourceRecMultiplayer = {0, 0, multiplayer.getWidth(), multiplayer.getHeight()};
	static Rectangle destinationRecMultiplayer = {middle_x, middle_y + 150, multiplayer.getWidth(), multiplayer.getHeight()};
	static Rectangle sourceRecOptions = {0, 0, options.getWidth(), options.getHeight()};
	static Rectangle destinationRecOptions = {middle_x, middle_y + 250, options.getWidth(), options.getHeight()};
	static Rectangle sourceRecQuitgame = {0, 0, quitgame.getWidth(), quitgame.getHeight()};
	static Rectangle destinationRecQuitgame = {middle_x + 408, middle_y + 250, quitgame.getWidth(), quitgame.getHeight()};
	static Rectangle sourceRecAccessibility = {0, 0, accessibility.getWidth(), accessibility.getHeight()};
	static Rectangle destinationRecAccessibility = {middle_x + 825, middle_y + 250, accessibility.getWidth(), accessibility.getHeight()};
	static Rectangle singleplayerBounds = {middle_x, middle_y + 50, singleplayer.getWidth(), singleplayer.getHeight()};
	static Rectangle singleplayerHighlightedBounds = {middle_x, middle_y + 50, singleplayerHighlighted.getWidth(), singleplayerHighlighted.getHeight()};
	static Rectangle multiplayerBounds = {middle_x, middle_y + 150, multiplayer.getWidth(), multiplayer.getHeight()};
	static Rectangle multiplayerHighlightedBounds = {middle_x, middle_y + 150, multiplayerHighlighted.getWidth(), multiplayerHighlighted.getHeight()};
	static Rectangle optionsBounds = {middle_x, middle_y + 250, options.getWidth(), options.getHeight()};
	static Rectangle optionsHighlightedBounds = {middle_x, middle_y + 250, optionsHighlighted.getWidth(), optionsHighlighted.getHeight()};
	static Rectangle quitgameBounds = {middle_x + 408, middle_y + 250, quitgame.getWidth(), quitgame.getHeight()};
	static Rectangle quitgameHighlightedBounds = {middle_x + 408, middle_y + 250, quitgameHighlighted.getWidth(), quitgameHighlighted.getHeight()};
	static Rectangle accessibilityBounds = {middle_x + 825, middle_y + 250, accessibility.getWidth(), accessibility.getHeight()};
	static Rectangle accessibilityHighlightedBounds = {middle_x + 825, middle_y + 250, accessibilityHighlighted.getWidth(), accessibilityHighlighted.getHeight()};


	// Ce truc sera a adapter partout pour éviter de péter le jeu et les boutons si la window est redimensionnée
	if (this->screen.GetWidth() != mainMenuBackground.getWidth() || this->screen.GetHeight() != mainMenuBackground.getHeight()) {
		mainMenuBackground.setWidth(this->screen.GetWidth());
		mainMenuBackground.setHeight(this->screen.GetHeight());
		mainMenuBackground_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
		mainMenuBackground_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
		middle_x = (this->screen.GetWidth() - TitleImage.getWidth()) / 2;
		middle_y = (this->screen.GetHeight() - TitleImage.getHeight()) / 2;
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
	static IndieTexture2D mainMenuBackground("assets/MainMenu/images/background_options.png");
	static IndieTexture2D playButton("assets/MainMenu/images/buttons/play.png");
	static IndieTexture2D playButtonHighlighted("assets/MainMenu/images/buttons/play_highlight.png");
	static IndieTexture2D cancelButton("assets/MainMenu/images/buttons/cancel.png");
	static IndieTexture2D cancelButtonHighlighted("assets/MainMenu/images/buttons/cancel_highlight.png");
	static IndieSound buttonSound("assets/MainMenu/audios/button.ogg");
    static IndieMusic MainMenuMusic("assets/MainMenu/audios/Moog-City.mp3");
	static float frameHeightPlayButton = (float)playButton.getHeight()/3;
	static float frameHeightCancelButton = (float)cancelButton.getHeight()/3;
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

	static float middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
	static float middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
	static float mainMenuBackground_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float mainMenuBackground_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;

	DrawTexture(mainMenuBackground, mainMenuBackground_x, mainMenuBackground_y, WHITE);
	DrawTexture(playButton, middle_x + 200, middle_y + 850, WHITE);
	DrawTexture(cancelButton, middle_x + 1100, middle_y + 850, WHITE);

	static Rectangle playButtonBounds = { middle_x + 200, middle_y + 850, playButton.getWidth(), playButton.getHeight() };
	static Rectangle playButtonHighlightedBounds = { middle_x + 200, middle_y + 850, playButtonHighlighted.getWidth(), playButtonHighlighted.getHeight() };
	static Rectangle cancelButtonBounds = { middle_x + 1100, middle_y + 850, cancelButton.getWidth(), cancelButton.getHeight() };
	static Rectangle cancelButtonHighlightedBounds = { middle_x + 1100, middle_y + 850, cancelButtonHighlighted.getWidth(), cancelButtonHighlighted.getHeight() };

	if (this->screen.GetWidth() != mainMenuBackground.getWidth() || this->screen.GetHeight() != mainMenuBackground.getHeight()) {
		middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
		middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
		mainMenuBackground_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
		mainMenuBackground_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
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