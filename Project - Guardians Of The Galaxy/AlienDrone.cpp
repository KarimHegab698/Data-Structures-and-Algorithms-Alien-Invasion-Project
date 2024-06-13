#include "AlienDrone.h"
#include "Game.h"
#include <iostream>
using namespace std;

AlienDrone::AlienDrone()
{
	ID = 0;
	type = AD;
	JoinTime = 0;
	Health = 100;
	Power = 0;
	AttackCapacity = 0;
}

AlienDrone::AlienDrone(int id, int jointime, int health, int power, int attackcapacity, Game*& game)
{
	ID = id;
	type = AD;
	JoinTime = jointime;
	Health = (health > 0 && health <= 100 ? health : 100);
	Power = power;
	GameManager = game;
	AttackCapacity = attackcapacity;
}

void AlienDrone::Attack()
{
	if (GameManager->getEA()->getEGArmy()->isEmpty() || GameManager->getEA()->getETArmy()->IsEmpty())
	{
		return;
	}
	int killedunits = 0;
	int aliveunitsET = 0;
	int aliveunitsEG = 0;
	int attackcapacity = AttackCapacity;
	int DamageEG = 0;
	int DamageET = 0;
	int ShotCount = 0;
	Queue<EarthGunnery*>* TempListG = new Queue<EarthGunnery*>();
	Queue<EarthGunnery*>* ShotListG = new Queue<EarthGunnery*>();
	Queue<EarthTank*>* TempListT = new Queue<EarthTank*>();
	Queue<EarthTank*>* ShotListT = new Queue<EarthTank*>();
	EarthGunnery* AttackedEG = new EarthGunnery();
	EarthTank* AttackedET = new EarthTank();
	AttackedEG = GameManager->getEA()->PickEG();
	AttackedET = GameManager->getEA()->PickET();
	while (GameManager->getAA()->getADcount() > 1 && attackcapacity > 0 && (AttackedEG != nullptr || AttackedET != nullptr) && (GameManager->getEA()->getEGcount() > 0 || GameManager->getEA()->getETcount() > 0))
	{
		if (attackcapacity > 0 && AttackedEG)
		{
			GameManager->getEA()->RemoveEG(AttackedEG);
			DamageEG = (Power * Health / 100) / sqrt(AttackedEG->getHealth());
			AttackedEG->setHealth(AttackedEG->getHealth() - DamageEG);

			AttackedEG->GotShot();
			if (AttackedEG->GetNumGotShot() == 1) {
				AttackedEG->setFirstShotTime(GameManager->GetTimeStep());
			}

			if (AttackedEG->getHealth() == 0)
			{
				AttackedEG->setDistrucTime(GameManager->GetTimeStep());
				GameManager->addKilled(AttackedEG);
				ShotListG->enqueue(AttackedEG);
				killedunits++;
				ShotCount++;
				AttackedEG->GotShot();
				attackcapacity--;
			}
			else
			{
				TempListG->enqueue(AttackedEG);
				ShotListG->enqueue(AttackedEG);
				aliveunitsEG++;
				AttackedEG->GotShot();
				ShotCount++;
				attackcapacity--;
			}
			if (attackcapacity == 0)
			{
				break;
			}
		}

		if (attackcapacity > 0 && AttackedET)
		{
			GameManager->getEA()->RemoveET(AttackedET);
			DamageET = (Power * Health / 100) / sqrt(AttackedET->getHealth());
			AttackedET->setHealth(AttackedET->getHealth() - DamageET);

			AttackedET->GotShot();
			if (AttackedET->GetNumGotShot() == 1) {
				AttackedET->setFirstShotTime(GameManager->GetTimeStep());
			}

			if (AttackedET->getHealth() == 0)
			{
				AttackedET->setDistrucTime(GameManager->GetTimeStep());
				GameManager->addKilled(AttackedET);
				ShotListT->enqueue(AttackedET);
				killedunits++;
				AttackedET->GotShot();
				ShotCount++;
				attackcapacity--;
			}
			else if (AttackedET->getHealth() > 0 && AttackedET->getHealth() < 0.2 * AttackedET->getInitialhealth())
			{
				AttackedET->setJoinedUMLTime(GameManager->GetTimeStep());
				GameManager->addUML_ET(AttackedET);
				ShotListT->enqueue(AttackedET);
				AttackedET->GotShot();
				ShotCount++;
				attackcapacity--;
				GameManager->getEA()->RemoveET(AttackedET);
			}
			else
			{
				TempListT->enqueue(AttackedET);
				ShotListT->enqueue(AttackedET);
				aliveunitsET++;
				AttackedET->GotShot();
				ShotCount++;
				attackcapacity--;
			}
			if (attackcapacity == 0)
			{
				break;
			}
		}
		if (GameManager->getEA()->getEGArmy()->isEmpty() && GameManager->getEA()->getETArmy()->IsEmpty())
		{
			return;
		}
		AttackedEG = GameManager->getEA()->PickEG();
		AttackedET = GameManager->getEA()->PickET();
	}
	if (ShotCount != 0&& GameManager->getSelectedMode()==1)
	{
		cout << u8"\U0001f6f8 " << "AD" << ID << " shots ";
		ShotListT->Print2();
		ShotListG->Print2();
		cout << " IDs of all Earth units shot by AD" << ID << endl;
	}
	EarthGunnery* EG = new EarthGunnery();
	EarthTank* ET = new EarthTank();
	for (int i = 0; i < aliveunitsET; i++)
	{
		TempListT->dequeue(ET);
		GameManager->AddUnit(ET);
	}
	for (int i = 0; i < aliveunitsEG; i++)
	{
		TempListG->dequeue(EG);
		GameManager->AddUnit(EG);
	}
	if (GameManager->getEA()->getEGArmy()->isEmpty() && GameManager->getEA()->getETArmy()->IsEmpty())
	{
		return;
	}
}