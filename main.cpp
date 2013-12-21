/* This code is compiled using Microsoft Visual C++ Express Edition 2010*/


#include <SFML\Graphics.hpp>
#include "Screens.h"
#include "Game.h"
#include "Menu.h"
#include "Splash.h"
int main()
{
	VideoMode vMode(800,600,32);
	RenderWindow win(vMode, "The Legend of Lingerstone");
	win.SetFramerateLimit(120);
	win.UseVerticalSync(false);

	int currentScreen = 0;
	
	//Main Menu
	Menu menu;

	//Game
	Game game;

	//Splash Screen
	Splash splash;
	

	while(currentScreen >= 0)
	{
		if (currentScreen == 0)
		{
			currentScreen = splash.Run(win, vMode);
			
		}
		if(currentScreen == 2)
		{
//			Menu menu;
			currentScreen = menu.Run(win, vMode);
		}

		if(currentScreen == 1)
		{
			currentScreen = game.Run(win, vMode);
		}

	}

	return EXIT_SUCCESS;

	
}