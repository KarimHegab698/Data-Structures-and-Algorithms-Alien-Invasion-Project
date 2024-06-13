//#pragma once
#include<fstream>
#include<iostream>
#include"Game.h"
using namespace std;
class Game;
#ifndef RANDGEN
#define RANDGEN


class RandGen
{
	Game *GamePtr;

	static int EunitID;
	static int AunitID;
	static int SunutID;

	string Filename;

	int TimeStep;

	int N;
	int ES, ET, EG, HU;
	int AS, AM, AD;
	int Prob;
	int Infectionthresh;

	int EarthUPowermin,EarthUPowermax;
	int EarthUHealthmin,EarthUHealthmax;
	int EarthUAttackCapmin, EarthUAttackCapmax;

	int AlienUPowermin, AlienUPowermax;
	int AlienUHealthmin, AlienUHealthmax;
	int AlienUAttackCapmin, AlienUAttackCapmax;

	/*int SaverUPowermin, SaverUPowermax;
	int SaverUHealthmin, SaverUHealthmax;
	int SaverUAttackCapmin, SaverUAttackCapmax;*/


public:
	
	RandGen(Game*& GamePtr);
	void Setprob(int n, int es, int et, int eg, int hu, int as, int am, int ad, int prob);
	void SetEU(int EUPmin, int EUPmax, int EUHmin, int EUHmax, int EUACapmin, int EUACapmax);
	void SetAU(int AUPmin, int AUPmax, int AUHmin, int AUHmax, int AUACapmin, int AUACapmax);
	
	void UnitsGenerator();
	ArmyUnit* EGen();
	ArmyUnit* AGen();
	//ArmyUnit* SUGen();
	
	int NumGen();
	
	void SetTimeStep(int num);
	
	
	int EUPowerGen();
	int EUHealthGen();
	int EUAttackCapGen();

	int AUPowerGen();
	int AUHealthGen();
	int AUAttackCapGen();

	/*int SUPowerGen();
	int SUHealthGen();
	int SUAttackCapGen();*/
	


};
#endif // !RANDGEN

