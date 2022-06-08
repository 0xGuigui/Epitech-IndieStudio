/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** SinglePlayerMenu
*/

#include "indieStudio.hpp"

using namespace bmb;

void Indie::displaySinglePlayerMenu(float musicTime) {
	static IndieTexture2D mainMenuBackground = loader.textures["background_options"];
	static IndieTexture2D playButton = loader.textures["play"];
	static IndieTexture2D playButtonHighlighted = loader.textures["play_highlight"];
	static IndieTexture2D cancelButton = loader.textures["cancel"];
	static IndieTexture2D cancelButtonHighlighted = loader.textures["cancel_highlight"];
	static IndieSound buttonSound = loader.sounds["button"];
    static IndieSound closeSound = loader.sounds["close"];
    static IndieMusic MainMenuMusic = loader.musics["Moog-City"];
	static float frameHeightPlayButton = (float)playButton.getHeight()/3;
	static float frameHeightCancelButton = (float)cancelButton.getHeight()/3;
	Vector2 mousePoint = GetMousePosition();

	static float musicPlayed = this->_musicPlayed;
	static bool isPlaying = false;
    MainMenuMusic.setLoop(true);
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

	static float middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
	static float middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
	static float mainMenuBackground_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
    static float mainMenuBackground_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;

	//display the model on the middle of the screen
	mainMenuBackground.Draw(mainMenuBackground_x, mainMenuBackground_y, WHITE);
	playButton.Draw(middle_x + 200, middle_y + 850, WHITE);
	cancelButton.Draw(middle_x + 1100, middle_y + 850, WHITE);

	static Rectangle playButtonBounds = { middle_x + 200, middle_y + 850, static_cast<float>(playButton.getWidth()), static_cast<float>(playButton.getHeight()) };
	static Rectangle playButtonHighlightedBounds = { middle_x + 200, middle_y + 850, static_cast<float>(playButtonHighlighted.getWidth()), static_cast<float>(playButtonHighlighted.getHeight()) };
	static Rectangle cancelButtonBounds = { middle_x + 1100, middle_y + 850, static_cast<float>(cancelButton.getWidth()), static_cast<float>(cancelButton.getHeight()) };
	static Rectangle cancelButtonHighlightedBounds = { middle_x + 1100, middle_y + 850, static_cast<float>(cancelButtonHighlighted.getWidth()), static_cast<float>(cancelButtonHighlighted.getHeight()) };

    if (this->screen.GetWidth() != this->screenHeight || this->screen.GetHeight() != this->screenWidth) {
        //Calculate the new position of the buttons and the background to keep it centered and completely on the screen
        // Apdapt the entire menu if the window is resized, like a image whose size is not the same as the screen, same for the buttons
        if (this->screen.GetWidth() != 1920 || this->screen.GetHeight() != 1080) {
            middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
            middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
            if (this->screen.GetWidth() < 1920)
                DrawText("The window is resized, \nthe game can have a bad experience", middle_x + 250, middle_y + 200,
                         50, RED);
            mainMenuBackground_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
            mainMenuBackground_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
            playButtonBounds = {middle_x + 200, middle_y + 850, static_cast<float>(playButton.getWidth()),
                                static_cast<float>(playButton.getHeight())};
            playButtonHighlightedBounds = {middle_x + 200, middle_y + 850,
                                           static_cast<float>(playButtonHighlighted.getWidth()),
                                           static_cast<float>(playButtonHighlighted.getHeight())};
            cancelButtonBounds = {middle_x + 1100, middle_y + 850, static_cast<float>(cancelButton.getWidth()),
                                  static_cast<float>(cancelButton.getHeight())};
            cancelButtonHighlightedBounds = {middle_x + 1100, middle_y + 850,
                                             static_cast<float>(cancelButtonHighlighted.getWidth()),
                                             static_cast<float>(cancelButtonHighlighted.getHeight())};
        } else {
            middle_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
            middle_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
            mainMenuBackground_x = (this->screen.GetWidth() - mainMenuBackground.getWidth()) / 2;
            mainMenuBackground_y = (this->screen.GetHeight() - mainMenuBackground.getHeight()) / 2;
            playButtonBounds = {middle_x + 200, middle_y + 850, static_cast<float>(playButton.getWidth()),
                                static_cast<float>(playButton.getHeight())};
            playButtonHighlightedBounds = {middle_x + 200, middle_y + 850,
                                           static_cast<float>(playButtonHighlighted.getWidth()),
                                           static_cast<float>(playButtonHighlighted.getHeight())};
            cancelButtonBounds = {middle_x + 1100, middle_y + 850, static_cast<float>(cancelButton.getWidth()),
                                  static_cast<float>(cancelButton.getHeight())};
            cancelButtonHighlightedBounds = {middle_x + 1100, middle_y + 850,
                                             static_cast<float>(cancelButtonHighlighted.getWidth()),
                                             static_cast<float>(cancelButtonHighlighted.getHeight())};
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
                this->state = mainMenu;
                MainMenuMusic.Stop();
            }
        }
    }
}
