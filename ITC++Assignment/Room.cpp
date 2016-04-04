#include "Room.h"


Room::Room()
{
}


Room::~Room()
{
}

void Room::descriptPrint()
{
	m_roomDescript.print();
}

void Room::roomDescrip(MyString descript)
{
	m_roomDescript = descript;
}

void Room::Update(MyString& command)
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
	}

	std::cout << "Error! Invalid input\n\n";

}

void Room::setDirections(MyString direction, MyString location)
{
	directionList.push_back(roomDirections(direction, location));
}

void Room::setRoomItems(MyString iName, MyString description, bool pUAble)
{
	itemList.push_back(roomItems(iName, description, pUAble, 1));
	m_itemCount++;
}