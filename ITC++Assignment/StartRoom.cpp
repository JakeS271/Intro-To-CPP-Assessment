#include "StartRoom.h"
#include <iostream>


StartRoom::StartRoom()
{
	descript.Append("You are in the main foyer of the mansion.\nThere is a door to the EAST and the WEST\nThere is a rug in the middle of the room and landscape painting coat the walls on all sides.\n");
	descript.print();
}


StartRoom::~StartRoom()
{
}

void StartRoom::Update(MyString command)
{
	if (command.Find("West") != -1)
	{
		std::cout << "FOUND!\n";
	}
	if (command.Find("East") != -1)
	{
		std::cout << "FOUND!\n";
	}
	else
	{
		std::cout << "Error! Invalid input\n";
	}
}
