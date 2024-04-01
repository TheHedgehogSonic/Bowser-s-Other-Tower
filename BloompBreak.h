#pragma once
#include "Enemy.h"

class BloompBreak : public Enemy {
public:
	BloompBreak(short f);
	~BloompBreak();
	void introduce();
	void jumpResponse1(short damage);
	void jumpResponse2(short damage);
	void hammerResponse(short damage);
	void action(Character& victim);
private:
	short forfeitCount;
};