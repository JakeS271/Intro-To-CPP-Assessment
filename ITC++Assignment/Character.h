#pragma once
class Character
{
public:
	Character();
	~Character();

	void AttackOpponent(Character enemy);
	void SetHealth(int health);
	int GetHealth();
	void SetDamage(int damage);
	int GetDamage();

protected:
	int m_health;
	int m_damage;
	bool m_isDead = false;
};

