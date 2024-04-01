#pragma once
#include "Enemy.h"

class HoppoRain : public Enemy {
public:
	HoppoRain(short i);
	~HoppoRain();
	void introduce();
	void jumpResponse1(short damage);
	void jumpResponse2(short damage);
	void hammerResponse(short damage);
	void action(Character& victim);
private:
	short interval;
	short spinyTimer;
};