#pragma once
#include "ArmyUnit.h"
#include <iostream>
class AlienDrone: public ArmyUnit
{
public:
	AlienDrone();
	AlienDrone(int id, int jointime, int health, int power, int attackcapacity, Game*& game);
	void Attack();
};