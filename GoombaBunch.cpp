#include "GoombaBunch.h"

GoombaBunch::GoombaBunch() {
	this->name = "Goomba Bunch";
	this->hint = "When in doubt, grab some shrooms from your inventory!";
	this->hp = 9999;
	this->hpMax = 9999;
	this->attack = 4;
	this->defense = 0;
	this->coinLoot = 100;
	this->level = true;
}

GoombaBunch::~GoombaBunch() {
	
}

void GoombaBunch::introduce() {
	std::cout << "Before you stands a WHOLE BUNCH OF GOOMBAS! Like, an entire room full. WOAH!!!" << std::endl;
}

void GoombaBunch::jumpResponse1(short damage) {
	std::cout << "You jump on one of the Goombas for " << -damage << " damage ";
}

void GoombaBunch::jumpResponse2(short damage) {
	std::cout << "and again for another " << -damage << "." << std::endl;
}

void GoombaBunch::hammerResponse(short damage) {
	std::cout << "Your hammer struck for total damage of " << -damage << " damage." << std::endl;
}

void GoombaBunch::action(Character& victim) {
	short damage = -attack + victim.getDefense() + victim.getTempDef();

	victim.addToHP(damage);
	std::cout << "The Goombas strike you for " << -damage << " damage." << std::endl;
}
