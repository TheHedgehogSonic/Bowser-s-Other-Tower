#include "Alien.h"

Alien::Alien(short s) {
	this->name = "Alien";
	this->hint = "I guess you should've listened to the higher and lower hints better.";
	this->hp = 1;
	this->hpMax = 1;
	this->attack = 0;
	this->defense = 0;
	this->coinLoot = 0;
	this->level = false;
	this->star = s;
	for (short i = 0; i < 25; i++) {
		guessed[i] = false;
	}
}

Alien::~Alien() {
	// Deconstruction
}

void Alien::introduce() {
	std::cout << "Way out in the outer reaches of space, you find an alien eager to destroy you." << std::endl;
}

void Alien::jumpResponse1(short damage) {
	std::cout << "This message should not appear. " << std::endl;
}

void Alien::jumpResponse2(short damage) {
	std::cout << "Please contact the dev for fixture." << std::endl;
}

void Alien::hammerResponse(short damage) {
	if (damage == star) {
		std::cout << "You blasted the alien away! ...And as it drifts away, you realize it was a Goomba this whole time!?" << std::endl;
		hp = 0;
	}
	else {
		std::cout << "That star was empty. It's hiding in a star ";
		if (star > damage) {
			std::cout << "higher than that." << std::endl;
		}
		else {
			std::cout << "lower than that." << std::endl;
		}
	}
}

void Alien::action(Character& victim) {
	victim.setHP(0);
	std::cout << "Now that you've exhausted your ammo, the alien sees an opening and blasts you away..." << std::endl;
}

short Alien::getStar() {
	return star;
}

bool Alien::starIsGuessed(short dex) {
	return guessed[dex];
}

void Alien::setStarGuessed(short dex, bool set) {
	guessed[dex] = set;
}
