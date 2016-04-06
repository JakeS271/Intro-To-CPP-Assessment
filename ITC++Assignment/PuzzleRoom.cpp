#include "puzzleRoom.h"
#include "Player.h"


puzzleRoom::puzzleRoom()
{
}


puzzleRoom::~puzzleRoom()
{
}

//static Player player;

void puzzleRoom::puzzleAnswer(MyString& command)
{
	if (command.Find(pItems[0].password) >= 0)
	{
		pItems[0].output.print();
		GiveItem("key");
	}
}

void puzzleRoom::setAnswer(MyString answer, MyString item, MyString Output)
{
	pItems.push_back(passwordItem(answer, item, Output));
	m_itemCount++;
}

void puzzleRoom::Update(MyString& command)
{
	command.Lowercase();
	for (int i = 0; i < m_itemCount; i++)
	{
		if (command.Find(itemList[i].itemName) >= 0 && command.Find("examine") >= 0)
		{
			itemList[i].descript.print();
			return;
		}

		else if (command.Find(directionList[i].direction) >= 0 && command.Find("go") >= 0)
		{
			location = directionList[i].location;
			return;
		}
		else
		{
			puzzleAnswer(command);
			return;
		}
	}

	std::cout << "Error! Invalid input\n\n";

}