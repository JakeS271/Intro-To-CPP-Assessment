#include "Game.h"
#include "Player.h"
#include "Room.h"
#include "MyString.h"
#include <iostream>
#include "StartRoom.h"
#include "PuzzleRoom.h"
#include "StudyRoom.h"
#include "ExitRoom.h"
#include <vector>

Game::Game()
{
}


Game::~Game()
{
}

MyString Room::location;

MyString Game::UserCommand()
{
	std::cout << "What shall we do?\n";
	char command[256];
	std::cin.getline(command, m_MAX_SIZE);
	
	return MyString(command);
}

void Game::start()
{
	MyString intro("\nWelcome to The Mansion.\nYou are trapped inside and must find a way out.\nWatch out though as you might not be alone in there."), command;
	intro.print();
	Player player;
	
	cLocation[0].roomName = "startR";
	cLocation[0].roomPointers = startP;
	cLocation[1].roomName = "studyR";
	cLocation[1].roomPointers = studyP;
	cLocation[2].roomName = "puzzleR";
	cLocation[2].roomPointers = puzzleP;
	cLocation[3].roomName = "exitR";
	cLocation[3].roomPointers = exitP;

	Room::location = "startR";
	while (m_end != true)
	{
		if (Room::location == "startR")
		{
			startP->roomDescrip();
			command = UserCommand();
			startP->Update(command);
		}
		else if (Room::location == "studyR")
		{
			studyP->roomDescrip();
			command = UserCommand();
			studyP->Update(command);
		}
		else if (Room::location == "puzzleR")
		{
			puzzleP->roomDescrip();
			command = UserCommand();
			puzzleP->Update(command);
		}
		else if (Room::location == "exitR")
		{
			exitP->roomDescrip();
			command = UserCommand();
			exitP->Update(command);
		}
	}
	system("PAUSE");
}

void Location()
{
	for (int i = 0; i < 4; i++)
	{
		if (Room::location == cLocation[i].roomName)
		{

		}
	}
}
