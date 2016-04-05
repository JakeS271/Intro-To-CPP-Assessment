#include "Game.h"
#include "Player.h"
#include "Room.h"
#include "MyString.h"
#include <iostream>

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
	MyString intro("\nWelcome to The Mansion.\nYou are trapped inside and must find a way out.\n\n"), command;
	intro.print();
	Player player;

	Room m_studyR;
	endRoom m_exitR;
	lockRoom m_startR;
	puzzleRoom m_puzzleR;

	Room * m_startP = &m_startR;
	Room * m_studyP = &m_studyR;
	Room * m_puzzleP = &m_puzzleR;
	Room * m_exitP = &m_exitR;

	m_startR.roomDescrip("You are in the main foyer with a door to the EAST and the WEST\nThere is a locked trap door and paintings on the walls.\n\n");
	m_startR.setDirections("west", "studyR");
	m_startR.setDirections("east", "puzzleR");
	m_startR.setRoomItems("painting", "It's a painting of a boat.\n\n", " ", false);
	m_startR.setRoomItems("trap door", "It's locked.\n\n", "key", true);

	m_studyR.roomDescrip("You are in a study.\nThere is a bookcase covered in dust and a desk next to it.\n\n");
	m_studyR.setDirections("east", "startR");
	m_studyR.setRoomItems("desk", "The desk has a letter on it with the name smudged.\nOnly the first half is clear.\nHAR\n\n", false);
	m_studyR.setRoomItems("bookcase", "Their is a book that seems average except a name it worn away except the last half.\nKYN\n\n", false);

	m_puzzleR.roomDescrip("You are in a black room with only a computer which poses a question.\nWhat is my name?\n\n");
	m_puzzleR.setDirections("west", "startR");
	m_puzzleR.setRoomItems("computer", "It's a strange computer only displaying a question.\nWhat is my name?\n\n", "", false);
	m_puzzleR.setAnswer("harkyn", "key", "THAT IS MY NAME\nA key descends from the light above and you pick it up.\n\n");

	m_exitR.roomDescrip("You are in a tunnel that leads out of the mansion.\n\n");

	cLocation[0].roomName = "startR";
	cLocation[0].roomPointers = m_startP;
	cLocation[1].roomName = "studyR";
	cLocation[1].roomPointers = m_studyP;
	cLocation[2].roomName = "puzzleR";
	cLocation[2].roomPointers = m_puzzleP;
	cLocation[3].roomName = "exitR";
	cLocation[3].roomPointers = m_exitP;

	Room::location = "startR";
	while (m_end != true)
	{
		m_end = true;
		Location();
	}

	std::cout << "Congratulations!\nYou have beat the game.\n";

	system("PAUSE");
}

void Game::Location()
{
	for (int i = 0; i < m_TOTAL_ROOM; i++)
	{
		if (cLocation[i].roomName == Room::location)
		{
			cLocation[i].roomPointers->descriptPrint();
			cLocation[i].roomPointers->Update(UserCommand());
			break;
		}
	}
}
