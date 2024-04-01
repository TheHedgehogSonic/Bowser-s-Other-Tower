#pragma once
#include "Character.h"
#include "Enemy.h"

class Item {
public:
	Item();
	Item(short t);
	static std::string showName(short dex);
	static short showPrice(short t);
	static bool getNoHeal();
	static void setNoHeal(bool set);
	short getPrice();
	std::string getName();
	short getType();
	void setType(short val);
	short action(Character& user, Enemy& victim);
	void operator=(const Item& right); // Shift items with ease
private:
	static std::string nameBank[5];
	static short price[5];
	static bool noHeal;
	std::string name;
	short type; // Item type
};