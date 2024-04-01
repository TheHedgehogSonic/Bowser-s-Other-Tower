#include "Hero.h"

Hero::Hero() : Character() {
	this->sp = 0;
	this->spMax = 0;
	this->luck = 0;
	this->level = 0;
	this->coins = 0;
	this->powerUses = 0;
	this->itemSlot = 0;
	this->breakableLogic = false;
	this->logicBroken = false;
}

Hero::Hero(short hpm, short spm, short atk, short def, short luck) :
Character(hpm, atk, def) {
	this->spMax = spm;
	this->sp = spm;
	this->luck = luck;
	this->level = 0;
	this->coins = 0;
	this->powerUses = 0;
	this->itemSlot = 0;
	this->breakableLogic = false;
	this->logicBroken = false;
}

Item Hero::getItem(short dex) {
	return inventory[dex];
}

short Hero::getSP() {
	return sp;
}

short Hero::getSPMax() {
	return spMax;
}

short Hero::getLuck() {
	return luck;
}

short Hero::getLevel() {
	return level;
}

short Hero::getCoins() {
	return coins;
}

short Hero::getPowerUses() {
	return powerUses;
}

bool Hero::logicIsBreakable() {
	return breakableLogic;
}

bool Hero::brokeLogic() {
	return logicBroken;
}

void Hero::addToSP(short val) {
	sp += val;
	sp = (sp > spMax ? spMax : sp); // Cap
}

void Hero::addToSPMax(short val) {
	spMax += val;
}

void Hero::addToLuck(short val) {
	luck += val;
}

void Hero::addToLevel(short val) {
	level += val;
}

void Hero::addToCoins(short val) {
	coins += val;
}

void Hero::addToPowerUses(short val) {
	powerUses += val;
}

void Hero::setSP(short val) {
	sp = val;
}

void Hero::setSPMax(short val) {
	spMax = val;
}

void Hero::setLuck(short val) {
	luck = val;
}

void Hero::setLevel(short val) {
	level = val;
}

void Hero::setCoins(short val) {
	coins = val;
}

void Hero::setPowerUses(short val) {
	powerUses = val;
}

void Hero::setLogicBroken(bool set) {
	logicBroken = set;
}

void Hero::setBreakableLogic(bool set) {
	breakableLogic = set;
}

void Hero::jump(Enemy& target) {
	short damage;
	// Jump 1
	damage = -(attack / 2) + target.getDefense();
	damage = (damage > 0 ? 0 : damage);
	target.addToHP(damage);
	target.jumpResponse1(damage);
	// Jump 2
	damage = -(attack / 2) - (attack % 2) + target.getDefense();
	damage = (damage > 0 ? 0 : damage);
	target.addToHP(damage);
	target.jumpResponse2(damage);
}

void Hero::hammer(Enemy& target) {
	short damage;
	// Bonk
	damage = -attack + target.getDefense();
	damage = (damage > 0 ? 0 : damage);
	target.addToHP(damage);
	target.hammerResponse(damage);
}

void Hero::powerAttack(Enemy& target) {
	short damage;

	damage = -(attack * 3) + target.getDefense();
	damage = (damage > 0 ? 0 : damage);
	target.addToHP(damage);
	target.powerResponse(damage);
}

void Hero::addItem(short t) {
	inventory[itemSlot] = t;
	itemSlot++;
}

short Hero::useItem(Hero& user, Enemy& victim, short slot) {
	return inventory[slot].action(user, victim);
}

void Hero::setItem(short dex, short val) {
	inventory[dex].setType(val);
}

void Hero::shiftItems(short start) {
	for (short i = start; i < 14; i++) {
		inventory[i] = inventory[i + 1];
	}
	itemSlot--;
}

short Hero::getItemSlot() {
	return itemSlot;
}

void Hero::setItemSlot(short val) {
	itemSlot = val;
}

void Hero::clearInventory() {
	for (short i = 0; i < 15; i++) {
		inventory[i].setType(0);
	}
	itemSlot = 0;
}

void Hero::print() {
	std::cout << "-------------" << std::endl;
	std::cout << "Your stats:" << std::endl;
	std::cout << "LVL " << level << std::endl;
	std::cout << "HP: " << hp << "/" << hpMax << std::endl;
	std::cout << "SP: " << sp << "/" << spMax << std::endl;
	std::cout << "ATK: " << attack << std::endl;
	std::cout << "DEF: " << defense << std::endl;
	std::cout << "LUCK: " << luck << std::endl;
	std::cout << "COINS: " << coins << std::endl;
	std::cout << "-------------" << std::endl;
}
