#pragma once
#include "Character.h"
#include "MyString.h"
#include <vector>

class Player : public Character
{
protected:
	int maxSpace = 5;

	struct Inventory
	{
		MyString name;
		int quantity;

		Inventory(MyString n, int q) : name(n), quantity(q) {}
	};

public:
	Player();
	Player(int h, int d);
	~Player();

	static Inventory Inv[1];
};

