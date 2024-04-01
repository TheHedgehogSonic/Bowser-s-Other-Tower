#include "Enemy.h"

Enemy::Enemy() : Character() {
	this->coinLoot = 0;
	this->level = false;
}

Enemy::Enemy(short hpm, short atk, short def, std::string n, std::string h, short c, bool l) :
Character(hpm, atk, def) {
	this->name = n;
	this->hint = h;
	this->coinLoot = c;
	this->level = l;
}

Enemy::~Enemy() {
	// Destructor
}

void Enemy::print() {
	std::cout << "You gonna fix that, future me?" << std::endl;
}

void Enemy::introduce() {
	std::cout << "Oopsie poopsie! It's a generic enemy because you used the wrong constructor." << std::endl;
}

std::string Enemy::getName() {
	return name;
}

std::string Enemy::getHint() {
	return hint;
}

short Enemy::getCoinLoot() {
	return coinLoot;
}

bool Enemy::hasLevel() {
	return level;
}

void Enemy::jumpResponse1(short damage) {
	std::cout << "You bounced on the enemy.";
}

void Enemy::jumpResponse2(short damage) {
	std::cout << " You bounced on the enemy again." << std::endl;
}

void Enemy::hammerResponse(short damage) {
	std::cout << "You hit the enemy with your hammer." << std::endl;
}

void Enemy::powerResponse(short damage) {
	std::cout << "You hit HARD with that Fire Flower for " << -damage << " damage!" << std::endl;
}

void Enemy::action(Character& victim) {
	std::cout << "The generic enemy attacks you." << std::endl;
}

void Enemy::addToPowerUses(short val) {
	std::cout << "ERROR: This function was called the wrong way." << std::endl;
}

bool Enemy::logicIsBreakable() {
	std::cout << "ERROR: This function was called the wrong way." << std::endl;
	return false;
}

void Enemy::setLogicBroken(bool set) {
	std::cout << "ERROR: This function was called the wrong way." << std::endl;
}

short Enemy::getStar() {
	std::cout << "ERROR: This function was called the wrong way." << std::endl;
	return 0;
}

bool Enemy::starIsGuessed(short dex) {
	std::cout << "ERROR: This function was called the wrong way." << std::endl;
	return false;
}

void Enemy::setStarGuessed(short dex, bool set) {
	std::cout << "ERROR: This function was called the wrong way." << std::endl;
}
