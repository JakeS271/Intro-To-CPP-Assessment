#pragma once
#include "Room.h"
class endRoom :
	public Room
{
public:
	endRoom();
	~endRoom();

	void Update(MyString& command);

};

