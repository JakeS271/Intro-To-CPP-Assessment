#include "Creature.h"



Creature::Creature()
{
	m_health = 100;
	m_damage = 25;
}

Creature::Creature(int h, int d)
{
	m_health = h;
	m_damage = d;
}

Creature::~Creature()
{
}
