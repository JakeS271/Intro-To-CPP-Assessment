#pragma once
#include "Character.h"
#include "MyString.h"

class Player : public Character
{
protected:
	struct Inventory
	{
		MyString name;
		int quantity;
	};

public:
	Player();
	Player(int h, int d);
	~Player();
	static Inventory Inv;	
};

