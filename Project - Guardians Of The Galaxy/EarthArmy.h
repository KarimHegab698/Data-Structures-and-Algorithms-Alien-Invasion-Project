#pragma once
#include "EarthSoldier.h"
#include "EarthTank.h"
#include "EarthGunnery.h"
#include "HealUnit.h"
#include "Stack.h"
#include "Queue.h"
#include "PriorityQueue.h"

using namespace std;

class EarthArmy
{
protected:
	Queue<EarthSoldier*>* ESArmy;
	Stack<EarthTank*>* ETArmy;
	PriorityQueue<EarthGunnery*>* EGArmy;
	Stack<HealUnit*>* HUArmy;
	int EScount = 0;
	int ETcount = 0;
	int EGcount = 0;
	int HUcount = 0;
	int TEScount = 0;
	int TETcount = 0;
	int TEGcount = 0;
	int THUcount = 0;
	Game* game;
public:
	EarthArmy(Game*& game);
	int getEScount();
	int getETcount();
	int getEGcount();
	int getHUcount();
	void GetTotalNums(int& ES, int& ET, int& EG, int& HU);
	EarthArmy();
	void AddUnit(ArmyUnit*& UnitPtr);
	void AddES(EarthSoldier* &ES);
	void AddET(EarthTank* &ET);
	void AddEG(EarthGunnery* &EG);
	void AddHU(HealUnit*& HU);
	EarthSoldier* PickES();
	EarthTank* PickET();
	EarthGunnery* PickEG();
	HealUnit* PickHU();
	bool RemoveES(EarthSoldier* &ES);
	bool RemoveET(EarthTank* &ET);
	bool RemoveEG(EarthGunnery*& EG);
	bool RemoveHU(HealUnit*& HU);
	void ESPrint();
	void ETPrint();
	void EGPrint();
	void HUPrint();
	void Print();
	Queue<EarthSoldier*>* getESArmy();
	PriorityQueue<EarthGunnery*>* getEGArmy();
	Stack<EarthTank*>* getETArmy();
	Stack<HealUnit*>* getHUArmy();
};

