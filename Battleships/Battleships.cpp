// Battleships.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <conio.h>
#include <time.h>

#include "CliListMenu.h"
#include "CliGridRenderer.h"

int main()
{
	// Seed rand(). Comment this out to generate ships in the same position each time
	// If this gets called once strange things happen, so make sure not to
	srand(time(NULL));

	Game game = Game(new CliGridRenderer());
	game.SetupCliMenu(); // Setup a CLI based menu 

	// Output some instructions
	std::cout << "Please resize your console window now to a large size." << std::endl;
	std::cout << "On the board, O represent your ships. X is a direct hit on both boards, # is a miss on both boards." << std::endl;
	std::cout << "A ship can sink before all sections have been hit. Similarly, it may take more than one hit to any section to sink the ship." << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "The sea, the great unifier, is man's only hope. Now, as never before, the old phrase has a literal meaning: we are all in the same boat. - Jacques Yves Cousteau" << std::endl << std::endl;
	std::cout << "Once you have resized the window, press enter to start the game." << std::endl;

	// Wait for input
	_getch();

	// Cllear the screen and start
	system("cls");
	game.Start();

    return 0;
}

