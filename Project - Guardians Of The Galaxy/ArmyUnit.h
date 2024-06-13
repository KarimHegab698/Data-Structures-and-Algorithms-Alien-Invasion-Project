#pragma once
#include <iostream>
using namespace std;
class Game;
class ArmyUnit
{
protected:
	enum Type {ES,ET,EG,AS,AM,AD,HU};
	Type type;
	int ID;
	int JoinTime;
	int FirstShotTime;
	int DistrucTime;

	int NumGotShot;
	Game* GameManager;
	int Health;
	int Power;
	int AttackCapacity;

public:
	virtual void Attack() = 0;

	int getType() const;
	int getID() const;
	int getJoinTime() const;
	int GetDistructTime();
	int GetFirstShotTime();
	int getHealth() const;
	int getPower() const;
	int getAttackCapacity() const;
	
	void setID(int id);
	void setJoinTime(int jointime);
	void setDistrucTime(int DST);
	void setFirstShotTime(int FST);
	void GotShot();

	int GetNumGotShot();

	void setHealth(int health);
	void setPower(int power);
	void setAttackCapacity(int attackcapacity);

};

static ostream& operator << (ostream& output, const ArmyUnit *AU)
{
	output << AU->getID();
	return output;
}
