#pragma once
#include "ArmyUnit.h"

class EarthTank : public ArmyUnit
{
private:
	int InitiaHealth;
	int JoinedUMLTime;
public:
	EarthTank(int id, int jointime, int health, int power, int attackcapacity, Game*& game);
	EarthTank();
	int getInitialhealth() ;
	int getJoinedUMLTime();
	void setJoinedUMLTime(int t);
	void Attack();
};

