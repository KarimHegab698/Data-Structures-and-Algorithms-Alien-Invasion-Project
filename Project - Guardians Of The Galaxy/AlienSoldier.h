#pragma once
#include "ArmyUnit.h"
#include <iostream>
class AlienSoldier : public ArmyUnit
{
public:
	AlienSoldier(int id, int jointime, int health, int power, int attackcapacity, Game* &game);
	AlienSoldier(int id, int jointime, int health, int power, int attackcapacity);
	AlienSoldier();
	void Attack();
};

