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
	/*srand(time(NULL));
	Queue<ArmyUnit*> ASTempList;
	Queue<ArmyUnit*> AMTempList;
	ArmyUnit* UnitPtr;
	ArmyUnit* UnitPtr2;

	string Filename;
	int num;
	cout << "enter file name: ";
	cin >> Filename;
	Game* Control = new Game(Filename);
	ES=0,ET=1,EG=2,AS=3,AM=4,AD=5
	for (int i = 1; i <= 50; i++) {
		Control->GenUnits();
		num = Control->RandNum();
		Control->Print();
		if (num <= 10) {
			Control->RemoveUnit(UnitPtr,0);
			Control->Print();
		}
		if (num > 10 && num <= 20)
		{
			bool flag = Control->RemoveUnit(UnitPtr, 1);
			Control->Print();
			if (flag) {
				Control->addKilled(UnitPtr);
			}
			Control->Print();
		}
		 if (num > 20 && num <= 30) {
			 UnitPtr = Control->pickEG();
			bool flag = Control->RemoveUnit(UnitPtr,2);        
			Control->Print();
			if (flag) {
				UnitPtr->setHealth((UnitPtr->getHealth() / 2));
				Control->AddUnit(UnitPtr);
			}
			Control->Print();
		 }
		if (num > 30 && num <= 40) {
			for (int j = 0; j < 5; j++) {
				Control->RemoveUnit(UnitPtr,3);
				UnitPtr->setHealth((UnitPtr->getHealth() / 2));
				ASTempList.enqueue(UnitPtr);
			}
			Control->Print();                        
			bool flag = false;
			for (int j = 0; j < 5; j++) {
				flag = ASTempList.dequeue(UnitPtr);
				if (flag) {
					Control->AddUnit(UnitPtr);
				}
			}
			Control->Print();
		}
		if (num > 40 && num <= 50) {
			for (int i = 0; i < 5; i++) {
				UnitPtr = Control->PickAM();
				bool flag1 = Control->RemoveUnit(UnitPtr, 4);
				if (flag1)
				{
					Control->RemoveUnit(UnitPtr,4);
					AMTempList.enqueue(UnitPtr);           
				}
			}
			Control->Print();
			bool flag = false;
			for (int i = 0; i < 5; i++) 
			{
				flag = AMTempList.dequeue(UnitPtr);
				if(flag){
					Control->AddUnit(UnitPtr);
				}
			}
			Control->Print();
		}
		if (num > 50 && num <= 60) {
			for (int i = 0; i < 3; i++) {
				Control->pickAD(UnitPtr, UnitPtr2);
				bool flag1 = Control->RemoveUnit(UnitPtr,5);
				if (flag1)
				{
					Control->addKilled(UnitPtr);                        
				}
				bool flag2 = Control->RemoveUnit(UnitPtr2,5);
				if (flag2)
				{
					Control->addKilled(UnitPtr);
				}
			}
			Control->Print();
		}
		 Control->Proceed();
	}*/
	srand(time(NULL));
	ArmyUnit* UnitPtr;
	ArmyUnit* UnitPtr2;

	string Filename;
	cout << "enter file name: ";
	cin >> Filename;
	Game* Control = new Game(Filename);
}