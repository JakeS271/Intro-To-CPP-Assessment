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
