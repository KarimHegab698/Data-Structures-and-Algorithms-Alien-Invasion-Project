#pragma once
#include "ArmyUnit.h"
class EarthGunnery : public ArmyUnit
{
protected:
	int power_health_combination;
public:
	EarthGunnery(int ID, int JoinTime, int Health, int Power, int AttackCapacity, Game*& game);
	EarthGunnery();
	void Attack();
	void setpower_health_combination(int combination);
	int getpower_health_combination() const;
};

