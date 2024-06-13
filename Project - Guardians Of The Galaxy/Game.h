#pragma once
#include <fstream>
#include "AlienArmy.h"
#include "EarthArmy.h"
#include "ArmyUnit.h"
#include "RandGen.h"
#include<string>
#include <iostream>
using namespace std;
class Game
{
private:
	int ProgramMode;   //  1 Interactive, 2 Silent
	string OutFileName;
	AlienArmy* AA;
	EarthArmy* EA;
	Queue<ArmyUnit*> KilledList;
	//Queue<ArmyUnit*> TempList;
	Queue<ArmyUnit*> AttackingUnits;
	PriorityQueue<EarthSoldier*> UML_ES;
	Queue<EarthTank*> UML_ET;
	int KilledCount = 0;
	int UML_ET_Count = 0;
	int UML_ES_Count = 0;
	int HealedCount=0;
	int WarState;//1 earth , 2 alien, 3 draw 
	//int tempListCount = 0;
	ArmyUnit* AttackingUnit;
	int TimeStep=1;
	RandGen* randgen;
	string Filename;
	string WE_WA="EWeak_AWeak.txt", WE_MA = "EWeak_AMod.txt", WE_SA = "EWeak_AStrong.txt", SE_WA = "EStrong_AWeak.txt", SE_MA = "EStrong_AMod.txt", SE_SA = "EStrong_AStrong.txt";

	
public:
	Game();

	void ChooseMode();
	int getSelectedMode();
	bool SelectFilename();
	void LoadFromFile();
	void separatenums(string input, int& min, int& max);

	int GetTimeStep();
	void GenUnits();
	void AddUnit(ArmyUnit* UnitPtr);
	bool RemoveUnit(ArmyUnit* &UnitPtr,int Type);
	AlienMonster* PickAM();
	void pickAD(ArmyUnit*& UnitPtr1, ArmyUnit*& UnitPtr2);
	EarthGunnery* pickEG();
	HealUnit* pickHU();
	void Simulate();

	void addUML_ET(EarthTank*& ET);
	void addUML_ES(EarthSoldier*& ES);

	void EarthAttack();
	void AlienAttack();

	void addKilled(ArmyUnit* AU);

	bool RemoveES_UML(EarthSoldier*& ES, int& pri);
	bool RemoveET_UML(EarthTank*& ET);
	void PrintUML();


	//void addTempList(ArmyUnit* AU);
	void PrintKilled();
	void Proceed();
	int RandNum();
	//void Print();
	void Print1();
	void Print2();
	//void PrintTempList(ArmyUnit* AU);

	//void setTempListCount(int c);
	//int  getTempListCount();

	int getUML_ES_Count();
	int getUML_ET_Count();

	void setAttackingUnit(ArmyUnit*AU);
	ArmyUnit* getAttackingUnit();

	//Queue<ArmyUnit*> GetTempList();
	Queue<AlienSoldier*>* getASArmy();
	Queue<EarthSoldier*>* getESArmy();
	Stack<EarthTank*>* getETArmy();
	PriorityQueue<EarthGunnery*>* getEGArmy();
	Deque<AlienDrone*>* getADArmy();
	AlienMonster** getAMArmy();
	Stack<HealUnit*>* getHUArmy();

	PriorityQueue<EarthSoldier*> getES_UML();
	Queue<EarthTank*> getET_UML();
	void Healed();
	AlienArmy* getAA();
	EarthArmy* getEA();
	bool IsFileName(string input);
	void GetOutFileName();
	void GenOutFile();
	
};

