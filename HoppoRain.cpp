#include "HoppoRain.h"

HoppoRain::HoppoRain(short i) {
	this->name = "Hoppo";
	this->hint = "Bouncing seemed like it worked... maybe there's a pattern to those pesky Spinies.";
	this->hp = 5;
	this->hpMax = 6;
	this->attack = 0;
	this->defense = 9999;
	this->coinLoot = 0;
	this->level = false;
	this->interval = i;
	this->spinyTimer = i;
}

HoppoRain::~HoppoRain() {
	// Destruct
}

void HoppoRain::introduce() {
	std::cout << "OH, GRAMBI!! It's a whole bunch of Hoppos raining from an open ceiling! Like... so many, you're drowning!" << std::endl;
}

void HoppoRain::jumpResponse1(short damage) {
	std::cout << "You bounce on a Hoppo, ";
}

void HoppoRain::jumpResponse2(short damage) {
	if (spinyTimer > 0) {
		hp--;
		std::cout << "and you're able to gain some more height to the exit!" << std::endl;
	}
	else {
		hp++;
		std::cout << "What the!? A camouflaged Spiny reveals itself! You lose height from the shocking pain." << std::endl;
	}
}

void HoppoRain::hammerResponse(short damage) {
	std::cout << "You knock away the Hoppo headed your way. This neither gains nor loses you height." << std::endl;
}

void HoppoRain::action(Character& victim) {
	std::cout << "The Hoppos crash into you sending you bouncing... not that it's very effective." << std::endl;
	spinyTimer = (spinyTimer > 0 ? spinyTimer - 1 : interval);

	if (hp >= hpMax) {
		std::cout << "The backwards bounce landed you in the pit of Hoppos where you drown and die." << std::endl;
		victim.setHP(0);
	}
}
