#include "Player.h"



Player::Player()
{
	health = 100;
	damage = 20;
}

Player::Player(int h, int d)
{
	health = h;
	damage = d;
}

Player::~Player()
{
}
