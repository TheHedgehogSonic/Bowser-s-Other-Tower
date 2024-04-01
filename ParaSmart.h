#pragma once
#include "Enemy.h"

class ParaSmart : public Enemy {
public:
	ParaSmart();
	~ParaSmart();
	void introduce();
	void jumpResponse1(short damage);
	void jumpResponse2(short damage);
	void hammerResponse(short damage);
	void action(Character& victim);
private:
	bool flying;
};