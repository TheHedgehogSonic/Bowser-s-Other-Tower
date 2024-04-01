#include "BobombDud.h"

BobombDud::BobombDud() {
	this->name = "Bob-omb";
	this->hint = "This was also meant as a free room.";
	this->hp = 9999;
	this->hpMax = 9999;
	this->attack = 4;
	this->defense = 5;
	this->coinLoot = 1;
	this->level = false;
	this->turns = 3;
}

BobombDud::~BobombDud() {

}

void BobombDud::introduce() {
	std::cout << "Oh, OK. A big Bob-omb. That's definitely a lot more normal than what you've been seeing so far." << std::endl;
}

void BobombDud::jumpResponse1(short damage) {
	std::cout << "You jump on the Bob-omb for " << -damage << " damage" << std::endl;
}

void BobombDud::jumpResponse2(short damage) {
	std::cout << "and another " << -damage << " damage." << std::endl;
}

void BobombDud::hammerResponse(short damage) {
	std::cout << "Your hammer deals a measly " << -damage << " damage." << std::endl;
}

void BobombDud::action(Character& victim) {
	turns--;

	if (turns > 0) {
		std::cout << turns << " more turns until self destruct. Hurry!" << std::endl;
	}
	else {
		std::cout << "Wait, that thing was a dud this whole time!?" << std::endl;
		hp = 0;
	}
}
