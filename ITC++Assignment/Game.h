#pragma once
#include "Player.h"
#include "Room.h"
#include "MyString.h"
#include <iostream>
#include "StartRoom.h"
#include "PuzzleRoom.h"
#include "StudyRoom.h"
#include "ExitRoom.h"
#include <vector>

class Game
{
public:
	Game();
	~Game();

	void start();
	MyString UserCommand();

protected:
	const int m_MAX_SIZE = 256;
	bool m_end = false;
	int m_MAX_ROOM = 4;

	StartRoom startR;
	StudyRoom studyR;
	PuzzleRoom puzzleR;
	ExitRoom exitR;
	Room * startP = &startR;
	Room * studyP = &studyR;
	Room * puzzleP = &puzzleR;
	Room * exitP = &exitR;
	struct currentLocation
	{
		MyString roomName;
		Room* roomPointers;
	};

	currentLocation cLocation[m_MAX_ROOM];
};

