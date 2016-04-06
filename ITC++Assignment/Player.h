#pragma once
#include "Character.h"
#include "MyString.h"
#include <vector>

class Player : public Character
{
protected:
	std::vector<MyString> inventory;
	int itemLength = 1;

public:
	Player();
	Player(int h, int d);
	~Player();

	bool HasItem(MyString& item);
	void GiveItem(MyString& item);
};

