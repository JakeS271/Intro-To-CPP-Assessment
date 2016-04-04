#include "lockRoom.h"
#include "Player.h"

lockRoom::lockRoom()
{
}


lockRoom::~lockRoom()
{
}

Player::Inventory Player::Inv;

void lockRoom::setRoomItems(MyString iName, MyString description, MyString itemUse, bool locked)
{
	itemList.push_back(roomItems(iName, description, itemUse, locked, 1));
	m_itemCount++;
}

void lockRoom::Update(MyString& command)
{
	command.Lowercase();
	for (int i = 0; i < m_itemCount; i++)
	{
		if (command.Find(itemList[i].itemName) >= 0 && command.Find("examine") >= 0)
		{
			itemList[i].descript.print();
		}

		else if (command.Find(directionList[i].direction) >= 0 && command.Find("go") >= 0)
		{
			if (command.Find("down") != 0)
			{
				location = directionList[i].location;
				return;
			}
		}
		else if (command.Find(itemList[i].itemName) >= 0 && command.Find("use") >= 0 && itemList[i].locked == true && command.Find(itemList[i].itemUse) >= 0 && Player::Inv.quantity == 1)
		{
			for (int index = 0; index < m_directCount; i++)
			{
				if (directionList[index].direction == "down")
				{
					location = directionList[index].location;
				}
			}
			return;
		}
	}

	std::cout << "Error! Invalid input\n\n";

}