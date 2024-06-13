#include "EarthTank.h"
#include "Game.h"
#include <iostream>

using namespace std;

EarthTank::EarthTank(int id, int jointime, int health, int power, int attackcapacity, Game*& game)
{
	ID = id;
	type = ET;
	JoinTime = jointime;
	Health = (health > 0 && health <= 100 ? health : 100);
	Power = power;
	GameManager = game;
	AttackCapacity = attackcapacity;
	InitiaHealth= (health > 0 && health <= 100 ? health : 100);
}
EarthTank::EarthTank()
{
	ID = 0;
	JoinTime = 0;
	type = ET;
	Health = 100;
	Power = 0;
	AttackCapacity = 0;
	InitiaHealth = 0;
}

int EarthTank::getInitialhealth()
{
	return InitiaHealth;
}
int EarthTank::getJoinedUMLTime()
{
	return JoinedUMLTime;
}
void EarthTank::setJoinedUMLTime(int t)
{
	JoinedUMLTime = t;
}

void EarthTank::Attack()
{
	int killedunits = 0;
	int aliveunits = 0;
	int ShotID = 0;
	int ShotCount = 0;
	int Damage = 0;
	Queue<ArmyUnit*>* TempList = new Queue<ArmyUnit*>;
	Queue<int>* ShotList = new Queue<int>;
	AlienSoldier* AttackedAS = new AlienSoldier();
	AlienMonster* AttackedAM = new AlienMonster();
	if (GameManager->getEA()->getEScount() < 0.3 * GameManager->getAA()->getAScount())
	{
		for (int i = 0; i < AttackCapacity; i++)
		{
			AttackedAS = GameManager->getAA()->PickAS();
			if (((GameManager->getEA()->getEScount()) < int((0.8 * GameManager->getAA()->getAScount()))) && (AttackedAS != NULL) && (GameManager->getAA()->getAScount() > 0))
			{
				GameManager->getAA()->RemoveAS(AttackedAS);
				Damage = (Power * Health / 100) /sqrt(AttackedAS->getHealth());
				AttackedAS->setHealth(AttackedAS->getHealth() - Damage);

				AttackedAS->GotShot();
				if (AttackedAS->GetNumGotShot() == 1) {
					AttackedAS->setFirstShotTime(GameManager->GetTimeStep());
				}

				if (AttackedAS->getHealth() == 0)
				{
					AttackedAS->setDistrucTime(GameManager->GetTimeStep());
					GameManager->addKilled(AttackedAS);
					ShotID = AttackedAS->getID();
					ShotList->enqueue(ShotID);
					killedunits++;
					ShotCount++;
				}
				else if (AttackedAS->getHealth() > 0)
				{
					ArmyUnit* AU = AttackedAS;
					ShotID = AttackedAS->getID();
					TempList->enqueue(AU);
					ShotList->enqueue(ShotID);
					aliveunits++;
					ShotCount++;
				}
			}
		}
	}
	int RemAttackCapacity = AttackCapacity - ShotCount;
	if (RemAttackCapacity != 0 && GameManager->getAA()->getAMcount() > 0)
	{
		for (int i = 0; i < RemAttackCapacity; i++)
		{
			AttackedAM = GameManager->getAA()->PickAM();
			if (AttackedAM != NULL && GameManager->getAA()->getAMcount() > 0)
			{
				GameManager->getAA()->RemoveAM(AttackedAM);
				Damage = (Power * Health / 100) /sqrt(AttackedAM->getHealth());
				AttackedAM->setHealth(AttackedAM->getHealth() - Damage);

				AttackedAM->GotShot();
				if (AttackedAM->GetNumGotShot() == 1) {
					AttackedAM->setFirstShotTime(GameManager->GetTimeStep());
				}

				if (AttackedAM->getHealth() == 0)
				{
					AttackedAM->setDistrucTime(GameManager->GetTimeStep());
					GameManager->addKilled(AttackedAM);
					ShotID = AttackedAM->getID();
					ShotList->enqueue(ShotID);
					killedunits++;
					ShotCount++;
				}
				else if (AttackedAM->getHealth() > 0)
				{
					ArmyUnit* AU = AttackedAM;
					ShotID = AttackedAM->getID();
					TempList->enqueue(AU);
					ShotList->enqueue(ShotID);
					aliveunits++;
					ShotCount++;
				}
			}
		}
	}
	if (ShotCount != 0 && GameManager->getSelectedMode() == 1)
	{
		cout << u8"🚜 " << "ET" << ID << " shots ";
		ShotList->Print2();
		cout << " IDs of all alien units shot by ET" << ID << endl;
	}
	ArmyUnit* AU;
	for (int i = 0; i < aliveunits; i++)
	{
		TempList->dequeue(AU);
		GameManager->AddUnit(AU);
	}
}

