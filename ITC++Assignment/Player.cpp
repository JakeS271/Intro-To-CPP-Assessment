#include "Player.h"



Player::Player()
{
	m_health = 100;
	m_damage = 20;
}

Player::Player(int h, int d)
{
	m_health = h;
	m_damage = d;
}

Player::~Player()
{
}
