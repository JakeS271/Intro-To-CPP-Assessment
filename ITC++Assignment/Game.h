#pragma once
#include "Room.h"
#include "MyString.h"
#include "lockRoom.h"
#include "puzzleRoom.h"
#include "endRoom.h"

class Game
{
public:
	Game();
	~Game();

	void start();
	MyString UserCommand();
	void Location();

protected:
	const int m_MAX_SIZE = 256;
	bool m_end = false;

	Room m_studyR;
	endRoom m_exitR;
	lockRoom m_startR;
	puzzleRoom m_puzzleR;

	Room * m_startP = &m_startR;
	Room * m_studyP = &m_studyR;
	Room * m_puzzleP = &m_puzzleR;
	Room * m_exitP = &m_exitR;

	struct currentLocation
	{
		MyString roomName;
		Room* roomPointers;
	};

	const int m_TOTAL_ROOM = 4;
	currentLocation cLocation[4];
};

