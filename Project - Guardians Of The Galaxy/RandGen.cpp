#include "RandGen.h"
#include<string>

int RandGen::EunitID = 1;
int RandGen::AunitID = 2000;
int RandGen::SunutID = 7000;
RandGen::RandGen(Game*&gameptr) {
    GamePtr = gameptr;
    TimeStep = 0;
     N = 0, ES = 0, ET = 0, EG = 0, HU = 0, AS = 0, AM = 0, AD = 0, Prob = 0,EarthUPowermin = 0, EarthUPowermax = 0, EarthUHealthmin = 0, EarthUHealthmax = 0, EarthUAttackCapmin = 0, EarthUAttackCapmax = 0, AlienUPowermin = 0, AlienUPowermax = 0, AlienUHealthmin = 0, AlienUHealthmax = 0, AlienUAttackCapmin = 0, AlienUAttackCapmax = 0;
}

void RandGen::Setprob(int n, int es, int et, int eg,int hu, int as, int am, int ad, int prob ) {
    N = n;
    ES = es;
    ET = et;
    EG = eg;
    HU = hu;
    AS = as;
    AM = am;
    AD = ad;
    Prob=prob;
}
void RandGen::SetEU(int EUPmin,int EUPmax,int EUHmin,int EUHmax,int EUACapmin,int EUACapmax) {
    EarthUPowermin = EUPmin;
    EarthUPowermax=EUPmax;
    EarthUHealthmin =EUHmin ;
    EarthUHealthmax=EUHmax;
    EarthUAttackCapmin = EUACapmin;
    EarthUAttackCapmax=EUACapmax;


}
void RandGen::SetAU(int AUPmin,int AUPmax,int AUHmin,int AUHmax,int AUACapmin,int AUACapmax) {
    AlienUPowermin = AUPmin;
    AlienUPowermax = AUPmax;
    AlienUHealthmin = AUHmin;
    AlienUHealthmax = AUHmax;
    AlienUAttackCapmin = AUACapmin;
    AlienUAttackCapmax = AUACapmax;
}
void RandGen::UnitsGenerator() {
    ArmyUnit* UnitPtr;
    int randnumA = 0;
    int secondgen = 0;     //0 -> Earth, 1 -> Alien
    for (int j = 0; j < 2; j++) {
        randnumA = NumGen();
            if (randnumA <= Prob && secondgen == 1) {
                for (int i = 0; i < N; i++) {
                    UnitPtr=AGen();
                    GamePtr->AddUnit(UnitPtr);
                }
            }

        if (randnumA <= Prob && secondgen == 0) {
            for (int i = 0; i < N; i++) {
                UnitPtr=EGen();
                GamePtr->AddUnit(UnitPtr);
            }
           
        }
         secondgen = 1;
    }
};

ArmyUnit* RandGen::EGen() {
    ArmyUnit* UnitPtr = nullptr;
    int randnumB = NumGen();
    if (EunitID <= 999) {
        if (randnumB <= ES) {
            //gen ES
            UnitPtr = new EarthSoldier(EunitID, TimeStep, EUHealthGen(), EUPowerGen(), EUAttackCapGen(), GamePtr);
            EunitID++;
        }
        else if (randnumB <= ET + ES) {
            //gen ET
            UnitPtr = new EarthTank(EunitID, TimeStep, EUHealthGen(), EUPowerGen(), EUAttackCapGen(), GamePtr);
            EunitID++;
        }
        else if (randnumB <= EG + ET + ES)
        {
            //gen EG
            UnitPtr = new EarthGunnery(EunitID, TimeStep, EUHealthGen(), EUPowerGen(), EUAttackCapGen(), GamePtr);
            EunitID++;
        }
        else {
            //gen HU
            UnitPtr = new HealUnit(EunitID, TimeStep, EUHealthGen(), EUPowerGen(), EUAttackCapGen(), GamePtr);
            EunitID++;
        }
    }
    //return pointer to unit
    return UnitPtr;
};
ArmyUnit* RandGen::AGen() {
    ArmyUnit* UnitPtr=nullptr;
    int randnumB = NumGen();
    if (AunitID <= 2999) {
        if (randnumB <= AS) {
            //gen AS
            UnitPtr = new AlienSoldier(AunitID, TimeStep, AUHealthGen(), AUPowerGen(), AUAttackCapGen(), GamePtr);
            AunitID++;
        }
        else if (randnumB <= AM + AS) {
            //gen AM
            UnitPtr = new AlienMonster(AunitID, TimeStep, AUHealthGen(), AUPowerGen(), AUAttackCapGen(), GamePtr);
            AunitID++;
        }
        else {
            //gen AD
            UnitPtr = new AlienDrone(AunitID, TimeStep, AUHealthGen(), AUPowerGen(), AUAttackCapGen(), GamePtr);
            AunitID++;
        }
    }
    //return pointer to unit
    return UnitPtr;
};



int RandGen::NumGen() {
    return 1 + rand() % 100 ;
};

void RandGen::SetTimeStep(int num) {
    TimeStep = num;
};



int RandGen::EUPowerGen() {
    return  EarthUPowermin + (rand() % (EarthUPowermax-EarthUPowermin+1));
};
int RandGen::EUHealthGen() {
    return  EarthUHealthmin + (rand() % (EarthUHealthmax-EarthUHealthmin+1));
};
int RandGen::EUAttackCapGen() {
    return  EarthUAttackCapmin + (rand() % (EarthUAttackCapmax-EarthUAttackCapmin+1));
};
int RandGen::AUPowerGen() {
    return  AlienUPowermin + (rand() % (AlienUPowermax-AlienUPowermin+1));
};
int RandGen::AUHealthGen() {
    return  AlienUHealthmin + (rand() % (AlienUHealthmax-AlienUHealthmin+1));
};
int RandGen::AUAttackCapGen() {
    return  AlienUAttackCapmin + (rand() % (AlienUAttackCapmax-AlienUAttackCapmin+1));
};
/*int RandGen::SUPowerGen() {
    return  SaverUPowermin + (rand() % (SaverUPowermax - SaverUPowermin + 1));
};
int RandGen::SUHealthGen() {
    return  SaverUHealthmin + (rand() % (SaverUHealthmax - SaverUHealthmin + 1));
};
int RandGen::SUAttackCapGen() {
    return  SaverUAttackCapmin + (rand() % (SaverUAttackCapmax - SaverUAttackCapmin + 1));
};*/



