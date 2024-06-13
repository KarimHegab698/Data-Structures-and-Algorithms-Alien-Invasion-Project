#include "AlienSoldier.h"
#include "Game.h"
#include <iostream>
using namespace std;

AlienSoldier::AlienSoldier(int id, int jointime, int health, int power, int attackcapacity, Game* &game)
{
	ID = id;
	type = AS;
	JoinTime = jointime;
	Health = (health > 0 && health <= 100 ? health : 100);
	Power = power;
	GameManager = game;
	AttackCapacity = attackcapacity;
}

AlienSoldier::AlienSoldier(int id, int jointime, int health, int power, int attackcapacity)
{
	ID = id;
	type = AS;
	JoinTime = jointime;
	Health = (health > 0 && health <= 100 ? health : 100);
	Power = power;
	AttackCapacity = attackcapacity;
}

AlienSoldier::AlienSoldier()
{
	ID = 0;
	type = AS;
	JoinTime = 0;
	Health = 100;
	Power = 0;
	AttackCapacity = 0;
}

void AlienSoldier::Attack()
{
	if (GameManager->getEA()->getEScount() <= 0 || AttackCapacity <= 0)
	{
		return;
	}
	Queue<EarthSoldier*>* TempList = new Queue<EarthSoldier*>();
	Queue<EarthSoldier*>* ShotList = new Queue<EarthSoldier*>();
	int killedunits = 0;
	int aliveunits = 0;
	int ShotCount = 0;
	int Damage = 0;
	EarthSoldier* AttackedES = new EarthSoldier();
	AttackedES = GameManager->getEA()->PickES();
	for (int i = 0; i < AttackCapacity; i++)
	{
		if (AttackedES != NULL && GameManager->getEA()->getEScount() > 0)
		{
			GameManager->getEA()->RemoveES(AttackedES);
			Damage = (Power * Health / 100) / sqrt(AttackedES->getHealth());
			AttackedES->setHealth(AttackedES->getHealth() - Damage);

			AttackedES->GotShot();
			if (AttackedES->GetNumGotShot() == 1) {
				AttackedES->setFirstShotTime(GameManager->GetTimeStep());
			}

			if (AttackedES->getHealth() == 0)
			{
				AttackedES->setDistrucTime(GameManager->GetTimeStep());
				GameManager->addKilled(AttackedES);
				ShotList->enqueue(AttackedES);
				killedunits++;
				ShotCount++;
			}
			else if (AttackedES->getHealth() > 0 && AttackedES->getHealth() < 0.2 * AttackedES->getInitialhealth())
			{
				AttackedES->setJoinedUMLTime(GameManager->GetTimeStep());
				GameManager->addUML_ES(AttackedES);
			}
			else
			{
				TempList->enqueue(AttackedES);
				ShotList->enqueue(AttackedES);
				aliveunits++;
				ShotCount++;
			}
		}
	}
	if (ShotCount != 0 && GameManager->getSelectedMode() == 1)
	{
		cout << u8"🤖 " << "AS" << ID << " shots ";
		ShotList->Print2();
		cout << " IDs of all earth units shot by AS" << ID << endl;
	}
	EarthSoldier* ES = new EarthSoldier;
	for (int i = 0; i < aliveunits; i++)
	{
		TempList->dequeue(ES);
		GameManager->AddUnit(ES);
	}
	if (GameManager->getEA()->getESArmy()->isEmpty())
	{
		return;
	}
}
