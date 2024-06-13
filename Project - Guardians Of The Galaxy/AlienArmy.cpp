#include "AlienArmy.h"
#include <iostream>

AlienArmy::AlienArmy(Game*& game)
{
	ASArmy = new Queue<AlienSoldier*>;
	ADArmy = new Deque<AlienDrone*>;
	AMArmy = new AlienMonster* [Max_size];
	this->game = game;
	for (int i = 0; i < Max_size; i++)
	{
		AMArmy[i] = NULL;
	}
}

AlienArmy::AlienArmy()
{
	ASArmy = new Queue<AlienSoldier*>;
	ADArmy = new Deque<AlienDrone*>;
	AMArmy = new AlienMonster * [Max_size];
	for (int i = 0; i < Max_size; i++)
	{
		AMArmy[i] = NULL;
	}
}

int AlienArmy::getAScount()
{
	return AScount;
}
int AlienArmy::getADcount()
{
	return ADcount;
}
int AlienArmy::getAMcount()
{
	return AMcount;
}
void AlienArmy::getTotalNums(int& AS, int& AD, int& AM)
{
	AS = TAScount;
	AD = TADcount;
	AM = TAMcount;

}
void AlienArmy::AddToList(ArmyUnit*& UnitPtr) {
	int id, power, health, time, cap;
	int Type = UnitPtr->getType();//ES=0,ET=1,EG=2,AS=3,AM=4,AD=5
	id = UnitPtr->getID();
	power = UnitPtr->getPower();
	health = UnitPtr->getHealth();
	time = UnitPtr->getJoinTime();
	cap = UnitPtr->getAttackCapacity();
	switch (Type)
	{
	case 3: {
		AlienSoldier* addAS = new AlienSoldier(id, time, health, power, cap, game);
		AddAS(addAS);
		break;
	}
	case 4: {
		AlienMonster* addAM = new AlienMonster(id, time, health, power, cap, game);
		AddAM(addAM);
		break;
	}
	case 5: {
		AlienDrone* addAD = new AlienDrone(id, time, health, power, cap, game);
		AddAD(addAD);
		break;
	}
	default:
		break;
	};
	delete UnitPtr;
	UnitPtr = nullptr;
}

void AlienArmy::AddAS(AlienSoldier*&AS)
{
	if (AS->getID() != 0) {
		ASArmy->enqueue(AS);
		AScount++;
		TAScount++;
	}
}

AlienSoldier* AlienArmy::PickAS()
{
	return ASArmy->front->getItem();
}

bool AlienArmy::RemoveAS(AlienSoldier*& AS)
{
	bool status=false;
	if (AScount != 0) {
		status = ASArmy->dequeue(AS);
		AScount--;
		if (AScount < 0)
		{
			AScount = 0;
		}
	}
		return status;
}

void AlienArmy::ASPrint()
{
	cout << u8"🤖 " << AScount << " AS ";
	ASArmy->Print();
}

void AlienArmy::AddAD(AlienDrone* &AD)
{
	if (AD->getID() != 0) {
		if (ADcount % 2 == 0) {
			ADArmy->enqueuefront(AD);
			ADcount++;
			TADcount++;
		}
		else {
			ADArmy->enqueueback(AD);
			ADcount++;
			TADcount++;
		}
	}
}

bool AlienArmy::RemoveAD(AlienDrone* &AD)
{ 
		if (ADcount > 0)
		{
			if (AD->getID() == ADArmy->front->getItem()->getID())
			{
				ADArmy->dequeuefront(AD);
				ADcount--;
			}
			else if (AD->getID() == ADArmy->rear->getItem()->getID())
			{
				ADArmy->dequeueback(AD);
				ADcount--;
			}
			return true;
		}
		if (ADcount < 0)
		{
			ADcount = 0;
		}
		return false;
}

void AlienArmy::PickAD(AlienDrone* & AD1, AlienDrone* &AD2)
{
	bool status = ADArmy->peekfront(AD1);
	if (!status) {
		AD1 = NULL;
		AD2 = NULL;
		return;
	}
	ADArmy->peekback(AD2);
	if (AD1 == AD2)
	{
		AD2 = NULL;
	}
}

void AlienArmy::ADPrint()
{
	cout << u8"\U0001f6f8 " << ADcount << " AD ";
	ADArmy->PrintD();
}

void AlienArmy::AddAM(AlienMonster* &AM) {
	if (AM->getID() != 0) {
		if (AMcount < Max_size) {

			AMArmy[AMcount] = AM;
			AMcount++;
			TAMcount++;
		}
	}
}

AlienMonster* AlienArmy::PickAM() {
	if (AMcount == 0)
	{
		return NULL;
	}
	int random = rand() % AMcount;
	return AMArmy[random];
}

bool AlienArmy::RemoveAM(AlienMonster* &AM) {
	bool status=false;
	if (AMcount > 0) {
		for (int i = 0; i < AMcount; i++) {
			if (AMArmy[i] == AM) {
				AMArmy[i] = AMArmy[AMcount - 1];
				AMArmy[AMcount - 1] = NULL;
				AMcount--;
				status = true;
				break;
			}
		}
		
		
	}
	return status;
}

void AlienArmy::AMPrint() {
	cout << u8"\U0001f47e " << AMcount << " AM ";
	if (AMcount == 0 || AMArmy[0] == NULL)
	{
		cout << "[ Empty ]\n";
		return;
	}
	cout << "[ " << AMArmy[0]->getID();
	for (int i = 1; i < AMcount; i++) {
		cout << ", " << AMArmy[i]->getID();
	}
	cout << " ]\n";
}

void AlienArmy::Print()
{
	cout << u8"\n👽👽👽👽👽👽👽👽👽👽👽👽👽👽👽👽 Alien Army Alive Units 👽👽👽👽👽👽👽👽👽👽👽👽👽👽👽👽\n";
	ASPrint();
	AMPrint();
	ADPrint();
}

Queue<AlienSoldier*>* AlienArmy::getASArmy()
{
	return ASArmy;
}

Deque<AlienDrone*>* AlienArmy::getADArmy()
{
	return ADArmy;
}

AlienMonster** AlienArmy::getAMArmy()
{
	return AMArmy;
}




