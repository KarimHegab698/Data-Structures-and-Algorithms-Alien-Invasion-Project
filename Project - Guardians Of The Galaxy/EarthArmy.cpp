#include "EarthArmy.h"
#include <iostream>

using namespace std;

EarthArmy::EarthArmy(Game*& game)
{
	this->game = game;
	ESArmy = new Queue<EarthSoldier*>;
	ETArmy = new Stack<EarthTank*>;
	EGArmy = new PriorityQueue<EarthGunnery*>;
	HUArmy = new Stack<HealUnit*>;
}
int EarthArmy::getEScount()
{
	return EScount;
}
int EarthArmy::getETcount()
{
	return ETcount;
}
int EarthArmy::getEGcount()
{
	return EGcount;
}
int EarthArmy::getHUcount()
{
	return HUcount;
}
void EarthArmy::GetTotalNums(int& ES, int& ET, int& EG, int& HU)
{
	ES = TEScount;
	ET = TETcount;
	EG = TEGcount;
	HU = THUcount;
}
EarthArmy::EarthArmy()
{
	ESArmy = new Queue<EarthSoldier*>();
	ETArmy = new Stack<EarthTank*>();
	EGArmy = new PriorityQueue<EarthGunnery*>();
	HUArmy = new Stack<HealUnit*>();
}

void EarthArmy::AddUnit(ArmyUnit*& UnitPtr) {
	int id, power, health, time, cap,inhel;
	int Type = UnitPtr->getType();//ES=0,ET=1,EG=2,AS=3,AM=4,AD=5,HU=6
	id = UnitPtr->getID();
	power = UnitPtr->getPower();
	health = UnitPtr->getHealth();
	time = UnitPtr->getJoinTime();
	cap = UnitPtr->getAttackCapacity();
	switch (Type)
	{
	case 0: {
		inhel = dynamic_cast<EarthSoldier*>(UnitPtr)->getInitialhealth();
		EarthSoldier* addES = new EarthSoldier(id, time, inhel, power, cap, game);
		addES->setHealth(health);
		AddES(addES);
		break;
	}
	case 1:{
		inhel = dynamic_cast<EarthTank*>(UnitPtr)->getInitialhealth();
		EarthTank* addET = new EarthTank(id, time, inhel, power, cap, game);
		addET->setHealth(health);
		AddET(addET);
		break;
	}
	case 2: {
		EarthGunnery* addEG = new EarthGunnery(id, time, health, power, cap, game);
		AddEG(addEG);
		break;
	}
	case 6: {
		bool stats = dynamic_cast<HealUnit*>(UnitPtr)->getdie();
		HealUnit* addHU = new HealUnit(id, time, health, power, cap, game);
		addHU->setdie(stats);
		AddHU(addHU);
		break;
	}
	default:
		break;
	};
	delete UnitPtr;
	UnitPtr = nullptr;
}


void EarthArmy::AddES(EarthSoldier* &ES)
{
	if (ES->getID() != 0) 
	{
		ESArmy->enqueue(ES);
		EScount++;
		TEScount++;
	}
}

void EarthArmy::AddET(EarthTank*& ET)
{
	if (ET->getID() != 0) {
		ETArmy->push(ET);
		ETcount++;
		TETcount++;
	}
}

void EarthArmy::AddEG(EarthGunnery*& EG) {
	if (EG->getID() != 0) {
		EGArmy->enqueue(EG, EG->getpower_health_combination());
		EGcount++;
		TEGcount++;
	}
}

void EarthArmy::AddHU(HealUnit*& HU)
{
 if(HU->getID()!=0&&HU->getdie() == false)
 {
		HUArmy->push(HU);
		HUcount++;
		THUcount++;
 }
}

EarthSoldier* EarthArmy::PickES()
{
	if (ESArmy->front != nullptr)
	{
		return ESArmy->front->getItem();
	}
	else
	{
		return nullptr;
	}
}

EarthTank* EarthArmy::PickET()
{
	if (ETArmy->Top != nullptr)
	{
		return ETArmy->Top->getItem();
	}
	else
	{
		return nullptr;
	}
}

EarthGunnery* EarthArmy::PickEG()
{
	EarthGunnery* EG;
	int x;
	bool flag = EGArmy->peek(EG, x);
	if (flag) {
		EG->setpower_health_combination(x);
		return EG;
	}
	return NULL;
}

HealUnit* EarthArmy::PickHU()
{
	if (HUArmy->Top != nullptr)
	{
		return HUArmy->Top->getItem();
	}
	else
	{
		return nullptr;
	}
}



bool EarthArmy::RemoveES(EarthSoldier* &ES)
{
	bool status = ESArmy->dequeue(ES);
	EScount--;
	if (EScount < 0)
	{
		EScount = 0;
	}
	return status;
}

bool EarthArmy::RemoveET(EarthTank* &ET)
{
	bool status = ETArmy->pop(ET);
	ETcount--;
	if (ETcount < 0)
	{
		ETcount = 0;
	}
	return status;
}

bool EarthArmy::RemoveEG(EarthGunnery*& EG)
{
	if (EG != nullptr) {
		int variable = EG->getpower_health_combination();
		bool status = EGArmy->dequeue(EG, variable);
		EGcount--;
		if (EGcount < 0)
		{
			EGcount = 0;
		}
		return status;
	}
	return false;
}

bool EarthArmy::RemoveHU(HealUnit*& HU)
{
	bool status = HUArmy->pop(HU);
	HUcount--;
	if (HUcount < 0)
	{
		HUcount = 0;
	}
	return status;
}

void EarthArmy::ESPrint()
{
	cout << u8"👮 " << EScount << " ES ";
	ESArmy->Print();
}

void EarthArmy::ETPrint()
{
	cout << u8"🚜 " << ETcount << " ET ";
	ETArmy->Print();
}

void EarthArmy::EGPrint()
{
	cout << u8"💣 " << EGcount << " EG ";
	if (EGArmy->isEmpty())
	{
		cout << "[ Empty ]\n";
		return;
	}
	PriorityNode<EarthGunnery*>* Temp = EGArmy->head;
	cout << "[ " << Temp->getItem(EGArmy->head->pri)->getID();
	Temp = Temp->getNext();
	while (Temp != NULL)
	{
		cout << ", " << Temp->getItem(Temp->pri)->getID();
		Temp = Temp->getNext();
	}
	cout << " ]\n";
}

void EarthArmy::HUPrint()
{
	cout << u8"⛑  " << HUcount << " HU ";
	HUArmy->Print();
}

void EarthArmy::Print()
{
	cout << u8"\n🌍🌍🌍🌍🌍🌍🌍🌍🌍🌍🌍🌍🌍🌍🌍🌍 Earth Army Alive Units 🌍🌍🌍🌍🌍🌍🌍🌍🌍🌍🌍🌍🌍🌍🌍🌍\n";
	ESPrint();
	ETPrint();
	EGPrint();
	HUPrint();
}


Queue<EarthSoldier*>* EarthArmy::getESArmy()
{
	return ESArmy;
}

PriorityQueue<EarthGunnery*>* EarthArmy::getEGArmy()
{
	return EGArmy;
}

Stack<EarthTank*>* EarthArmy::getETArmy()
{
	return ETArmy;
}


Stack<HealUnit*>* EarthArmy::getHUArmy()
{
	return HUArmy;
}


