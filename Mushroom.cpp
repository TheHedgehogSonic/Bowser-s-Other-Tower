#include "Mushroom.h"

Mushroom::Mushroom() {
	this->name = "Mushroom";
	this->hint = "If only there was a weapon you could use to outdamage that pesky healer.";
	this->hp = 49;
	this->hpMax = 9999;
	this->attack = 7;
	this->defense = 0;
	this->coinLoot = 0;
	this->level = true;
}

Mushroom::~Mushroom() {
	// Kaboom thingy
}

void Mushroom::introduce() {
	std::cout << "It's a Mushroom, but something seems off. This one is a slightly darker red and it looks angry. Could that mean... No!" << std::endl;
}

void Mushroom::jumpResponse1(short damage) {
	std::cout << "You jump on the Mushroom for " << -damage << " damage, ";
}

void Mushroom::jumpResponse2(short damage) {
	std::cout << "and again for " << -damage << " more." << std::endl;
}

void Mushroom::hammerResponse(short damage) {
	std::cout << "You hammer the Mushroom for " << -damage << " damage." << std::endl;
}

void Mushroom::action(Character& victim) {
	short damage = -attack + victim.getDefense() + victim.getTempDef();

	victim.addToHP(damage);
	this->hp += attack;
	std::cout << "The Mushroom sucks " << -damage << " of your HP, and heals " << attack << " of its own." << std::endl;
}
