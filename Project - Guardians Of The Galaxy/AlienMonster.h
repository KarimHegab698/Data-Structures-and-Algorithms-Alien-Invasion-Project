#pragma once
#include "ArmyUnit.h"
class AlienMonster : public ArmyUnit
{
public:
	AlienMonster();
	AlienMonster(int ID, int JoinTime, int Health, int Power, int AttackCapacity, Game*& game);
	void Attack();
};

