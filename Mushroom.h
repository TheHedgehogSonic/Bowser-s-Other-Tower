#pragma once
#include "Enemy.h"

class Mushroom : public Enemy {
public:
	Mushroom();
	~Mushroom();
	void introduce();
	void jumpResponse1(short damage);
	void jumpResponse2(short damage);
	void hammerResponse(short damage);
	void action(Character& victim);
};