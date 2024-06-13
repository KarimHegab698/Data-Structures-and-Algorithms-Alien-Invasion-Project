#include <fstream>
#include <iostream>
/*#include "Queue.h"
#include "PriorityQueue.h"
#include "Node.h"
#include "Stack.h"
#include "EarthSoldier.h"
#include "EarthTank.h"
#include "EarthArmy.h"
#include "ArmyUnit.h"
#include "EarthGunnery.h"
#include "AlienArmy.h"
#include "AlienSoldier.h"
#include "RandGen.h"*/
#include "Game.h"


using namespace std;

int main()
{
	// Test code 
	Game* Control = new Game();
	 
	//Earth Soldier
	/*Control->Simulate();*/
	/*EarthSoldier* ES1 = new EarthSoldier(1,0,100,300,4,Control);
	AlienArmy* AA = new AlienArmy();
	EarthArmy* EA = new EarthArmy();
	AlienSoldier* AS1 = new AlienSoldier(2, 0, 100, 50, 4, Control);
	AlienSoldier* AS2 = new AlienSoldier(3, 0, 90, 50, 4, Control);
	AlienSoldier* AS3 = new AlienSoldier(4, 0, 80, 50, 4, Control);
	AlienSoldier* AS4 = new AlienSoldier(5, 0, 40, 50, 4, Control);
	AlienSoldier* AS5 = new AlienSoldier(6, 0, 10, 50, 4, Control);
	Control->getAA()->AddAS(AS1);
	Control->getAA()->AddAS(AS2);
	Control->getAA()->AddAS(AS3);
	Control->getAA()->AddAS(AS4);
	Control->getAA()->AddAS(AS5);
	Control->getEA()->AddES(ES1);
	Control->Print();
	ES1->Attack();*/
	/*ES1->Attack();
	ES1->Attack();
	ES1->Attack();*/
	Control->Print();
	/*ES1->Attack();
	ES1->Attack();
	ES1->Attack();
	Control->Print();
	Control->Print();*/


	//Earth Gunnery
	/*EarthGunnery* EG = new EarthGunnery(1, 0, 60, 100, 4, Control);

	AlienDrone* AD1 = new AlienDrone(2, 0, 10, 50, 0, Control);
	AlienDrone* AD2 = new AlienDrone(3, 0, 20, 50, 0, Control);
	AlienDrone* AD3 = new AlienDrone(4, 0, 30, 50, 0, Control);
	AlienDrone* AD4 = new AlienDrone(5, 0, 5, 50, 0, Control);
	AlienMonster* AM1 = new AlienMonster(6, 0, 40, 50, 0, Control);
	AlienMonster* AM2 = new AlienMonster(7, 0, 50, 50, 0, Control);

	Control->getEA()->AddEG(EG);
	Control->getAA()->AddAM(AM1);
	Control->getAA()->AddAM(AM2);
	Control->getAA()->AddAD(AD1);
	Control->getAA()->AddAD(AD2);
	Control->getAA()->AddAD(AD3);
	Control->getAA()->AddAD(AD4);
	Control->Print(EG);

	EG->Attack();
	Control->Print(EG);
	EG->Attack();
	Control->Print(EG);*/

	//Alien Monster

	AlienMonster* AM = new AlienMonster(1, 0, 60, 100, 7, Control);

	EarthSoldier* ES1 = new EarthSoldier(2, 0, 10, 50, 0, Control);
	EarthSoldier* ES2 = new EarthSoldier(3, 0, 20, 50, 0, Control);
	EarthSoldier* ES3 = new EarthSoldier(4, 0, 30, 50, 0, Control);

	EarthTank* ET1 = new EarthTank(5, 0, 5, 50, 0, Control);
	EarthTank* ET2 = new EarthTank(6, 0, 40, 50, 0, Control);
	EarthTank* ET3 = new EarthTank(7, 0, 50, 50, 0, Control);

	Control->getAA()->AddAM(AM);
	Control->getEA()->AddES(ES1);
	/*Control->getEA()->AddES(ES2);
	Control->getEA()->AddES(ES3);
	Control->getEA()->AddET(ET1);
	Control->getEA()->AddET(ET2);
	Control->getEA()->AddET(ET3);*/
	Control->Print();

	AM->Attack();
	Control->Print();


	//Drone test
	/*AlienDrone* AD1 = new AlienDrone(1, 0, 60, 100, 6, Control);
	AlienDrone* AD2 = new AlienDrone(2, 0, 60, 100, 6, Control);

	EarthGunnery* EG1 = new EarthGunnery(3, 0, 30, 100, 0, Control);
	EarthGunnery* EG2 = new EarthGunnery(4, 0, 10, 100, 0, Control);
	EarthGunnery* EG3 = new EarthGunnery(5, 0, 20, 100, 0, Control);
	EarthGunnery* EG4 = new EarthGunnery(6, 0, 10, 100, 0, Control);

	EarthTank* ET1 = new EarthTank(7, 0, 5, 100, 0, Control);
	EarthTank* ET2 = new EarthTank(8, 0, 40, 100, 0, Control);
	EarthTank* ET3 = new EarthTank(9, 0, 30, 100, 0, Control);
	EarthTank* ET4 = new EarthTank(10, 0, 20, 100, 0, Control);

	Control->getAA()->AddAD(AD1);
	Control->getAA()->AddAD(AD2);

	Control->getEA()->AddEG(EG1);
	Control->getEA()->AddEG(EG2);
	Control->getEA()->AddEG(EG3);
	Control->getEA()->AddEG(EG4);

	Control->getEA()->AddET(ET1);
	Control->getEA()->AddET(ET2);
	Control->getEA()->AddET(ET3);
	Control->getEA()->AddET(ET4);
	Control->Print(AD1);
	Control->Print(AD2);

	AD1->Attack();
	AD2->Attack();
	Control->Print(AD1);
	Control->Print(AD2);
	AD1->Attack();
	AD2->Attack();
	Control->Print(AD1);
	Control->Print(AD2);
	AD1->Attack();
	AD2->Attack();
	Control->Print(AD1);
	Control->Print(AD2);
	AD1->Attack();
	AD2->Attack();
	Control->Print(AD1);
	Control->Print(AD2);*/
}