#include "Character.h"

Character::Character() {
	this->hp = 0;
	this->hpMax = 0;
	this->attack = 0;
	this->defense = 0;
	this->tempDef = 0;
}

Character::Character(short hpMax, short atk, short def) {
	this->hpMax = hpMax;
	this->hp = hpMax;
	this->attack = atk;
	this->defense = def;
	this->tempDef = 0;
}

short Character::getHP() {
	return hp;
}

short Character::getHPMax() {
	return hpMax;
}

short Character::getAttack() {
	return attack;
}

short Character::getDefense() {
	return defense;
}

short Character::getTempDef() {
	return tempDef;
}

bool Character::isAlive() {
	return hp > 0;
}

void Character::addToHP(short val) {
	hp += val;
	hp = (hp > hpMax ? hpMax : hp); // Cap
	hp = (hp >= 0 ? hp : 0);
}

void Character::addToHPMax(short val) {
	hpMax += val;
}

void Character::addToAttack(short val) {
	attack += val;
}

void Character::addToDefense(short val) {
	defense += val;
}

void Character::addToTempDef(short val) {
	tempDef += val;
}

void Character::setHP(short val) {
	hp = val;
}

void Character::setHPMax(short val) {
	hpMax = val;
}

void Character::setAttack(short val) {
	attack = val;
}

void Character::setDefense(short val) {
	defense = val;
}

void Character::setTempDef(short val) {
	tempDef = val;
}
