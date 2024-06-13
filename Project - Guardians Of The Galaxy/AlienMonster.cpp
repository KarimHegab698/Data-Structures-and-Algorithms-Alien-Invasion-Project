#include "AlienMonster.h"
#include "Game.h"

AlienMonster::AlienMonster() {
	ID = 0;
	JoinTime = 0;
	Health = 100;
	Power = 0;
	type = AM;
	AttackCapacity = 0;
}

AlienMonster::AlienMonster(int ID, int JoinTime, int Health, int Power, int AttackCapacity, Game*& game) {
	this->ID = ID;
	this->JoinTime = JoinTime;
	this->Health = (Health > 0 && Health <= 100 ? Health : 100);
	this->Power = Power;
	this->type = AM;
	this->GameManager = game;
	this->AttackCapacity = AttackCapacity;
}

void AlienMonster::Attack() {
	EarthSoldier* ES;
	EarthTank* ET;
	int Capacity = AttackCapacity;
	ArmyUnit* ArmyUnitTemp;
	Queue<ArmyUnit*>* TempList = new Queue<ArmyUnit*>;
	Queue<int>* ShotList = new Queue<int>;
	int ShotID;
	int notkilledUnits = 0, ShotUnits = 0;
	int damage;
	ES = GameManager->getEA()->PickES();
	ET = GameManager->getEA()->PickET();

	
	while (Capacity > 0 && !(ES == NULL && ET == NULL)){
		if (ES != NULL) {
			//Attack
			GameManager->getEA()->RemoveES(ES);
			damage = (Power * Health / 100) / sqrt(ES->getHealth());
			ES->setHealth(ES->getHealth() - damage);

			ES->GotShot();
			if (ES->GetNumGotShot() == 1) {
				ES->setFirstShotTime(GameManager->GetTimeStep());
			}

			ShotID = ES->getID();
			ShotList->enqueue(ShotID);
			ShotUnits++;
			if (ES->getHealth() <= 0) {
				ES->setDistrucTime(GameManager->GetTimeStep());
				GameManager->addKilled(ES);
			}
			else if(ES->getHealth() > 0 && ES->getHealth() < 0.2 * ES->getInitialhealth())
			{
				ES->setJoinedUMLTime(GameManager->GetTimeStep());
				GameManager->addUML_ES(ES);
			}
			else {
				ArmyUnitTemp = ES;
				TempList->enqueue(ArmyUnitTemp);
				notkilledUnits++;
			}

			Capacity--;
			if (Capacity == 0) {
				break;
			}
		}


		if (ET != NULL) {
			//Attack
			GameManager->getEA()->RemoveET(ET);
			damage = (Power * Health / 100) / sqrt(ET->getHealth());
			ET->setHealth(ET->getHealth() - damage);

			ET->GotShot();
			if (ET->GetNumGotShot() == 1) {
				ET->setFirstShotTime(GameManager->GetTimeStep());
			}

			ShotID = ET->getID();
			ShotList->enqueue(ShotID);
			ShotUnits++;
			if (ET->getHealth() <= 0) {
				ET->setDistrucTime(GameManager->GetTimeStep());
				GameManager->addKilled(ET);
			}
			else if (ET->getHealth() > 0 && ET->getHealth() < 0.2 * ET->getInitialhealth()) {
				ET->setJoinedUMLTime(GameManager->GetTimeStep());
				GameManager->addUML_ET(ET);
			}
			else {
				ArmyUnitTemp = ET;
				TempList->enqueue(ArmyUnitTemp);
				notkilledUnits++;
			}
			Capacity--;
			if (Capacity == 0) {
				break;
			}
		}

		ES = GameManager->getEA()->PickES();
		ET = GameManager->getEA()->PickET();
	}

	
	if (ShotUnits != 0 && GameManager->getSelectedMode() == 1) {
		cout << u8"\U0001f47e " << "AM " << ID << " shoots ";
		ShotList->Print2();
		cout << " IDs of all alien units shot by AM " << ID << endl;
	}
		


	ArmyUnit* AU;
	for (int i = 0; i < notkilledUnits; i++) {
		TempList->dequeue(AU);
		GameManager->AddUnit(AU);
	}
}




