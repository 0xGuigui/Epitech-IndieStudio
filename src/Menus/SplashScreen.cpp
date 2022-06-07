/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-paul.gervais
** File description:
** SplashScreen
*/

#include "indieStudio.hpp"

using namespace bmb;

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

	SplashScreenImage.setWidth(this->_screenWidth);
	SplashScreenImage.setHeight(this->_screenHeight);
	int x = (this->screen.GetWidth() - SplashScreenImage.getWidth()) / 2;
	int y = (this->screen.GetHeight() - SplashScreenImage.getHeight()) / 2;
	SplashScreenImage.Draw(x, y, WHITE);
	if (!SplashScreenSound.isPlaying())
		DrawRectangle(x + (SplashScreenImage.getWidth() / 2) - (SplashScreenImage.getWidth() / 4), 500 + (SplashScreenImage.getHeight() / 2) - (SplashScreenImage.getHeight() / 4), SplashScreenImage.getWidth() / 2, SplashScreenImage.getHeight() / 32, WHITE);
	else
		DrawRectangle(x + (SplashScreenImage.getWidth() / 2) - (SplashScreenImage.getWidth() / 4), 500 + (SplashScreenImage.getHeight() / 2) - (SplashScreenImage.getHeight() / 4), SplashScreenImage.getWidth() / 2 * this->timePlayed / 5.0f, SplashScreenImage.getHeight() / 32, WHITE);
	//if the window is resized, the splashscreen and the progress bar are resized too and the progress bar need to be always showed
	if (this->screen.GetWidth() != this->_screenWidth || this->screen.GetHeight() != this->_screenHeight) {
		SplashScreenImage.setWidth(this->screen.GetWidth());
		SplashScreenImage.setHeight(this->screen.GetHeight());
		x = (this->screen.GetWidth() - SplashScreenImage.getWidth()) / 2;
		y = (this->screen.GetHeight() - SplashScreenImage.getHeight()) / 2;
		SplashScreenImage.Draw(x, y, WHITE);
		if (!SplashScreenSound.isPlaying())
			DrawRectangle(x + (SplashScreenImage.getWidth() / 2) - (SplashScreenImage.getWidth() / 4), 500 + (SplashScreenImage.getHeight() / 2) - (SplashScreenImage.getHeight() / 4), SplashScreenImage.getWidth() / 2, SplashScreenImage.getHeight() / 32, WHITE);
		else
			DrawRectangle(x + (SplashScreenImage.getWidth() / 2) - (SplashScreenImage.getWidth() / 4), 500 + (SplashScreenImage.getHeight() / 2) - (SplashScreenImage.getHeight() / 4), SplashScreenImage.getWidth() / 2 * this->timePlayed / 5.0f, SplashScreenImage.getHeight() / 32, WHITE);
	}
	if (!SplashScreenSound.isPlaying()) {
		this->state = mainMenu;
        SplashScreenSound.Stop();
	}
}
