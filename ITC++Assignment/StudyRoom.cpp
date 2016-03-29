#include "StudyRoom.h"



StudyRoom::StudyRoom()
{
	descript.Append("\nYou are in a study.\nThere is a bookcase covered in dust and a desk next to it.\n\n");
}


StudyRoom::~StudyRoom()
{
}

void StudyRoom::Update(MyString command)
{
	command.Lowercase();
	if (command.Find("east") != -1 && command.Find("go") != -1)
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
		else if (command.Find("book") != -1)
		{
			std::cout << "The book seems average except a name it worn away except the last half.\nKYN\n\n";
		}
		else if (command.Find("bookcase") != -1)
		{
			std::cout << "It's a dusty bookcase. However, it appears that one of the books isnt dusty at all.\n\n";
			return;
		}
		else if (command.Find("desk") != -1 && lampOn == true)
		{
			std::cout << "The desk has a letter on it with the name smudged.\nOnly the first half is clear.\nHAR\n\n";
			return;
		}
		else if (command.Find("desk") != -1)
		{
			std::cout << "The desk has a lamp next to it and the desk itself is too dark to examine.\n\n";
			return;
		}
		else
		{
			std::cout << "Examine what?\n\n";
			return;
		}
	}
	else if (command.Find("lamp") != -1 && command.Find("on") != -1)
	{
		std::cout << "You turn the lamp on and the desk is now illuminated.\n\n";
		lampOn = true;
	}
	else
	{
		std::cout << "Error! Invalid input\n\n";
	}
}