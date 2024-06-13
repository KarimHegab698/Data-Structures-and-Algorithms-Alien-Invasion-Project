#include "EarthGunnery.h"
#include "Game.h"
#include <iostream>

using namespace std;

EarthGunnery::EarthGunnery(int ID, int JoinTime, int Health, int Power, int AttackCapacity, Game*& game)
{
	this->ID = ID;
	this->JoinTime = JoinTime;
	this->Health = (Health > 0 && Health <= 100 ? Health : 100);
	this->Power = Power;
	this->type = EG;
	this->GameManager = game;
	this->AttackCapacity = AttackCapacity;
	power_health_combination = sqrt(Power * Health);
}

EarthGunnery::EarthGunnery()
{
	ID = 0;
	JoinTime = 0;
	Health = 100;
	Power = 0;
	type = EG;
	AttackCapacity = 0;
	power_health_combination = 0;
}


void EarthGunnery::Attack() 
{
	AlienDrone* AD1;
	AlienDrone* AD2;
	AlienMonster* AM;
	ArmyUnit* ArmyUnitTemp;
	Queue<ArmyUnit*>* TempList = new Queue<ArmyUnit*>;
	Queue<int>* ShotList = new Queue<int>;
	int ShotID;
	int notkilledUnits = 0, ShotUnits = 0;
	int damage;
	int Capacity = AttackCapacity;
	GameManager->getAA()->PickAD(AD1, AD2);
	AM = GameManager->getAA()->PickAM();


	while (Capacity > 0 && !(AM == NULL && AD1 == NULL && AD2 == NULL)) {
		
		if (AD1 != NULL) {
				//Attack
				GameManager->getAA()->RemoveAD(AD1);
				damage = (Power * Health / 100) / sqrt(AD1->getHealth());
				AD1->setHealth(AD1->getHealth() - damage);

				AD1->GotShot();
				if (AD1->GetNumGotShot() == 1) {
					AD1->setFirstShotTime(GameManager->GetTimeStep());
				}

				ShotID = AD1->getID();
				ShotList->enqueue(ShotID);
				ShotUnits++;
				if (AD1->getHealth() <= 0) {
					AD1->setDistrucTime(GameManager->GetTimeStep());
					GameManager->addKilled(AD1);
				}
				else {
					ArmyUnitTemp = AD1;
					TempList->enqueue(ArmyUnitTemp);
					notkilledUnits++;
				}

				Capacity--;
				if (Capacity == 0) {
					break;
				}
		}


		if (AM != NULL) {
			//Attack
			GameManager->getAA()->RemoveAM(AM);
			damage = (Power * Health / 100) / sqrt(AM->getHealth());
			AM->setHealth(AM->getHealth() - damage);

			AM->GotShot();
			if (AM->GetNumGotShot() == 1) {
				AM->setFirstShotTime(GameManager->GetTimeStep());
			}

			ShotID = AM->getID();
			ShotList->enqueue(ShotID);
			ShotUnits++;
			if (AM->getHealth() <= 0) {
				AM->setDistrucTime(GameManager->GetTimeStep());
				GameManager->addKilled(AM);
			}
			else {
				ArmyUnitTemp = AM;
				TempList->enqueue(ArmyUnitTemp);
				notkilledUnits++;
			}
			Capacity--;
			if (Capacity == 0) {
				break;
			}
		}

		if (AD2 != NULL) {
			//Attack
			GameManager->getAA()->RemoveAD(AD2);
			damage = (Power * Health / 100) /sqrt(AD2->getHealth());
			AD2->setHealth(AD2->getHealth() - damage);

			AD2->GotShot();
			if (AD2->GetNumGotShot() == 1) {
				AD2->setFirstShotTime(GameManager->GetTimeStep());
			}

			ShotID = AD2->getID();
			ShotList->enqueue(ShotID);
			ShotUnits++;
			if (AD2->getHealth() <= 0) {
				AD2->setDistrucTime(GameManager->GetTimeStep());
				GameManager->addKilled(AD2);
			}
			else {
				ArmyUnitTemp = AD2;
				TempList->enqueue(ArmyUnitTemp);
				notkilledUnits++;
			}
			Capacity--;
			if (Capacity == 0) {
				break;
			}
		}

		AM = GameManager->getAA()->PickAM();
		if (AM != NULL) {
			//Attack
			GameManager->getAA()->RemoveAM(AM);
			damage = (Power * Health / 100) / sqrt(AM->getHealth());
			AM->setHealth(AM->getHealth() - damage);

			AM->GotShot();
			if (AM->GetNumGotShot() == 1) {
				AM->setFirstShotTime(GameManager->GetTimeStep());
			}

			ShotID = AM->getID();
			ShotList->enqueue(ShotID);
			ShotUnits++;
			if (AM->getHealth() <= 0) {
				AM->setDistrucTime(GameManager->GetTimeStep());
				GameManager->addKilled(AM);
			}
			else {
				ArmyUnitTemp = AM;
				TempList->enqueue(ArmyUnitTemp);
				notkilledUnits++;
			}


			Capacity--;
			if (Capacity == 0) {
				break;
			}

		}
		AM = GameManager->getAA()->PickAM();
		GameManager->getAA()->PickAD(AD1, AD2);
	}

	 if(ShotUnits!=0 && GameManager->getSelectedMode() == 1) {
		cout << u8"💣 " << "EG " << ID << " shoots ";
		ShotList->Print2();
		cout << " IDs of all alien units shot by EG " << ID << endl;
	 }



	ArmyUnit* AU;
	for (int i = 0; i < notkilledUnits; i++) {
		TempList->dequeue(AU);
		GameManager->AddUnit(AU);
	}

}

void EarthGunnery::setpower_health_combination(int combination)
{
	power_health_combination = combination;
}

int EarthGunnery::getpower_health_combination() const
{
	return power_health_combination;
}
