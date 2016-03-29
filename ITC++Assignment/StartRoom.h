#pragma once
#include "Room.h"
class StartRoom : public Room
{
public:
	StartRoom();
	~StartRoom();

	void Update(MyString command);

protected:
	char c[256];
	bool rugMoved = false, openTrapDoor = false;
	
};

