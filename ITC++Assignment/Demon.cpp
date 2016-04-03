#include "Demon.h"
#include <time.h>
#include <stdlib.h>
#include "Player.h"

Demon::Demon()
{
	srand(time(NULL));
}


Demon::~Demon()
{
}

void Demon::kamikaze()
{
	int kChance = rand() % 10 + 1;
	if (kChance <= 2)
	{
		//AttackOpponent(pl)
	}
}