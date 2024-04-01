#include "KoopaDance.h"

KoopaDance::KoopaDance(short d) {
	this->name = "Dancing Koopa";
	this->hint = "You weren't supposed to lose here.";
	this->hp = 100;
	this->hpMax = 100;
	this->attack = 4;
	this->defense = 3;
	this->coinLoot = 10;
	this->level = false;
	this->dances = d;
}

KoopaDance::~KoopaDance() {

}

void KoopaDance::introduce() {
	std::cout << "Uh... is that a dancing Koopa? And why is it rambling on about ice cream sundaes the Goombas had to celebrate" << std::endl;
	std::cout << "what was meant to be your untimely demise? Oh well. Guess you have to fight him alongside his BAH BAHing now." << std::endl;
}

void KoopaDance::jumpResponse1(short damage) {
	std::cout << "You jump and... ";
}

void KoopaDance::jumpResponse2(short damage) {
	if (dances >= 0) {
		std::cout << "your trajectory got screwed by the BAH BAH!" << std::endl;
	}
	else {
		std::cout << "it's a hit! Now the Koopa is dead." << std::endl;
		hp = 0;
	}
}

void KoopaDance::hammerResponse(short damage) {
	if (dances >= 0) {
		std::cout << "Your hammer's aim was screwed by the BAH BAH!" << std::endl;
	}
	else {
		std::cout << "Your hammer connected! Now the Koopa is dead." << std::endl;
		hp = 0;
	}
}

void KoopaDance::action(Character& victim) {
	short damage = -attack + victim.getDefense() + victim.getTempDef();

	victim.addToHP(damage);
	std::cout << "The Koopa shell slams you for " << -damage << " damage." << std::endl;
	dances--;
}
