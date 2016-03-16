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
void CliGridRenderer::RenderGame(battleships::Fleet *fOne, battleships::Fleet *fTwo, std::vector<Coordinates> *pOneShots, std::vector<Coordinates> *pTwoShots)
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
				std::cout << " " << letters[y] << "   ";
			}
			else
			{
				// We go y,x because of the order in which the for loops are
				// Or at least that seems to work when we're playing the game, so we're rolling with it
				if (fTwo->IsShipAtPosition(Coordinates(y, x)) && ShotsAtPosition(pOneShots, Coordinates(y,x)))
				{
					// output X if this shot was a hit
					std::cout << " X   ";
				}
				else if(ShotsAtPosition(pOneShots, Coordinates(y, x)))
				{
					// output # if this shot was a miss
					std::cout << " #   ";
				}
				else
				{
					// Output ~ if there hasn't been an attempted shot here - we don't want the player
					// knowing where their enemy's ships are!
					std::cout << " ~   ";
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
		// First Column so output row numbers
		std::cout << std::setfill('0') << std::setw(2) << x;

		for (int y = 0; y < 11; y++)
		{
			// First row so output column letters
			if (x == 0)
			{
				std::cout << " " << letters[y] << "   ";
			}
			else
			{
				if (fOne->IsShipAtPosition(Coordinates(x, y)))
				{
					// If there's a ship here, output a O to indicate it
					std::cout << " O   ";
				}
				else
				{
					// Otherwise output wavy sea lines
					std::cout << " ~   ";
				}
			}
		}

		// New line for next row
		std::cout << std::endl;
	}
}

// Check if shots were fired on the given set of coordinates
bool CliGridRenderer::ShotsAtPosition(std::vector<Coordinates> *shots, Coordinates pos)
{
	bool fired = false;
	for (int i = 0; i < shots->size(); i++)
	{
		if (shots->at(i).GetX() == pos.GetX() && shots->at(i).GetY() == pos.GetY())
		{
			// Only return true if both x and y values match
			fired = true;
		}
	}

	return fired;
}
