#include "stdafx.h"
#include "Menu.h"


Menu::Menu()
{
	this->exit = false;
}


Menu::~Menu()
{
}

bool Menu::GameShouldExit()
{
	return exit;
}