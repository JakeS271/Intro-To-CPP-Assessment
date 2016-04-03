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
	MyString intro("\nWelcome to The Mansion.\nYou are trapped inside and must find a way out.\nWatch out though as you might not be alone in there."), command;
	intro.print();
	//delete[] &intro;
	Player player;

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
		if (Room::location == "startR")
		{
			m_startR.roomDescrip("\nYou are in the main foyer of the mansion.\nThere is a door to the EAST and the WEST\nThere is a locked trap door in the middle of the room and paintings line the walls.\n\n");
			m_startR.setDirections("west", "studyR");
			m_startR.setDirections("east", "puzzleR");
			m_startR.setRoomItems("painting", "It's a painting of a boat.\n\n", " ", false);
			m_startR.setRoomItems("trap door", "It's locked.\n\n", "key", true);
		}
		if (Room::location == "studyR")
		{
			m_studyR.roomDescrip("\nYou are in a study.\nThere is a bookcase covered in dust and a desk next to it.\n\n");
			m_studyR.setDirections("east", "startR");
			m_studyR.setRoomItems("desk", "The desk has a letter on it with the name smudged.\nOnly the first half is clear.\nHAR\n\n", false);
			m_studyR.setRoomItems("bookcase", "It's a dusty bookcase.Their is a book that seems average except a name it worn away except the last half.\nKYN\n\n", false);
		}
		if (Room::location == "puzzleR")
		{
			m_puzzleR.roomDescrip("\nYou are in a pitch black room with only a spotlight in the centre.\nIn the spotlight is a computer and its screen poses a question.\nWhat is my name?\n\n");
			m_puzzleR.setDirections("west", "startR");
			m_puzzleR.setRoomItems("computer", "It's a strange computer only displaying a question.\nWhat is my name?\n\n", false, false);
			m_puzzleR.setAnswer("harkyn", "key", "THAT IS MY NAME\nA key descends from the light above.\nYou pick it up and place it in your inventory.\n\n");
		}
		if (Room::location == "exitR")
		{
			m_exitR.roomDescrip("\nYou are in a tunnel that leads out of the mansion.\n Congratulations you have escaped.\n\n");
			m_end = true;
		}
	}
	system("PAUSE");
}

void Game::Location()
{
	for (int i = 0; i < m_TOTAL_ROOM; i++)
	{
		if (Room::location.Compare(cLocation[i].roomName) == 0)
		{
			cLocation[i].roomPointers->descriptPrint();
			while (Room::location.Compare(cLocation[i].roomName) == 0)
			{
				cLocation[i].roomPointers->Update(UserCommand());
			}	
		}
	}
}
