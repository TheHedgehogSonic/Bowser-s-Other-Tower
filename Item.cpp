#include "Item.h"

std::string Item::nameBank[5] = { "Empty", "Mushroom", "Fire Flower", "Star", "The Letter P" };
short Item::price[5] = { 0, 5, 20, 500, 200 };
bool Item::noHeal = true;

Item::Item() {
	this->type = 0;
	this->name = nameBank[type];
}

Item::Item(short t) {
	this->type = t;
	this->name = nameBank[type];
}

std::string Item::showName(short dex) {
	return nameBank[dex];
}

short Item::showPrice(short t) {
	return price[t];
}

bool Item::getNoHeal() {
	return noHeal;
}

void Item::setNoHeal(bool set) {
	noHeal = set;
}

short Item::getPrice() {
	return price[type];
}

std::string Item::getName() {
	return name;
}

short Item::getType() {
	return type;
}

void Item::setType(short val) {
	type = val;
	name = nameBank[val];
}

short Item::action(Character& user, Enemy& victim) {
	switch (type) { // Depending on item type
	case 0: // Empty
		std::cout << "You don't have an item in that slot." << std::endl;
		break;
	case 1: // Mushroom
		user.addToHP(5); // Heal
		std::cout << "You healed yourself for 5 HP!" << std::endl;
		std::cout << "You now have " << user.getHP() << " HP." << std::endl;
		noHeal = false;
		break;
	case 2: // Fire Flower
		user.addToPowerUses(3);
		std::cout << "You wield the power of Fire!" << std::endl;
		break;
	case 3: // Star
		victim.setHP(0);
		std::cout << "KERBLAMMO!! You annihilated all the enemies in sight!" << std::endl;
		break;
	case 4: // The letter P
		if (user.logicIsBreakable()) {
			user.setLogicBroken(true);
			std::cout << "Woah, what's happening? The J in the word \"Jump\" is fading away..." << std::endl;
			std::cout << "By the power of 4th wall logic bending, you now have the power to inflate enemies!!" << std::endl;
			system("pause");
		}
		else {
			std::cout << "Nothing is happening. I guess a letter can't do much for you right now, but maybe later." << std::endl;
			return 0;
		}
		break;
	}
	return type;
}

void Item::operator=(const Item& right) {
	this->name = right.name;
	this->type = right.type;
}
