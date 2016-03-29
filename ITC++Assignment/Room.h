#pragma once

#include "MyString.h"
#include <vector>
#include <iostream>

class Room
{
public:
	Room();
	~Room();
	void roomDescrip();

	static MyString location;
	virtual void Update(MyString command);

protected:
	MyString descript;
	char m_chars;
	bool leaveArea = false;
};

