#pragma once
#include "Room.h"
class ExitRoom :
	public Room
{
public:
	ExitRoom();
	~ExitRoom();

	void Update(MyString command);
};

