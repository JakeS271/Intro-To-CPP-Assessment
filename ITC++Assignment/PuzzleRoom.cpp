#include "puzzleRoom.h"
#include "Player.h"


puzzleRoom::puzzleRoom()
{
}


puzzleRoom::~puzzleRoom()
{
}

//Player::Inventory Player::Inv;

void puzzleRoom::puzzleAnswer(MyString& command)
{
	for (int i = 0; i < m_itemCount; i++)
	{
		if (command.Find(pItems[i].password))
		{
			pItems[i].output.print();
			Player::Inv.name = pItems[i].item;
			Player::Inv.quantity = 1;
		}
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
		if (command.Find(itemList[i].itemName) && command.Find("examine"))
		{
			itemList[i].descript.print();
			return;
		}

		else if (command.Find(directionList[i].direction) && command.Find("go"))
		{
			location = directionList[i].location;
			return;
		}
		puzzleAnswer(command);
	}

	std::cout << "Error! Invalid input\n\n";

}