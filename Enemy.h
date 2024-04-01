#pragma once
#include "Character.h"

class Enemy abstract : public Character {
public:
	Enemy(); // Default constructor
	Enemy(short hpm, short atk, short def, std::string n, std::string h, short c, bool l); // Conditional constructor
	~Enemy();
	void print();
	virtual void introduce() abstract;
	std::string getName();
	std::string getHint();
	short getCoinLoot();
	bool hasLevel();
	virtual void jumpResponse1(short damage);
	virtual void jumpResponse2(short damage);
	virtual void hammerResponse(short damage);
	virtual void powerResponse(short damage);
	virtual void action(Character& victim); // Attack the hero
	// Unnecessaries
	virtual void addToPowerUses(short val);
	virtual bool logicIsBreakable();
	virtual void setLogicBroken(bool set);
	virtual short getStar();
	virtual bool starIsGuessed(short dex);
	virtual void setStarGuessed(short dex, bool set);
protected:
	std::string name;
	std::string hint;
	short coinLoot;
	bool level; // If the enemy has a level up for you
};