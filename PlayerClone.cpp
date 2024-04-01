#include "PlayerClone.h"

PlayerClone::PlayerClone(short hp, short hpm, short atk, short def, short cl) {
	this->name = "Mario";
	this->hint = "Looks like you died. Or did the clone? I really couldn't tell.";
	this->hp = hp;
	this->hpMax = hpm;
	this->attack = atk;
	this->defense = def;
	this->coinLoot = cl;
	this->level = true;
}

PlayerClone::~PlayerClone() {

}

void PlayerClone::introduce() {
	std::cout << "A clone of you? Uh, OK... I don't even know what the heck's going on anymore." << std::endl;
}

void PlayerClone::jumpResponse1(short damage) {
	std::cout << "You attack you for " << -damage << " damage, ";
}

void PlayerClone::jumpResponse2(short damage) {
	std::cout << "and " << -damage << " more." << std::endl;
	std::cout << "You now have " << hp << " HP." << std::endl;
}

void PlayerClone::hammerResponse(short damage) {
	std::cout << "You attack you for " << -damage << " damage." << std::endl;
	std::cout << "You now have " << hp << " HP." << std::endl;
}

void PlayerClone::action(Character& victim) {
	short damage = -attack + victim.getDefense() + victim.getTempDef();

	victim.addToHP(damage);
	std::cout << "You attack you for " << -damage << " damage." << std::endl;
}
