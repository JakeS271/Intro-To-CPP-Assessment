#pragma once
#include "Character.h"
#include "MyString.h"
#include <vector>

class Player : public Character
{
protected:
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

	void AddToInventory(MyString name, int quantity);

	static std::vector<Inventory> Inv;	
};

