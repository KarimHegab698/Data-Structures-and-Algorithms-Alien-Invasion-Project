#include "ArmyUnit.h"
int ArmyUnit::getType() const
{
	return type;
}

int ArmyUnit::getID() const
{
	return ID;
}

int ArmyUnit::getJoinTime() const
{
	return JoinTime;
}

int ArmyUnit::GetDistructTime()
{
	return DistrucTime;
}

int ArmyUnit::GetFirstShotTime()
{
	return FirstShotTime;
}

int ArmyUnit::getHealth() const
{
	return Health;
}

int ArmyUnit::getPower() const
{
	return Power;
}

int ArmyUnit::getAttackCapacity() const
{
	return AttackCapacity;
}


void ArmyUnit::setID(int id)
{
	ID = id;
}

void ArmyUnit::setJoinTime(int jointime)
{
	JoinTime = jointime;
}

void ArmyUnit::setDistrucTime(int DST)
{
	DistrucTime = DST;
}

void ArmyUnit::setFirstShotTime(int FST)
{
	FirstShotTime = FST;
}

void ArmyUnit::GotShot()
{
	NumGotShot++;
}
int ArmyUnit:: GetNumGotShot(){
	return NumGotShot;
}

void ArmyUnit::setHealth(int health)
{
	if (health <= 100 && health >= 0)
	{
		Health = health;
	}
	else if (health < 0)
	{
		Health = 0;
	}
	else
	{
		Health = 100;
	}
}

void ArmyUnit::setPower(int power)
{
	Power = power;
}

void ArmyUnit::setAttackCapacity(int attackcapacity)
{
	AttackCapacity = attackcapacity;
}
