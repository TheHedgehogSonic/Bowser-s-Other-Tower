#include "ParaSmart.h"

ParaSmart::ParaSmart() {
	this->name = "Condart";
	this->hint = "Even though the walls are tall, they seem pretty unstable. If you could shake it somehow...";
	this->hp = 1;
	this->hpMax = 1;
	this->attack = 6;
	this->defense = 9999;
	this->coinLoot = 9;
	this->level = false;
	this->flying = true;
}

ParaSmart::~ParaSmart() {

}

void ParaSmart::introduce() {
	std::cout << "The ceiling on this floor is SUPER high, but there's also a Condart." << std::endl;
}

void ParaSmart::jumpResponse1(short damage) {
	if (flying) {
		std::cout << "You missed. ";
	}
}

void ParaSmart::jumpResponse2(short damage) {
	if (flying) {
		std::cout << "The Condart pinned itself to the high ceiling to evade you!" << std::endl;
	}
	else {
		std::cout << "Your jump seals the deal." << std::endl;
		hp = 0;
	}
}

void ParaSmart::hammerResponse(short damage) {
	if (flying) {
		std::cout << "Your hammer TREMORS the walls sending the Condart tumbling down, wings weak, feathers sweaty." << std::endl;
		attack = 3;
		defense = 0;
		flying = false;
	}
	else {
		std::cout << "Your hammer seals the deal." << std::endl;
		hp = 0;
	}
}

void ParaSmart::action(Character& victim) {
	short damage = -attack + victim.getDefense() + victim.getTempDef();

	victim.addToHP(damage);
	if (flying) {
		std::cout << "The Condart dives down to pin you for " << -damage << " damage." << std::endl;
	}
	else {
		std::cout << "The weakened Condart strikes you for " << -damage << " damage." << std::endl;
	}
}
