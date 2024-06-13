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
	}
	else {
		Health = 100;
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
	}
	else {
		Health = 100;
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
	for (int i=0; i < AttackCapacity; i++)
	{
		if (AttackedAS != NULL && GameManager->getAA()->getAScount() > 0)
		{
			GameManager->getAA()->RemoveAS(AttackedAS);
			Damage = (Power * (Health / 100)) / sqrt(AttackedAS->getHealth());
			AttackedAS->setHealth(AttackedAS->getHealth() - Damage);
			if (AttackedAS->getHealth() == 0)
			{
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
		/*for (int i = 0; i < aliveunits; i++)
		{
			de
		}
		if (GameManager->getAA()->getASArmy()->isEmpty())
		{
			return;
		}
		AttackedAS = GameManager->getAA()->PickAS();*/
	}
	if (ShotCount!=0)
	{
		cout << "ES " << ShotCount << " shots ";
		ShotList->Print2();
	}
}
