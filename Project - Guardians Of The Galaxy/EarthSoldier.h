#pragma once
#include "ArmyUnit.h"

#include <iostream>

using namespace std;

class EarthSoldier : public ArmyUnit
{
private:
	int InitialHealth;
	int JoinedUMLTime;
public:
	EarthSoldier(int id, int jointime, int health, int power, int attackcapacity,Game*&game);
	EarthSoldier(int id, int jointime, int health, int power, int attackcapacity);
	EarthSoldier();
	int getInitialhealth();
	int getJoinedUMLTime();
	void setJoinedUMLTime(int t);
	void Attack();
};

