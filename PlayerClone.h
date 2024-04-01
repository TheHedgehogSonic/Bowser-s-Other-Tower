#pragma once
#include "Enemy.h"

class PlayerClone : public Enemy {
public:
	PlayerClone(short hp, short hpm, short atk, short def, short cl);
	~PlayerClone();
	void introduce();
	void jumpResponse1(short damage);
	void jumpResponse2(short damage);
	void hammerResponse(short damage);
	void action(Character& victim);
};