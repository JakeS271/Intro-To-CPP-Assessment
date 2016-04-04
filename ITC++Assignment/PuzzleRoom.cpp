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

			player AddToInventory(pItems[i].item, 1);

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
		if (command.Find(itemList[i].itemName) >= 0 && command.Find("examine") >= 0)
		{
			itemList[i].descript.print();
			return;
		}

		else if (command.Find(directionList[i].direction) >= 0 && command.Find("go")>= 0)
		{
			location = directionList[i].location;
			return;
		}
		puzzleAnswer(command);
	}

	std::cout << "Error! Invalid input\n\n";

}