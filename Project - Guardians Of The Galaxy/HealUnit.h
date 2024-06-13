#pragma once
#include "ArmyUnit.h"
#include <iostream>

class HealUnit : public ArmyUnit
{
	bool die=false;
public:
	HealUnit();
	HealUnit(int id, int jointime, int health, int power, int attackcapacity, Game*& game);
	void setdie(bool why);
	bool getdie();
	void Attack();
};

