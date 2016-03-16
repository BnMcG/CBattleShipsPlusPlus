#include "stdafx.h"
#include "CliListMenu.h"
#include "Coordinates.h"

#include <iostream>

using namespace std;

CliListMenu::CliListMenu(battleships::Fleet *pOne, battleships::Fleet *pTwo, std::vector<Coordinates> *pOneShots, std::vector<Coordinates> *pTwoShots)
{
	this->playerOneFleet = pOne;
	this->playerTwoFleet = pTwo;
	this->playerOneShots = pOneShots;
	this->playerTwoShots = pTwoShots;
}

CliListMenu::~CliListMenu()
{
}

void CliListMenu::RenderMenu()
{
	cout << "Please select an option: " << endl << endl
		<< "1. Enter grid reference to fire upon" << endl
		<< "2. Exit game" << endl
		<< endl << "menu> ";

	string input = "";
	cin >> input;

	ProcessInput(input);
}

void CliListMenu::ProcessInput(string input)
{
	if (input == "1")
	{
		// Ask for grid reference
		string input = "";
		cout << "Enter grid reference (letter first): ";
		cin >> input;

		// Decode grid reference
		char columnChar = input[0];
		int x = 0;
		int y = stoi(input.substr(1, input.size() - 1));

		switch (columnChar)
		{
		case 'A':
			x = 0;
			break;
		case 'B':
			x = 1;
			break;
		case 'C':
			x = 2;
			break;
		case 'D':
			x = 3;
			break;
		case 'E':
			x = 4;
			break;
		case 'F':
			x = 5;
			break;
		case 'G':
			x = 6;
			break;
		case 'H':
			x = 7;
			break;
		case 'I':
			x = 8;
			break;
		case 'J':
			x = 9;
			break;
		case 'K':
			x = 10;
			break;
		}

		Coordinates targetCoords = Coordinates(x, y);

		// Did we hit anything?
		if (this->playerTwoFleet->IsShipAtPosition(targetCoords)) 
		{
			// Yes
			cout << "Hit!" << endl;
		}
		else
		{
			// No
			cout << "Miss!" << endl;
		}

		playerOneShots->push_back(targetCoords);

	}

	if (input == "2")
	{
		this->exit = true;
	}
}