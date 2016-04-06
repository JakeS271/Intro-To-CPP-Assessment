#include "Player.h"



Player::Player()
{
	m_MaxHealth = 100;
	m_damage = 20;
}

Player::Player(int h, int d)
{
	m_MaxHealth = h;
	m_damage = d;
}

Player::~Player()
{
}

bool Player::HasItem(MyString& item)
{
	for (int i = 0; i < itemLength; i++)
	{
		if (inventory[i] == item)
		{
			return true;
		}
	}
	return false;
}

void Player::GiveItem(MyString& item)
{
	inventory.push_back(item);
	itemLength++;
}
