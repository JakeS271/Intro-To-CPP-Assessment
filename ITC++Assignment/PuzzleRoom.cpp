#include "PuzzleRoom.h"
#include "Player.h"


PuzzleRoom::PuzzleRoom()
{
	descript.Append("\nYou are in a pitch black room with only a soptlight in the centre.\nIn the spotlight is a computer and its screen poses a question.\nWhat is my name?\n\n");
}


PuzzleRoom::~PuzzleRoom()
{
}

Player::Inventory Player::Inv;

void PuzzleRoom::Update(MyString command)
{
	command.Lowercase();
	if (command.Find("west") != -1 && command.Find("go") != -1)
	{
		Room::location = "startR";
		return;
	}
	else if (command.Find("examine") != -1)
	{
		if (command.Find("door") != -1)
		{
			std::cout << "It's a door.\n\n";
			return;
		}
		else if (command.Find("computer") != -1)
		{
			std::cout << "It's a strange computer only displaying a question.\nWhat is my name?\n\n";
			return;
		}
		else
		{
			std::cout << "Examine what?\n\n";
			return;
		}
	}
	else if (command.Find("harkyn") != -1 && command.Find("enter") != -1 && command.Find("computer") != -1)
	{
		std::cout << "The screen displays another message.\nThat is my name.\nA golden key descends from the light and stops directly infront of the screen.\n\n";
		keyAval = true;
	}
	else if (command.Find("key") != -1 && (command.Find("pick up") != -1 || command.Find("grab") != -1) && keyAval == true)
	{
		std::cout << "You pick up the key and put it in your inventory.\n\n";
		keyAval = false;
		Player::Inv.name = "key";
		Player::Inv.quantity = 1;

	}
	else
	{
		std::cout << "Error! Invalid input\n\n";
	}
}