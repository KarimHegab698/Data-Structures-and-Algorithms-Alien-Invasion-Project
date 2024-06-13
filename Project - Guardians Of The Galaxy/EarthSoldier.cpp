#include "EarthSoldier.h"
#include "Game.h"
#include <iostream>

using namespace std;

EarthSoldier::EarthSoldier(int id, int jointime, int health, int power, int attackcapacity,Game* &game)
{
	ID = id;
	type = ES;
	JoinTime = jointime;
	if (health > 0 && health <= 100) {
		Health = health ;
		InitialHealth = health;
	}
	else {
		Health = 100;
		InitialHealth = 100;
	}
	Power = power;
	GameManager = game;
	AttackCapacity = attackcapacity;
}

EarthSoldier::EarthSoldier(int id, int jointime, int health, int power, int attackcapacity)
{
	ID = id;
	type = ES;
	JoinTime = jointime;
	if (health > 0 && health <= 100) {
		Health = health;
		InitialHealth = health;
	}
	else {
		Health = 100;
		InitialHealth = 100;
	}
	Power = power;
	AttackCapacity = attackcapacity;
}
EarthSoldier::EarthSoldier()
{
	ID = 0;
	JoinTime = 0;
	type = ES;
	Health = 100;
	Power = 0;
	AttackCapacity = 0;
	InitialHealth = 0;
}

int EarthSoldier::getInitialhealth()
{
	return InitialHealth;
}
int EarthSoldier::getJoinedUMLTime()
{
	return JoinedUMLTime;
}
void EarthSoldier::setJoinedUMLTime(int t)
{
	JoinedUMLTime = t;
}

void EarthSoldier::Attack()
{
	if (GameManager->getAA()->getAScount() <= 0 || AttackCapacity <= 0)
	{
		return;
	}
	Queue<AlienSoldier*>* TempList = new Queue<AlienSoldier*>();
	Queue<AlienSoldier*>* ShotList = new Queue<AlienSoldier*>();
	int killedunits = 0;
	int aliveunits = 0;
	int ShotCount = 0;
	int Damage = 0;
	AlienSoldier* AttackedAS = new AlienSoldier();
	AttackedAS = GameManager->getAA()->PickAS();
	for (int i=0; i<AttackCapacity; i++)
	{
		if (AttackedAS != NULL && GameManager->getAA()->getAScount() > 0)
		{
			GameManager->getAA()->RemoveAS(AttackedAS);
			Damage = (Power * Health / 100) / sqrt(AttackedAS->getHealth());
			AttackedAS->setHealth(AttackedAS->getHealth() - Damage);

			AttackedAS->GotShot();
			if (AttackedAS->GetNumGotShot() == 1) {
				AttackedAS->setFirstShotTime(GameManager->GetTimeStep());
			}

			if (AttackedAS->getHealth() == 0)
			{
				AttackedAS->setDistrucTime(GameManager->GetTimeStep());
				GameManager->addKilled(AttackedAS);
				ShotList->enqueue(AttackedAS);
				killedunits++;
				ShotCount++;
			}
			else if (AttackedAS->getHealth() > 0)
			{
				TempList->enqueue(AttackedAS);
				ShotList->enqueue(AttackedAS);
				aliveunits++;
				ShotCount++;
			}
		}
	}
	if (ShotCount!=0&&GameManager->getSelectedMode()==1)
	{
		cout << u8"👮 " << "ES " << ID << " shots ";
		ShotList->Print2();
		cout << " IDs of all alien units shot by ES " << ID << endl;
	}
	AlienSoldier* AS = new AlienSoldier;
	for (int i = 0; i < aliveunits; i++)
	{
		TempList->dequeue(AS);
		GameManager->AddUnit(AS);
	}
	if (GameManager->getAA()->getASArmy()->isEmpty())
	{
		return;
	}
}
