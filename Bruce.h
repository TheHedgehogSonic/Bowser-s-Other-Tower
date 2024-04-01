#pragma once
#include "Enemy.h"

class Bruce : public Enemy {
public:
	Bruce();
	~Bruce();
	void introduce();
	void jumpResponse1(short damage);
	void jumpResponse2(short damage);
	void hammerResponse(short damage);
	void action(Character& victim);
};