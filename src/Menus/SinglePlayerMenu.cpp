/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** SinglePlayerMenu
*/

#include "indieStudio.hpp"

using namespace bmb;

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

	if (this->screen.GetWidth() != this->_screenHeight || this->screen.GetHeight() != this->_screenWidth) {
        //Calculate the new position of the buttons and the background to keep it centered and completely on the screen
		mainMenuBackground_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
		mainMenuBackground_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
		middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
		middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
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
	if (CheckCollisionPointRec(mousePoint, playButtonBounds)) {
		playButtonHighlighted.Draw(middle_x + 200, middle_y + 850, WHITE);
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			this->state = inGame;
			MainMenuMusic.Stop();
			this->_musicPlayed = MainMenuMusic.getTimePlayed();
		}
	}
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