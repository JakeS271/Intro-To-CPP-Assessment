#pragma once
#include "Room.h"
class lockRoom : public Room
{
public:
	lockRoom();
	~lockRoom();

	void setRoomItems(MyString iName, MyString description, MyString itemUse, bool locked);
	virtual void Update(MyString& command);

protected:
	struct roomItems
	{
		MyString itemName;
		MyString descript;
		MyString itemUse;
		bool locked;
		int quantity;

		roomItems(MyString i, MyString d, MyString u, bool lock, int q) : itemName(i), descript(d), itemUse(u), locked(lock), quantity(q) {}
	};
	int m_itemCount = 0;
	std::vector<roomItems> itemList;
};

