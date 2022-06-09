/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** MainMenu
*/

#include "indieStudio.hpp"

using namespace bmb;

void Indie::displayMainMenu(float musicTime)
{
	static IndieTexture2D mainMenuBackground = loader.textures["mainmenu"];
	static IndieTexture2D titleImage = loader.textures["IndieCraft"];
	static IndieTexture2D play = loader.textures["singleplayer"];
	static IndieTexture2D playHighlighted = loader.textures["singleplayer_highlight"];
	static IndieTexture2D options = loader.textures["options"];
	static IndieTexture2D optionsHighlighted = loader.textures["options_highlight"];
	static IndieTexture2D quitgame = loader.textures["quitgame"];
	static IndieTexture2D quitgameHighlighted = loader.textures["quitgame_highlight"];
	static IndieTexture2D accessibility = loader.textures["accessibility"];
	static IndieTexture2D accessibilityHighlighted = loader.textures["accessibility_highlight"];
	static IndieTexture2D SplashText = loader.textures["splashtext"];
	static float frameHeightplay = (float)play.getHeight() / 3;
	static float frameHeightOptions = (float)options.getHeight() / 3;
	static float frameHeightQuitgame = (float)quitgame.getHeight() / 3;
	static float frameHeightAccessibility = (float)accessibility.getHeight() / 3;
	static IndieMusic MainMenuMusic = loader.musics["Moog-City"];
	static IndieSound buttonSound = loader.sounds["button"];
	static IndieSound closeSound = loader.sounds["close"];
	static bool isPlaying = false;
	MainMenuMusic.setLoop(true);
	static Vector2 mousePoint = {0.0f, 0.0f};
	mousePoint = GetMousePosition();

	this->_musicPlayed = MainMenuMusic.getTimePlayed();
	if (musicTime != 0 && !isPlaying)
	{
		MainMenuMusic.Seek(musicTime);
		this->setTimeMusicPlayed(musicTime);
		MainMenuMusic.Play();
		isPlaying = true;
	}

	else
		MainMenuMusic.Play();
	MainMenuMusic.Update();
	timePlayed += GetFrameTime();

	mainMenuBackground.setWidth(this->screenWidth);
	mainMenuBackground.setHeight(this->screenHeight);
	static float mainMenuBackground_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
	static float mainMenuBackground_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
	static float middle_x = (this->screen.GetWidth() - titleImage.getWidth()) / 2;
	static float middle_y = (this->screen.GetHeight() - titleImage.getHeight()) / 2;
	mainMenuBackground.Draw(mainMenuBackground_x, mainMenuBackground_y, WHITE);
	titleImage.Draw(middle_x, 75, WHITE);
	play.Draw(middle_x, middle_y + 50, WHITE);
	options.Draw(middle_x, middle_y + 150, WHITE);
	quitgame.Draw(middle_x + 408, middle_y + 150, WHITE);
	accessibility.Draw(middle_x + 825, middle_y + 150, WHITE);


	SplashText.Draw(middle_x + 675, 10, WHITE);
	DrawText("IndieCraft is an Epitech project, based on the bomberman", this->screen.GetWidth() - 600, this->screen.GetHeight() - 30, 20, WHITE);

	static IndieRectangle sourceRecplay = {0, 0, static_cast<float>(play.getWidth()), static_cast<float>(play.getHeight())};
	static IndieRectangle destinationRecplay = {middle_x, middle_y + 50, static_cast<float>(play.getWidth()), static_cast<float>(play.getHeight())};
	static IndieRectangle sourceRecOptions = {0, 0, static_cast<float>(options.getWidth()), static_cast<float>(options.getHeight())};
	static IndieRectangle destinationRecOptions = {middle_x, middle_y + 250, static_cast<float>(options.getWidth()), static_cast<float>(options.getHeight())};
	static IndieRectangle sourceRecQuitgame = {0, 0, static_cast<float>(quitgame.getWidth()), static_cast<float>(quitgame.getHeight())};
	static IndieRectangle destinationRecQuitgame = {middle_x + 408, middle_y + 250, static_cast<float>(quitgame.getWidth()), static_cast<float>(quitgame.getHeight())};
	static IndieRectangle sourceRecAccessibility = {0, 0, static_cast<float>(accessibility.getWidth()), static_cast<float>(accessibility.getHeight())};
	static IndieRectangle destinationRecAccessibility = {middle_x + 825, middle_y + 250, static_cast<float>(accessibility.getWidth()), static_cast<float>(accessibility.getHeight())};
	static IndieRectangle playBounds = {middle_x, middle_y + 50, static_cast<float>(play.getWidth()), static_cast<float>(play.getHeight())};
	static IndieRectangle playHighlightedBounds = {middle_x, middle_y + 50, static_cast<float>(playHighlighted.getWidth()), static_cast<float>(playHighlighted.getHeight())};
	static IndieRectangle optionsBounds = {middle_x, middle_y + 150, static_cast<float>(options.getWidth()), static_cast<float>(options.getHeight())};
	static IndieRectangle optionsHighlightedBounds = {middle_x, middle_y + 150, static_cast<float>(optionsHighlighted.getWidth()), static_cast<float>(optionsHighlighted.getHeight())};
	static IndieRectangle quitgameBounds = {middle_x + 408, middle_y + 150, static_cast<float>(quitgame.getWidth()), static_cast<float>(quitgame.getHeight())};
	static IndieRectangle quitgameHighlightedBounds = {middle_x + 408, middle_y + 150, static_cast<float>(quitgameHighlighted.getWidth()), static_cast<float>(quitgameHighlighted.getHeight())};
	static IndieRectangle accessibilityBounds = {middle_x + 825, middle_y + 150, static_cast<float>(accessibility.getWidth()), static_cast<float>(accessibility.getHeight())};
	static IndieRectangle accessibilityHighlightedBounds = {middle_x + 825, middle_y + 150, static_cast<float>(accessibilityHighlighted.getWidth()), static_cast<float>(accessibilityHighlighted.getHeight())};

	// Ce truc sera a adapter partout pour éviter de péter le jeu et les boutons si la window est redimensionnée
	if (this->screen.GetWidth() != mainMenuBackground.getWidth() || this->screen.GetHeight() != mainMenuBackground.getHeight())
	{
		mainMenuBackground.setWidth(this->screen.GetWidth());
		mainMenuBackground.setHeight(this->screen.GetHeight());
		mainMenuBackground_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
		mainMenuBackground_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
		middle_x = (this->screen.GetWidth() - titleImage.getWidth()) / 2;
		middle_y = (this->screen.GetHeight() - titleImage.getHeight()) / 2;
		playBounds = {middle_x, middle_y + 50, static_cast<float>(play.getWidth()), static_cast<float>(play.getHeight())};
		playHighlightedBounds = {middle_x, middle_y + 50, static_cast<float>(playHighlighted.getWidth()), static_cast<float>(playHighlighted.getHeight())};
		optionsBounds = {middle_x, middle_y + 150, static_cast<float>(options.getWidth()), static_cast<float>(options.getHeight())};
		optionsHighlightedBounds = {middle_x, middle_y + 150, static_cast<float>(optionsHighlighted.getWidth()), static_cast<float>(optionsHighlighted.getHeight())};
		quitgameBounds = {middle_x + 408, middle_y + 150, static_cast<float>(quitgame.getWidth()), static_cast<float>(quitgame.getHeight())};
		quitgameHighlightedBounds = {middle_x + 408, middle_y + 150, static_cast<float>(quitgameHighlighted.getWidth()), static_cast<float>(quitgameHighlighted.getHeight())};
		accessibilityBounds = {middle_x + 825, middle_y + 150, static_cast<float>(accessibility.getWidth()), static_cast<float>(accessibility.getHeight())};
		accessibilityHighlightedBounds = {middle_x + 825, middle_y + 150, static_cast<float>(accessibilityHighlighted.getWidth()), static_cast<float>(accessibilityHighlighted.getHeight())};
	}

	static float timer = 0;
	timer += 0.05f;
	static float defaultSizeSplashTextWidth = SplashText.getWidth();
	static float defaultSizeSplashTextHeight = SplashText.getHeight();

	if (timer > 0.0f && timer < 1.0f)
	{
		SplashText.setHeight(SplashText.getHeight() + 1);
		SplashText.setWidth(SplashText.getWidth() + 1);
	}

	if (timer > 1.0f && timer < 2.0f)
	{
		SplashText.setHeight(SplashText.getHeight() - 1);
		SplashText.setWidth(SplashText.getWidth() - 1);
	}

	if (timer > 2.0f)
	{
		SplashText.setHeight(defaultSizeSplashTextHeight);
		SplashText.setWidth(defaultSizeSplashTextWidth);
		timer = 0;
	}

	if (CheckCollisionPointRec(mousePoint, playBounds))
	{
		playHighlighted.Draw(middle_x, middle_y + 50, WHITE);
		if (mouse.isButtonPressed(MOUSE_LEFT_BUTTON))
		{
			buttonSound.Play();
			this->state = PlayMenu;
		}
	}

	if (CheckCollisionPointRec(mousePoint, optionsBounds))
	{
		optionsHighlighted.Draw(middle_x, middle_y + 150, WHITE);
		if (mouse.isButtonPressed(MOUSE_LEFT_BUTTON))
		{
			buttonSound.Play();
			this->state = optionsMenu;
		}
	}

	if (CheckCollisionPointRec(mousePoint, quitgameBounds) || IsKeyPressed(KEY_ESCAPE))
	{
		quitgameHighlighted.Draw(middle_x + 408, middle_y + 150, WHITE);
		if (mouse.isButtonPressed(MOUSE_LEFT_BUTTON))
		{
			buttonSound.Play();
			while (buttonSound.isPlaying())
				;
			closeSound.Play();
			while (closeSound.isPlaying())
				;
			MainMenuMusic.Stop();
	        std::cout << "INFO: EXITING: QUIT GAME BY USER" << std::endl;
			exit(0);
		}
	}

	if (CheckCollisionPointRec(mousePoint, accessibilityBounds))
	{
		accessibilityHighlighted.Draw(middle_x + 825, middle_y + 150, WHITE);
		if (mouse.isButtonPressed(MOUSE_LEFT_BUTTON))
		{
			buttonSound.Play();
			OpenURL("https://bit.ly/3PSsHwZ");
			exit(0);
		}
	}
}