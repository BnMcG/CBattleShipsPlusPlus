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
		int column = 0;
		int row = stoi(input.substr(1, input.size() - 1));

		switch (columnChar)
		{
		case 'A':
			column = 1;
			break;
		case 'B':
			column = 2;
			break;
		case 'C':
			column = 3;
			break;
		case 'D':
			column = 4;
			break;
		case 'E':
			column = 5;
			break;
		case 'F':
			column = 6;
			break;
		case 'G':
			column = 7;
			break;
		case 'H':
			column = 8;
			break;
		case 'I':
			column = 9;
			break;
		case 'J':
			column = 10;
			break;
		case 'K':
			column = 11;
			break;
		}

		Coordinates targetCoords = Coordinates(column, row);

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