#pragma once
#include "Enemy.h"

class KoopaDance : public Enemy {
public:
	KoopaDance(short d);
	~KoopaDance();
	void introduce();
	void jumpResponse1(short damage);
	void jumpResponse2(short damage);
	void hammerResponse(short damage);
	void action(Character& victim);
private:
	short dances;
};