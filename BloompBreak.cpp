#include "BloompBreak.h"

BloompBreak::BloompBreak(short f) {
	this->name = "Bloomp";
	this->hint = "Maybe if you can't deflate it, MORE air would make it pop! But how will you get more air... bend logic?";
	this->hp = 3;
	this->hpMax = 3;
	this->attack = 0;
	this->defense = 9999;
	this->coinLoot = 0;
	this->level = false;
	this->forfeitCount = f;
}

BloompBreak::~BloompBreak() {
	// Destructor
}

void BloompBreak::introduce() {
	std::cout << "The air is thick. Through the mist, a Bloomp shows its face, holding within its bod a key to the higher floors." << std::endl;
}

void BloompBreak::jumpResponse1(short damage) {
	if (damage) {
		std::cout << "You pump up the Bloomp to fill it with more air... ";
	}
	else {
		std::cout << "You jump on the Bloomp to let out some of its air... ";
	}
}

void BloompBreak::jumpResponse2(short damage) {
	if (damage) {
		std::cout << "It looks close to bursting!" << std::endl;
		hp--;
	}
	else {
		std::cout << "But it's quick to inflate back with the surrounding air." << std::endl;
	}
}

void BloompBreak::hammerResponse(short damage) {
	std::cout << "Your hammer didn't do much." << std::endl;
}

void BloompBreak::action(Character& victim) {
	if (forfeitCount) {
		forfeitCount--;
		std::cout << "The Bloomp crashes into you, bouncing you back... not that it was very effective." << std::endl;
	}
	else { // Out of tries
		std::cout << "Nothing's working. You've grown exhausted trying, as you turn back to revel in your loss." << std::endl;
		victim.setHP(0);
	}
}
