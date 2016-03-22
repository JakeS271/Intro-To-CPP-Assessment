#include "Game.h"
#include "Player.h"
#include "Room.h"
#include "MyString.h"
#include <iostream>
#include "StartRoom.h"

Game::Game()
{
	Player player;
}


Game::~Game()
{
}

void Game::start()
{
	intro.print();
	StartRoom sR;
	while (true)
	{
		std::cout << "What shall we do?\n";
		char c[256];
		std::cin.getline(c, MAX_SIZE);
		MyString command = c;
		sR.Update(command);
	}
	system("PAUSE");
}
