#include "stdafx.h"
#include "CliGridRenderer.h"
#include <iostream>
#include <iomanip>

CliGridRenderer::CliGridRenderer()
{
	letters[0] = 'A';
	letters[1] = 'B';
	letters[2] = 'C';
	letters[3] = 'D';
	letters[4] = 'E';
	letters[5] = 'F';
	letters[6] = 'G';
	letters[7] = 'H';
	letters[8] = 'I';
	letters[9] = 'J';
	letters[10] = 'K';
}

/**
 * Override the Render method to draw the battleships on the screen  
 */
void CliGridRenderer::RenderGame(battleships::Fleet *fOne, battleships::Fleet *fTwo)
{
	std::cout << std::endl << std::endl;

	// AI board
	for (int x = 0; x < 11; x++)
	{
		// First Column so 
		std::cout << std::setfill('0') << std::setw(2) << x;

		for (int y = 0; y < 11; y++)
		{
			if (x == 0)
			{
				std::cout << " " << letters[y] << "\t";
			}
			else
			{
				if (fTwo->IsShipAtPosition(Coordinates(x, y)))
				{
					std::cout << " O\t";
				}
				else
				{
					std::cout << " ~\t";
				}
			}
		}

		// New line for next row
		std::cout << std::endl;
	}

	// Split the boards
	std::cout << std::endl << std::endl;

	// Player board
	for (int x = 0; x < 11; x++)
	{
		// First Column so 
		std::cout << std::setfill('0') << std::setw(2) << x;

		for (int y = 0; y < 11; y++)
		{
			if (x == 0)
			{
				std::cout << " " << letters[y] << "\t";
			}
			else
			{
				if (fOne->IsShipAtPosition(Coordinates(x, y)))
				{
					std::cout << " O\t";
				}
				else
				{
					std::cout << " ~\t";
				}
			}
		}

		// New line for next row
		std::cout << std::endl;
	}
}
