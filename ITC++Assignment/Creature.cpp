#include "Creature.h"



Creature::Creature()
{
	health = 50;
	damage = 25;
}

Creature::Creature(int h, int d)
{
	health = h;
	damage = d;
}

Creature::~Creature()
{
}
