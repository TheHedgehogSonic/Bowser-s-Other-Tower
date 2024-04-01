#pragma once
#include "Character.h"
#include "Enemy.h"
#include "Item.h"

class Hero : public Character {
public:
	Hero(); // Derived constructor
	Hero(short hpm, short spm, short atk, short def, short luck);
	Item getItem(short dex);
	short getSP();
	short getSPMax();
	short getLuck();
	short getLevel();
	short getCoins();
	short getPowerUses();
	bool logicIsBreakable();
	bool brokeLogic();
	void addToSP(short val);
	void addToSPMax(short val);
	void addToLuck(short val);
	void addToLevel(short val);
	void addToCoins(short val);
	void addToPowerUses(short val);
	void setSP(short val);
	void setSPMax(short val);
	void setLuck(short val);
	void setLevel(short val);
	void setCoins(short val);
	void setPowerUses(short val);
	void setLogicBroken(bool set);
	void setBreakableLogic(bool set);
	void jump(Enemy& target);
	void hammer(Enemy& target);
	void powerAttack(Enemy& target);
	void addItem(short t);
	short useItem(Hero& user, Enemy& victim, short slot);
	void setItem(short dex, short val);
	void shiftItems(short start);
	short getItemSlot();
	void setItemSlot(short val);
	void clearInventory();
	void print(); // Shows the stats, coins and level of your character
private:
	Item inventory[15];
	short sp, spMax; // Special points
	short luck;
	short level;
	short coins;
	short powerUses;
	short itemSlot; // The active item slot for writing
	bool breakableLogic; // If you can
	bool logicBroken; // The letter P on the Cheep Cheep
};