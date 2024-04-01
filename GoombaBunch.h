#pragma once
#include "Enemy.h"

class GoombaBunch : public Enemy {
public:
	GoombaBunch();
	~GoombaBunch();
	void introduce();
	void jumpResponse1(short damage);
	void jumpResponse2(short damage);
	void hammerResponse(short damage);
	void action(Character& victim);
};