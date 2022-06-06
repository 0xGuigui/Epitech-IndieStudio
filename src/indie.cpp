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
	// static IndieRectangle SplashScreenProgressBar(0, 0, 0, 0);
	static bool isPlaying = false;

	if (!isPlaying && !SplashScreenSound.isPlaying()) {
		SplashScreenSound.Play();
		isPlaying = true;
	}
	//Get screen size
	static int screenWidth = this->screen.GetWidth();
	static int screenHeight = this->screen.GetHeight();

	SplashScreenImage.setWidth(screenWidth);
	SplashScreenImage.setHeight(screenHeight);
	int x = (this->screen.GetWidth() - SplashScreenImage.getWidth()) / 2;
	int y = (this->screen.GetHeight() - SplashScreenImage.getHeight()) / 2;
	SplashScreenImage.Draw(x, y, WHITE);
	if (this->timePlayed > 5.0f)
		DrawRectangle(x + (SplashScreenImage.getWidth() / 2) - (SplashScreenImage.getWidth() / 4), 500 + (SplashScreenImage.getHeight() / 2) - (SplashScreenImage.getHeight() / 4), SplashScreenImage.getWidth() / 2, SplashScreenImage.getHeight() / 32, WHITE);
	else
		DrawRectangle(x + (SplashScreenImage.getWidth() / 2) - (SplashScreenImage.getWidth() / 4), 500 + (SplashScreenImage.getHeight() / 2) - (SplashScreenImage.getHeight() / 4), SplashScreenImage.getWidth() / 2 * this->timePlayed / 5.0f, SplashScreenImage.getHeight() / 32, WHITE);
	//if the window is resized, the splashscreen and the progress bar are resized too
	if (this->screen.GetWidth() != screenWidth || this->screen.GetHeight() != screenHeight) {
		SplashScreenImage.setWidth(this->screen.GetWidth());
		SplashScreenImage.setHeight(this->screen.GetHeight());
		x = (this->screen.GetWidth() - SplashScreenImage.getWidth()) / 2;
		y = (this->screen.GetHeight() - SplashScreenImage.getHeight()) / 2;
		SplashScreenImage.Draw(x, y, WHITE);
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
	static IndieTexture2D titleImage("assets/MainMenu/images/IndieCraft.png");
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
	static IndieSound closeSound("assets/SplashScreen/audios/close.ogg");
    static bool isPlaying = false;
    MainMenuMusic.setLoop(true);
    static Vector2 mousePoint = { 0.0f, 0.0f };
	mousePoint = GetMousePosition();

    if (musicTime != 0 && !isPlaying) {
		MainMenuMusic.Seek(musicTime);
		this->setTimeMusicPlayed(musicTime);
		MainMenuMusic.Play();
		isPlaying = true;
	} else
		MainMenuMusic.Play();
	MainMenuMusic.Update();

	timePlayed += GetFrameTime();
	static int screenWidth = this->screen.GetWidth();
	static int screenHeight = this->screen.GetHeight();
	mainMenuBackground.setWidth(screenWidth);
    mainMenuBackground.setHeight(screenHeight);
    static float mainMenuBackground_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float mainMenuBackground_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
	static float middle_x = (this->screen.GetWidth() - titleImage.getWidth()) / 2;
	static float middle_y = (this->screen.GetHeight() - titleImage.getHeight()) / 2;
    mainMenuBackground.Draw(mainMenuBackground_x, mainMenuBackground_y, WHITE);
	titleImage.Draw(middle_x, 75, WHITE);
	singleplayer.Draw(middle_x, middle_y + 50, WHITE);
	multiplayer.Draw(middle_x, middle_y + 150, WHITE);
	options.Draw(middle_x, middle_y + 250, WHITE);
	quitgame.Draw(middle_x + 408, middle_y + 250, WHITE);
	accessibility.Draw(middle_x + 825, middle_y + 250, WHITE);
	// @TODO Ici faudrait faire une sorte d'effet de bpm pour le splashtext
	SplashText.Draw(middle_x + 675, 10, WHITE);
	DrawText("IndieCraft is an Epitech project, based on the bomberman", this->screen.GetWidth() - 600, this->screen.GetHeight() - 30, 20, WHITE);

	static Rectangle sourceRecSingleplayer = {0, 0, static_cast<float>(singleplayer.getWidth()), static_cast<float>(singleplayer.getHeight())};
	static Rectangle destinationRecSingleplayer = {middle_x, middle_y + 50, static_cast<float>(singleplayer.getWidth()), static_cast<float>(singleplayer.getHeight())};
	static Rectangle sourceRecMultiplayer = {0, 0, static_cast<float>(multiplayer.getWidth()), static_cast<float>(multiplayer.getHeight())};
	static Rectangle destinationRecMultiplayer = {middle_x, middle_y + 150, static_cast<float>(multiplayer.getWidth()), static_cast<float>(multiplayer.getHeight())};
	static Rectangle sourceRecOptions = {0, 0, static_cast<float>(options.getWidth()), static_cast<float>(options.getHeight())};
	static Rectangle destinationRecOptions = {middle_x, middle_y + 250, static_cast<float>(options.getWidth()), static_cast<float>(options.getHeight())};
	static Rectangle sourceRecQuitgame = {0, 0, static_cast<float>(quitgame.getWidth()), static_cast<float>(quitgame.getHeight())};
	static Rectangle destinationRecQuitgame = {middle_x + 408, middle_y + 250, static_cast<float>(quitgame.getWidth()), static_cast<float>(quitgame.getHeight())};
	static Rectangle sourceRecAccessibility = {0, 0, static_cast<float>(accessibility.getWidth()), static_cast<float>(accessibility.getHeight())};
	static Rectangle destinationRecAccessibility = {middle_x + 825, middle_y + 250, static_cast<float>(accessibility.getWidth()), static_cast<float>(accessibility.getHeight())};
	static Rectangle singleplayerBounds = {middle_x, middle_y + 50, static_cast<float>(singleplayer.getWidth()), static_cast<float>(singleplayer.getHeight())};
	static Rectangle singleplayerHighlightedBounds = {middle_x, middle_y + 50, static_cast<float>(singleplayerHighlighted.getWidth()), static_cast<float>(singleplayerHighlighted.getHeight())};
	static Rectangle multiplayerBounds = {middle_x, middle_y + 150, static_cast<float>(multiplayer.getWidth()), static_cast<float>(multiplayer.getHeight())};
	static Rectangle multiplayerHighlightedBounds = {middle_x, middle_y + 150, static_cast<float>(multiplayerHighlighted.getWidth()), static_cast<float>(multiplayerHighlighted.getHeight())};
	static Rectangle optionsBounds = {middle_x, middle_y + 250, static_cast<float>(options.getWidth()), static_cast<float>(options.getHeight())};
	static Rectangle optionsHighlightedBounds = {middle_x, middle_y + 250, static_cast<float>(optionsHighlighted.getWidth()), static_cast<float>(optionsHighlighted.getHeight())};
	static Rectangle quitgameBounds = {middle_x + 408, middle_y + 250, static_cast<float>(quitgame.getWidth()), static_cast<float>(quitgame.getHeight())};
	static Rectangle quitgameHighlightedBounds = {middle_x + 408, middle_y + 250, static_cast<float>(quitgameHighlighted.getWidth()), static_cast<float>(quitgameHighlighted.getHeight())};
	static Rectangle accessibilityBounds = {middle_x + 825, middle_y + 250, static_cast<float>(accessibility.getWidth()), static_cast<float>(accessibility.getHeight())};
	static Rectangle accessibilityHighlightedBounds = {middle_x + 825, middle_y + 250, static_cast<float>(accessibilityHighlighted.getWidth()), static_cast<float>(accessibilityHighlighted.getHeight())};


	// Ce truc sera a adapter partout pour éviter de péter le jeu et les boutons si la window est redimensionnée
	if (this->screen.GetWidth() != mainMenuBackground.getWidth() || this->screen.GetHeight() != mainMenuBackground.getHeight()) {
		mainMenuBackground.setWidth(this->screen.GetWidth());
		mainMenuBackground.setHeight(this->screen.GetHeight());
		mainMenuBackground_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
		mainMenuBackground_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
		middle_x = (this->screen.GetWidth() - titleImage.getWidth()) / 2;
		middle_y = (this->screen.GetHeight() - titleImage.getHeight()) / 2;
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
		singleplayerHighlighted.Draw(middle_x, middle_y + 50, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			buttonSound.Play();
			this->_musicPlayed = MainMenuMusic.getTimePlayed();
			this->state = singlePlayerMenu;
			MainMenuMusic.Stop();
		}
	}
	if (CheckCollisionPointRec(mousePoint, multiplayerBounds)) {
		multiplayerHighlighted.Draw(middle_x, middle_y + 150, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			buttonSound.Play();
			//this->state = multiPlayerMenu;
		}
	}
	if (CheckCollisionPointRec(mousePoint, optionsBounds)) {
		optionsHighlighted.Draw(middle_x, middle_y + 250, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			buttonSound.Play();
			//this->state = optionsMenu;
		}
	}
	if (CheckCollisionPointRec(mousePoint, quitgameBounds)) {
		quitgameHighlighted.Draw(middle_x + 408, middle_y + 250, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			buttonSound.Play();
			while (buttonSound.isPlaying());
			closeSound.Play();
			while (closeSound.isPlaying());
			MainMenuMusic.Stop();
			exit(0); // @TODO: A changer pour quitter proprement
		}
	}
	if (CheckCollisionPointRec(mousePoint, accessibilityBounds)) {
		accessibilityHighlighted.Draw(middle_x + 825, middle_y + 250, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			buttonSound.Play();
			OpenURL("https://bit.ly/3PSsHwZ");
		}
	}
    // MainMenuMusic.Update();
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
    MainMenuMusic.setLoop(true);

	if (musicTime != 0 && !isPlaying) {
		MainMenuMusic.Seek(musicTime);
		this->setTimeMusicPlayed(musicTime);
		MainMenuMusic.Play();
		isPlaying = true;
	} else
		MainMenuMusic.Play();
	MainMenuMusic.Update();


	static float middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
	static float middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
	static float mainMenuBackground_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float mainMenuBackground_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;

	mainMenuBackground.Draw(mainMenuBackground_x, mainMenuBackground_y, WHITE);
	playButton.Draw(middle_x + 200, middle_y + 850, WHITE);
	cancelButton.Draw(middle_x + 1100, middle_y + 850, WHITE);

	static Rectangle playButtonBounds = { middle_x + 200, middle_y + 850, static_cast<float>(playButton.getWidth()), static_cast<float>(playButton.getHeight()) };
	static Rectangle playButtonHighlightedBounds = { middle_x + 200, middle_y + 850, static_cast<float>(playButtonHighlighted.getWidth()), static_cast<float>(playButtonHighlighted.getHeight()) };
	static Rectangle cancelButtonBounds = { middle_x + 1100, middle_y + 850, static_cast<float>(cancelButton.getWidth()), static_cast<float>(cancelButton.getHeight()) };
	static Rectangle cancelButtonHighlightedBounds = { middle_x + 1100, middle_y + 850, static_cast<float>(cancelButtonHighlighted.getWidth()), static_cast<float>(cancelButtonHighlighted.getHeight()) };

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

	//@TODO = A adapter lorsque les encapsulations des colisions seront terminées
	if (CheckCollisionPointRec(mousePoint, playButtonBounds))
		playButtonHighlighted.Draw(middle_x + 200, middle_y + 850, WHITE);
	if (CheckCollisionPointRec(mousePoint, cancelButtonBounds)) {
		cancelButtonHighlighted.Draw(middle_x + 1100, middle_y + 850, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			buttonSound.Play();
			this->_musicPlayed = MainMenuMusic.getTimePlayed();
			this->state = mainMenu;
			MainMenuMusic.Stop();
		}
	}
	// MainMenuMusic.Update();
}