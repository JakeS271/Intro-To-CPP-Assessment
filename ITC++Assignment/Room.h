#pragma once

#include "MyString.h"
#include <vector>
#include <iostream>

class Room
{
public:
	Room();
	~Room();

	void descriptPrint();
	void roomDescrip(MyString descript);
	virtual void Update(MyString& command);
	void setDirections(MyString direction, MyString location);
	virtual void setRoomItems(MyString iName, MyString description, bool pUAble);

	static MyString location;

protected:
	MyString m_roomDescript;
	char m_chars;

	struct roomItems
	{
		MyString itemName;
		MyString descript;
		bool pickUpable;
		int quantity;

		roomItems(MyString i, MyString d, bool p, int q) : itemName(i), descript(d), pickUpable(p), quantity(q) {}
	};

	struct roomDirections
	{
		MyString direction;
		MyString location;

		roomDirections(MyString d, MyString l) : direction(d), location(l) {}
	};

	int m_itemCount = 0, m_directCount = 0;
	std::vector<roomItems> itemList;
	std::vector<roomDirections> directionList;
};

