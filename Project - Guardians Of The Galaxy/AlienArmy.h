#pragma once
#include "AlienSoldier.h"
#include "AlienDrone.h"
#include "Queue.h"
#include "Deque.h"
#include <iostream>
#include "AlienMonster.h"
using namespace std;
#define Max_size 1000


class AlienArmy
{
protected:
	Queue <AlienSoldier*>* ASArmy;
	Deque<AlienDrone*>* ADArmy;
	AlienMonster** AMArmy;
	Game* game;
	int AScount = 0;
	int ADcount = 0;
	int AMcount = 0;
	int TAScount = 0;
	int TADcount = 0;
	int TAMcount = 0;
public:
	AlienArmy(Game*& game);
	AlienArmy();
	int getAScount();
	int getADcount();
	int getAMcount();
	void getTotalNums(int& AS, int& AD, int& AM);
	void AddToList(ArmyUnit*& UnitPtr);
	void AddAS(AlienSoldier* &AS);
	void AddAD(AlienDrone* &AD);
	void AddAM(AlienMonster*& AM);
	AlienSoldier* PickAS();
	void PickAD(AlienDrone* &AD1, AlienDrone* &AD2);
	AlienMonster* PickAM();
	bool RemoveAS(AlienSoldier*& AS);
	bool RemoveAD(AlienDrone*&AD);
	bool RemoveAM(AlienMonster*& AM);
	void ASPrint();
	void ADPrint();
	void AMPrint();
	void Print();

	Queue<AlienSoldier*>* getASArmy();
	Deque<AlienDrone*>* getADArmy();
	AlienMonster** getAMArmy();
};




