#include "Game.h"
#include <iostream>
#include <windows.h>
using namespace std;

Game::Game()
{

	
	ChooseMode();
	Game* gameptr = this;
	AA = new AlienArmy(gameptr);
	EA = new EarthArmy(gameptr);
	randgen = new RandGen(gameptr);
	LoadFromFile();
}

void Game::ChooseMode()
{
	bool exit = false;
	while (!exit) {
		cout << "Choose Program Mode:" << endl << "1)Interactive Mode " << endl << "2) Silent Mode\n";
		cin >> ProgramMode;
		if (ProgramMode == 1 || ProgramMode == 2) {
			exit = true;
		}
		else {
			cout << "Error Choice invalid " << endl;
		}
	}
}
int Game::getSelectedMode() {
	return ProgramMode;
}

void Game::addKilled(ArmyUnit* AU)
{
	if (AU->getID() != 0) {
		KilledList.enqueue(AU);
		KilledCount++;
	}
	return;
}

bool Game::RemoveES_UML(EarthSoldier*& ES, int& pri)
{
	bool status = UML_ES.dequeue(ES, pri);
	UML_ES_Count--;
	if (UML_ES_Count < 0)
	{
		UML_ES_Count = 0;
	}
	return status;
}

bool Game::RemoveET_UML(EarthTank*& ET)
{
	bool status = UML_ET.dequeue(ET);
	UML_ET_Count--;
	if (UML_ET_Count < 0)
	{
		UML_ET_Count = 0;
	}
	return status;
}

void Game::PrintUML()
{
	cout << u8"\n🚑🚑🚑🚑🚑🚑🚑🚑🚑🚑🚑🚑🚑🚑🚑🚑 Units Maintenance List 🚑🚑🚑🚑🚑🚑🚑🚑🚑🚑🚑🚑🚑🚑🚑🚑\n";
	cout << u8"👮 " << UML_ES_Count  << " ES units ";
	if (UML_ES.isEmpty())
	{
		cout << "[ Empty ]\n";
	}
	else
	{
		PriorityNode<EarthSoldier*>* Temp1 = UML_ES.head;
		//int Pri;
		cout << "[ " << Temp1->getItem(UML_ES.head->pri)->getID();
		Temp1 = Temp1->getNext();
		while (Temp1 != nullptr)
		{
			cout << ", " << Temp1->getItem(UML_ES.head->pri)->getID();
			Temp1 = Temp1->getNext();
		}
		cout << " ]\n";
	}
	cout << u8"🚜 " << UML_ET_Count << " ET units ";
	if (UML_ET.isEmpty())
	{
		cout << "[ Empty ]\n";
	}
	else
	{
		Node<EarthTank*>* Temp2 = UML_ET.front;
		cout << "[ " << Temp2->getItem();
		Temp2 = Temp2->getNext();
		while (Temp2 != nullptr)
		{
			cout << ", " << Temp2->getItem();
			Temp2 = Temp2->getNext();
		}
		cout << " ]\n";
	}
}


void Game::PrintKilled()
{
	cout << u8"⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️ Killed/Destructed Units ⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️\n";
	cout << u8"☠️ " << KilledCount << " units ";
	{
		if (KilledList.isEmpty())
		{
			cout << "[ Empty ]\n";
			return;
		}
		Node<ArmyUnit*>* Temp = KilledList.front;
		cout << "[ " << Temp->getItem();
		Temp = Temp->getNext();
		while (Temp != NULL)
		{
			cout << ", " << Temp->getItem();
			Temp = Temp->getNext();
		}
		cout << " ]\n";
	}
}

int Game::GetTimeStep() {
	return TimeStep;
};

bool Game:: SelectFilename() {
	int filenum;
	bool validstat = false;
	WE_WA = "bweak.txt", WE_MA = "EWeakAMod.txt", WE_SA = "EWeakAStrong.txt", SE_WA = "EStrongAWeak.txt", SE_MA = "EStrongAMod.txt", SE_SA = "bstrong.txt";
	cout << "Choose War Conditions (Enter a number)  " << endl << "1) Weak Earth VS Weak Aliens"<<endl<<"2) Weak Earth VS Moderate Aliens" <<endl<<"3) Weak Earth VS Strong Aliens" << endl << "4) Strong Earth VS Weak Aliens"<<endl<<"5) Strong Earth VS Moderate Aliens"<<endl<<"6) Strong Earth VS Strong Aliens " << endl;
	cin >> filenum;
	switch (filenum)
	{
	case 1: {
		Filename = WE_WA;
		validstat = true;
		break;
	}case 2: {
		Filename = WE_MA;
		validstat = true;
		break;
	}case 3: {
		Filename = WE_SA;
		validstat = true;
		break;
	}case 4: {
		Filename = SE_WA;
		validstat = true;
		break;
	}case 5: {
		Filename = SE_MA;
		validstat = true;
		break;
	}case 6: {
		Filename = SE_SA;
		validstat = true;
		break;
	}
	default:
		validstat = false;
		break;
	}
	return validstat;
}
void Game::LoadFromFile() {
	bool exit = false, FileError = false, filevalid=true;
	while (!exit) {
		filevalid = SelectFilename();
		if (filevalid) {
			ifstream myfile(Filename);
			int N, ES, ET, EG, HU, AS, AM, AD, Prob;
			int EUPmin, EUPmax, EUHmin, EUHmax, EUACapmin, EUACapmax;
			int AUPmin, AUPmax, AUHmin, AUHmax, AUACapmin, AUACapmax;
			myfile >> N >> ES >> ET >> EG >> HU >> AS >> AM >> AD >> Prob;
			string bufferE1, bufferE2, bufferE3, bufferA1, bufferA2, bufferA3;
			myfile >> bufferE1 >> bufferE2 >> bufferE3 >> bufferA1 >> bufferA2 >> bufferA3;
			try {
				separatenums(bufferE1, EUPmin, EUPmax);
				separatenums(bufferE2, EUHmin, EUHmax);
				separatenums(bufferE3, EUACapmin, EUACapmax);
				separatenums(bufferA1, AUPmin, AUPmax);
				separatenums(bufferA2, AUHmin, AUHmax);
				separatenums(bufferA3, AUACapmin, AUACapmax);
			}
			catch (...) {
				cout << "error in input file please enter the right format";
				FileError == true;
			}
			randgen->Setprob(N, ES, ET, EG, HU, AS, AM, AD, Prob);
			randgen->SetAU(AUPmin, AUPmax, AUHmin, AUHmax, AUACapmin, AUACapmax);
			randgen->SetEU(EUPmin, EUPmax, EUHmin, EUHmax, EUACapmin, EUACapmax);
			if (HU <= 5 && !FileError) {
				exit = true;
			}
			else if (HU > 5) {
				cout << "Heal Unit probability exceeded the limit,change its value";
			}
		}
		else {
			cout << "INVALID CHOICE CHOOSE AGAIN!" << endl << endl;
		}
			
		
		
	}
};

void Game:: GenUnits() {
	randgen->UnitsGenerator();
};

void Game::separatenums(string input, int& min, int& max) {
	int stop = 0, count = 0;
	string fnum, snum;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] != '-' && stop == 0) {
			fnum += input[i];
		}
		else if (input[i] != '-' && stop == 1) {
			snum += input[i];
		}
		else {
			stop = 1;
		}
	}
	min = stoi(fnum);
	max = stoi(snum);
};
void Game::Proceed() {
	if (ProgramMode == 1)
	{
		system("pause");
		TimeStep++;
		randgen->SetTimeStep(TimeStep);
	}
	else
	{
		TimeStep++;
		randgen->SetTimeStep(TimeStep);
	}
}
int Game::RandNum() {
	return randgen->NumGen();
}

void Game::AddUnit(ArmyUnit* UnitPtr) {
	if (UnitPtr == nullptr)
	{
		return;
	}
	int Type = UnitPtr->getType();//ES=0,ET=1,EG=2,AS=3,AM=4,AD=5 HU=6
	if((Type>= 0 && Type<=2) || Type==6){
		EA->AddUnit(UnitPtr);
	}
	else if (Type >= 3 && Type <= 5) {
		AA->AddToList(UnitPtr);
	}
	
}

bool Game::RemoveUnit(ArmyUnit*& UnitPtr,int Type)
{
	//ES=0,ET=1,EG=2,AS=3,AM=4,AD=5,HU=6
	bool stat=false;
	switch (Type)
	{
	case 0: {
		stat=EA->RemoveES((EarthSoldier*&)UnitPtr);
		break;
	}case 1: {
		stat=EA->RemoveET((EarthTank*&)UnitPtr);
		break;
	}case 2: {
		stat=EA->RemoveEG((EarthGunnery*&)UnitPtr);
		break;
	}case 3: {
		stat=AA->RemoveAS((AlienSoldier*&)UnitPtr);
		break;
	}case 4: {
		stat=AA->RemoveAM((AlienMonster*&)UnitPtr);
		break;
	}case 5: {
		stat=AA->RemoveAD((AlienDrone*&)UnitPtr); 
		break;
	}case 6: {
		stat = EA->RemoveHU((HealUnit*&)UnitPtr);
		break;
	}
	default:
		break;
	}
	return stat;
}

AlienMonster* Game::PickAM()
{ 
	return AA->PickAM();
}

void Game::pickAD(ArmyUnit*& UnitPtr1, ArmyUnit*& UnitPtr2)
{
	AA->PickAD((AlienDrone*&)UnitPtr1, (AlienDrone*&)UnitPtr2);
	
}

EarthGunnery* Game::pickEG()
{
	return EA->PickEG();
}

HealUnit* Game::pickHU()
{
	return EA->PickHU();
}

void Game::Simulate()
{
	
	if (ProgramMode==1)
	{
		for (int i = 0; i < 500; i++) {
			if (i == 0) {
				GenUnits();
			}
			Print1();
			EarthAttack();
			AlienAttack();
			Print2();
			if (AA->getAScount() == 0 && AA->getAMcount() == 0 && AA->getADcount() == 0 && i>40) {
				cout << "CONGRATS EARTH ARMY WINNNSS"<<endl;
				break;
			}
			else if (EA->getEScount() == 0 && EA->getETcount() == 0 && EA->getEGcount() == 0 && i>40) {
				cout << " GOT DEFEATED BY THE ALIEN ARMY " << endl;
				break;
			}
			else if (i == 499) {
				cout << "Draw" << endl;
				break;
			}
			Proceed();
			if (i != 0) {
				GenUnits();
			}
		}
		GetOutFileName();
		GenOutFile();
	}
	else if (ProgramMode == 2)
	{
		
		for (int i = 0; i < 500; i++) {// 40 timestep
			if (i == 0) {
				GenUnits();
			}
			EarthAttack();
			AlienAttack();
			system("CLS");
			if (AA->getAScount() == 0 && AA->getAMcount() == 0 && AA->getADcount() == 0 && i > 40) {
				cout << "CONGRATS EARTH ARMY WINNNSS" << endl;
				WarState = 1;
				break;
			}
			else if (EA->getEScount() == 0 && EA->getETcount() == 0 && EA->getEGcount() == 0 && i > 40) {
				cout << " GOT DEFEATED BY THE ALIEN ARMY " << endl;
				WarState = 2;
				break;
			}
			else if (i == 499) {
				cout << "Draw" << endl;
				WarState = 3;
				break;
			}
			Proceed();
			if (i != 0) {
				GenUnits();
			}
		}
		
		cout << "Silent Mode" << endl;
		cout << "Simulation Starts..." << endl;
		cout << "Simulation ends, Output file is created" << endl;
		GetOutFileName();
		GenOutFile();
	}
}

void Game::addUML_ET(EarthTank*& ET)
{
	if (ET->getID() != 0) {
		UML_ET.enqueue(ET);
		UML_ET_Count++;
	}
	return;
}

void Game::addUML_ES(EarthSoldier*& ES)
{
	if (ES->getID() != 0)
	{
		UML_ES.enqueue(ES,(200 - ES->getHealth()));
		UML_ES_Count++;
	}
}

void Game::EarthAttack()
{
	bool valid=true;
	ArmyUnit* UnitPtr;
	for (int i = 0; i < 2; i++) {
		valid = RemoveUnit(UnitPtr, i);
		if (valid) {
			if (i == 0) {
				dynamic_cast<EarthSoldier*>(UnitPtr)->Attack();
			}
			if (i == 1) {
				dynamic_cast<EarthTank*>(UnitPtr)->Attack();
			}
			AddUnit(UnitPtr);
		}
	}
	UnitPtr = pickEG();
	valid = RemoveUnit(UnitPtr, 2);
	if (valid) {
		dynamic_cast<EarthGunnery*>(UnitPtr)->Attack();
		AddUnit(UnitPtr);
	}
	
	valid=RemoveUnit(UnitPtr, 6);
	if (valid)
	{
		dynamic_cast<HealUnit*>(UnitPtr)->Attack();
		AddUnit(UnitPtr);
	}
	cout << endl;
	
}

void Game::AlienAttack()
{
	bool valid1 = true, valid2 = true;
	ArmyUnit* UnitPtr1;
	ArmyUnit* UnitPtr2;

	valid1 = RemoveUnit(UnitPtr1, 3);
	if (valid1) {
		dynamic_cast<AlienSoldier*>(UnitPtr1)->Attack();
		AddUnit(UnitPtr1);
	}
	

	UnitPtr1=PickAM();
	valid1 = RemoveUnit(UnitPtr1,4);
	if (valid1) {
		dynamic_cast<AlienMonster*>(UnitPtr1)->Attack();		
		AddUnit(UnitPtr1);
	}
	

	pickAD(UnitPtr1, UnitPtr2);
	if (UnitPtr1 && UnitPtr2) {
		valid1 = RemoveUnit(UnitPtr1, 5);
		valid2 = RemoveUnit(UnitPtr2, 5);
		dynamic_cast<AlienDrone*>(UnitPtr1)->Attack();
		dynamic_cast<AlienDrone*>(UnitPtr2)->Attack();
		AddUnit(UnitPtr1);
		AddUnit(UnitPtr2);
	}
	cout << endl;
}



void Game::Print1()
{
	cout << u8"⏳⌛ Current TimeStep: " << TimeStep << endl;
	EA->Print();
	AA->Print();
	cout << u8"\n⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔  Units fighting at current timestep ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔ ⚔\n";
}

void Game::Print2()
{
	PrintKilled();
	PrintUML();
	cout << endl << endl;
}

int Game::getUML_ES_Count()
{
	return UML_ES_Count;
}

int Game::getUML_ET_Count()
{
	return UML_ET_Count;
}

void Game::setAttackingUnit(ArmyUnit* AU)
{
	AttackingUnit = AU;
}

ArmyUnit* Game::getAttackingUnit()
{
	return AttackingUnit;
}

Queue<AlienSoldier*>* Game::getASArmy()
{
	return AA->getASArmy();
}

Queue<EarthSoldier*>* Game::getESArmy()
{
	return EA->getESArmy();
}

Stack<EarthTank*>* Game::getETArmy()
{
	return EA->getETArmy();
}

PriorityQueue<EarthGunnery*>* Game::getEGArmy()
{
	return EA->getEGArmy();
}

Deque<AlienDrone*>* Game::getADArmy()
{
	return AA->getADArmy();
}

AlienMonster** Game::getAMArmy()
{
	return AA->getAMArmy();
}

Stack<HealUnit*>* Game::getHUArmy()
{
	return EA->getHUArmy();
}

PriorityQueue<EarthSoldier*> Game::getES_UML()
{
	return UML_ES;
}

Queue<EarthTank*> Game::getET_UML()
{
	return UML_ET;
}

void Game::Healed()
{
	HealedCount++;
}

AlienArmy* Game::getAA()
{
	return AA;
}

EarthArmy* Game::getEA()
{
	return EA;
}

bool Game:: IsFileName(string input) {
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == 47 || input[i] == 58 || input[i] == 92 || input[i] == 124 || input[i] == 60 || input[i] == 62 || input[i] == 63 || input[i] == 42 || input[i] == 34) {
			return false;
		}
	}
	return true;
}

void Game:: GetOutFileName() {
	bool exit = false;
	while (!exit) {
		cout << "Enter File Name: ";
		cin >> OutFileName;
		if (IsFileName(OutFileName)) {
			OutFileName += ".txt";
			exit = true;
		}
		else {
			cout << "enter a valid filename"<<endl;
		}
	}
}

void Game::GenOutFile()
{
	ArmyUnit* UnitPtr;
	int TD, TJ, TA, DF, Dd, TB, TES, TET, TEG, THU, TAS, TAM, TAD;

	EA->GetTotalNums(TES, TET, TEG, THU);
	AA->getTotalNums(TAS, TAM, TAD);

	int TDES = TES - EA->getEScount(), TDET = TET - EA->getETcount(), TDEG = TEG - EA->getEGcount();
	int TDHU= THU - EA->getHUcount(), TDAS = TAS - AA->getAScount(), TDAM = TAM - AA->getAMcount(), TDAD = TAD - AA->getADcount();

	int PDES = (TDES / TES) * 100, PDET = (TDET / TET) * 100, PDEG = (TDEG / TEG) * 100, PDHU = (TDHU / THU) * 100;
	int PDAS = (TDAS / TAS) * 100, PDAM = (TDAM / TAM) * 100, PDAD = (TDAD / TAD) * 100;

	int TEU = TES + TET + TEG;
	int TAU = TAS + TAM + TAD;

	int TDEU = TDES + TDET + TDEG;
	int TDAU = TDAS + TDAM + TDAD;

	int PTDRTUE = (TDEU / TEU) * 100;
	int PTDRTUA = (TDAU / TAU) * 100;

	int TDFE=0, TDdE=0, TTBE=0;
	int TDFA=0, TDdA=0, TTBA=0;

	int countDE=0,countDA=0;

	int AVGDFE=0, AVGDdE=0, AVGTBE=0, AVGDFA=0, AVGDdA=0, AVGTBA=0;


	int Totalhealed=0;

	int DFDbRA = 0, DFDbRE = 0,DdDbRA=0, DdDbRE=0;


	ofstream myfile(OutFileName);
	if (myfile.is_open()) {
		myfile << "TD " << "ID " << "TJ " << "DF " << "Dd " << "Db" << endl;
		while(KilledList.dequeue(UnitPtr)){
			TD = UnitPtr->GetDistructTime();
			TJ = UnitPtr->getJoinTime();
			TA = UnitPtr->GetFirstShotTime();
			DF = TA - TJ;
			Dd = TD - TA;
			TB = TD - TJ;
			
			if (UnitPtr->getType()>=0 && UnitPtr->getType() < 3) {
				myfile << TD << " " << UnitPtr->getID() << " " << TJ << " " << DF << " " << Dd << " " << TB << endl;
				TDFE += DF;
				TDdE += Dd;
				TTBE += TB;
				countDE++;
			}
			else if (UnitPtr->getType() > 2 && UnitPtr->getType() < 6) {
				myfile << TD << " " << UnitPtr->getID() << " " << TJ << " " << DF << " " << Dd << " " << TB << endl;
				TDFA += DF;
				TDdA += Dd;
				TTBA += TB;
				countDA++;
			}
		}
		if (countDE != 0) {
			AVGDdE = TDdE / countDE;
			AVGDFE = TDFE / countDE;
			AVGTBE = TTBE / countDE;
			DFDbRE = TDFE / TTBE;
			DdDbRE = TDdE / TTBE;
		}
		if (countDA!=0) {
			AVGDdA = TDdA / countDA;
			AVGDFA = TDFA / countDA;
			AVGTBA = TTBA / countDA;
			DFDbRA = TDFA / TTBA;
			DdDbRA = TDdA / TTBA;
		}

		if (WarState == 1) {
			myfile << "Earth Army Wins" << endl;
		}
		else if (WarState == 2) {
			myfile << "Alien Army Wins" << endl;
		}
		else if(WarState==3)
		{
			myfile << "Draw" << endl;
		}

		myfile << "Earth Army"<<endl;

		myfile <<"Total Earth Soliders: "<< TES << "  "<< "Total Earth Tanks: "<<  TET << " " << "Total Earth Gunnery: " << TEG << endl;
		myfile <<"Percentage Of Destructed Units Relative To Their Total:"<<endl<<"Earth Soliders: " << PDES << " " << "Earth Tanks: " << PDET << " " << "Earth Gunnery: " << PDEG << endl;
		myfile <<"Percentage Of Total Destructed Units Relative To Their Total:" << PTDRTUE << endl;
		myfile << AVGDFE << " " << AVGDdE << " " << AVGTBE << endl;
		myfile << DFDbRE << " " << DdDbRE <<endl;
		myfile << "Total Healed ratio: " << Totalhealed / TEU << endl;

		myfile << "Alien Army"<<endl;


		myfile <<"Total Alien Soldiers: " <<TAS << "  "<<"Total Alien Monester: " << TAM << " "<<"Total Alien Drones: " << TAD << endl;
		myfile << "Percentage Of Destructed Units Relative To Their Total : "<<"Alien Soldiers: "<<PDAS << " "<<"Alien Monesters: " << PDAM << " "<<"Alien Drones: " << PDAD << endl;
		myfile << "Percentage Of Total Destructed Units Relative To Their Total:"<<PTDRTUA << endl;
		myfile << AVGDFA << " " << AVGDdA << " " << AVGTBA << endl;
		myfile << DFDbRA << " " << DdDbRA <<endl;

		


	}

}
