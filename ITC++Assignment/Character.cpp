#include "Character.h"



Character::Character()
{
}


Character::~Character()
{
}

void Character::AttackOpponent(Character enemy)
{
	if ((enemy.GetHealth() - m_damage) <= 0)
	{
		enemy.m_isDead = true;
	}
	else
	{
		enemy.SetHealth(enemy.GetHealth() - m_damage);
	}
}

void Character::SetHealth(int health)
{
	m_health = health;
}

int Character::GetHealth()
{
	return m_health;
}

void Character::SetDamage(int damage)
{
	m_damage = damage;
}

int Character::GetDamage()
{
	return m_damage;
}