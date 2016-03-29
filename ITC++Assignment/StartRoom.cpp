#include "StartRoom.h"
#include <iostream>
#include "Player.h"


StartRoom::StartRoom()
{
	descript.Append("\nYou are in the main foyer of the mansion.\nThere is a door to the EAST and the WEST\nThere is a rug in the middle of the room and paintings line the walls.\n\n");
}


StartRoom::~StartRoom()
{
}

void StartRoom::Update(MyString command)
{
	command.Lowercase();
	if (command.Find("west") != -1 && command.Find("go") != -1)
	{
		Room::location = "studyR";
		return;
	}
	else if (command.Find("east") != -1 && command.Find("go") != -1)
	{
		Room::location = "puzzleR";
		return;
	}
	else if (command.Find("examine") != -1)
	{
		if (command.Find("door") != -1)
		{
			std::cout << "It's a door.\n\n";
			return;
		}
		else if (command.Find("rug") != -1)
		{
			std::cout << "It's a dust free rug. It appears to be moveable\n\n";
			return;
		}
		else if (command.Find("painting") != -1)
		{
			std::cout << "It's a painting of a boat.\n\n";
			return;
		}
		else
		{
			std::cout << "Examine what?\n\n";
			return;
		}
	}
	else if (command.Find("open") != -1 && command.Find("trap door") && rugMoved == true && Player::Inv.quantity == 0)
	{
		std::cout << "It is locked\n\n";
		return;
	}
	else if (command.Find("open") != -1 && command.Find("trap door") && rugMoved == true && Player::Inv.quantity == 1)
	{
		std::cout << "You unlock the trap door with the key.\n\n";
		Player::Inv.quantity = 0;
		openTrapDoor = true;
		return;
	}
	else if (command.Find("trap door") != -1 && command.Find("enter") != -1 && openTrapDoor == true)
	{
		std::cout << "You enter the trap door.\n\n";
		Room::location = "exitR";
		return;
	}
	else if (command.Find("move") != -1 && command.Find("rug") != -1)
	{
		std::cout << "You move the rug to reveal a secret trap door with a locked padlock.\n\n";
		rugMoved = true;
		return;
	}
	else
	{
		std::cout << "Error! Invalid input\n\n";
	}
}
