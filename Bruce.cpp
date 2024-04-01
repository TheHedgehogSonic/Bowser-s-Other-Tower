#include "Bruce.h"

Bruce::Bruce() {
	this->name = "Bowser";
	this->hint = "If you died here, you're just suck at this game.";
	this->hp = 1;
	this->hpMax = 1;
	this->attack = 10;
	this->defense = 0;
	this->coinLoot = 0;
	this->level = false;
}

Bruce::~Bruce() {

}

void Bruce::introduce() {
	std::cout << "Here you are, face to face with Bowser. It's now or never!" << std::endl;
}

void Bruce::jumpResponse1(short damage) {
	std::cout << "You jump on Bowser for " << -damage << " damage ";
}

void Bruce::jumpResponse2(short damage) {
	std::cout << "and again for another " << -damage << "." << std::endl;
}

void Bruce::hammerResponse(short damage) {
	std::cout << "Your hammer struck for total damage of " << -damage << " damage." << std::endl;
}

void Bruce::action(Character& victim) {
	short damage = -attack + victim.getDefense() + victim.getTempDef();

	victim.addToHP(damage);
	std::cout << "Bowser chucks hammers at you for " << -damage << " damage." << std::endl;
}
