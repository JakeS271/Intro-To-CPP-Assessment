#pragma once
#include "Character.h"
class Creature : public Character
{
public:
	Creature();
	Creature(int h, int d);
	~Creature();

	void Enrage();
};

