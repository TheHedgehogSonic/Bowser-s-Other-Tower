#pragma once
#include <iostream>

class Character abstract {
public:
	Character(); // Default constructor
	Character(short hpMax, short atk, short def);
	short getHP();
	short getHPMax();
	short getAttack();
	short getDefense();
	short getTempDef();
	bool isAlive();
	void addToHP(short val);
	void addToHPMax(short val);
	void addToAttack(short val);
	void addToDefense(short val);
	void addToTempDef(short val);
	void setHP(short val);
	void setHPMax(short val);
	void setAttack(short val);
	void setDefense(short val);
	void setTempDef(short val);
	virtual void print() abstract;
	// Unnecessaries
	virtual void addToPowerUses(short val) abstract;
	virtual bool logicIsBreakable() abstract;
	virtual void setLogicBroken(bool set) abstract;
protected:
	short hp, hpMax; // HP out of how much
	short attack; // Attack power
	short defense; // Defense against rivals
	short tempDef;
};