#include "Creature.h"



Creature::Creature()
{
	m_MaxHealth = 70;
	m_damage = 25;
}

Creature::Creature(int h, int d)
{
	m_MaxHealth = h;
	m_damage = d;
}

Creature::~Creature()
{
}

void Creature::Enrage()
{
	SetHealth(GetHealth() / 2);
	SetDamage(GetDamage() * 2);
}