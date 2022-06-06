/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** MainMenu
*/

#include "indieStudio.hpp"

using namespace bmb;

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


	this->_musicPlayed = MainMenuMusic.getTimePlayed();
    if (musicTime != 0 && !isPlaying) {
		MainMenuMusic.Seek(musicTime);
		this->setTimeMusicPlayed(musicTime);
		MainMenuMusic.Play();
		isPlaying = true;
	} else
		MainMenuMusic.Play();
	MainMenuMusic.Update();

	if (IsKeyPressed(KEY_ESCAPE)) {
		closeSound.Play();
		while (closeSound.isPlaying());
		exit(0);
	}
	timePlayed += GetFrameTime();
	mainMenuBackground.setWidth(this->_screenWidth);
	std::cout << this->_screenHeight << std::endl;
	std::cout << this->_screenWidth << std::endl;
    mainMenuBackground.setHeight(this->_screenHeight);
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
	} else {
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

	static float timer = 0;
	timer += 0.05f;
	static float defaultSizeSplashTextWidth = SplashText.getWidth();
	static float defaultSizeSplashTextHeight = SplashText.getHeight();
	if (timer > 0.0f && timer < 1.0f) {
		SplashText.setHeight(SplashText.getHeight() + 1);
		SplashText.setWidth(SplashText.getWidth() + 1);
	} if (timer > 1.0f && timer < 2.0f) {
		SplashText.setHeight(SplashText.getHeight() - 1);
		SplashText.setWidth(SplashText.getWidth() - 1);
	} if (timer > 2.0f) {
		SplashText.setHeight(defaultSizeSplashTextHeight);
		SplashText.setWidth(defaultSizeSplashTextWidth);
		timer = 0;
	}


	if (CheckCollisionPointRec(mousePoint, singleplayerBounds)) {
		singleplayerHighlighted.Draw(middle_x, middle_y + 50, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			buttonSound.Play();
			this->state = singlePlayerMenu;
			MainMenuMusic.Stop();
		}
	} if (CheckCollisionPointRec(mousePoint, multiplayerBounds)) {
		multiplayerHighlighted.Draw(middle_x, middle_y + 150, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			buttonSound.Play();
			this->state = multiplayerMenu;
			MainMenuMusic.Stop();
		}
	} if (CheckCollisionPointRec(mousePoint, optionsBounds)) {
		optionsHighlighted.Draw(middle_x, middle_y + 250, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			buttonSound.Play();
			//this->state = optionsMenu;
		}
	} if (CheckCollisionPointRec(mousePoint, quitgameBounds)) {
		quitgameHighlighted.Draw(middle_x + 408, middle_y + 250, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			buttonSound.Play();
			while (buttonSound.isPlaying());
			closeSound.Play();
			while (closeSound.isPlaying());
			MainMenuMusic.Stop();
			exit(0); // @TODO: A changer pour quitter proprement
		}
	} if (CheckCollisionPointRec(mousePoint, accessibilityBounds)) {
		accessibilityHighlighted.Draw(middle_x + 825, middle_y + 250, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			buttonSound.Play();
			OpenURL("https://bit.ly/3PSsHwZ");
		}
	}
    // MainMenuMusic.Update();
}