#pragma once
#include "Enemy.h"

class Alien : public Enemy {
public:
	Alien(short s); // Conditional
	~Alien();
	void introduce();
	void jumpResponse1(short damage); // Useless
	void jumpResponse2(short damage); // Useless
	void hammerResponse(short damage); // Used here as a response system for guessed stars
	void action(Character& victim);
	short getStar();
	bool starIsGuessed(short dex);
	void setStarGuessed(short dex, bool set);
private:
	short star;
	bool guessed[25];
};