#pragma once
#include "Room.h"
class StudyRoom :
	public Room
{
public:
	StudyRoom();
	~StudyRoom();

	void Update(MyString command);

protected:
	bool lampOn = false;
};

