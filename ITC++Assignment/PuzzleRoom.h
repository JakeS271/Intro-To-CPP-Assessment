#pragma once
#include "Room.h"
class PuzzleRoom :
	public Room
{
public:
	PuzzleRoom();
	~PuzzleRoom();

	void Update(MyString command);

protected:
	bool keyAval = false;
};

