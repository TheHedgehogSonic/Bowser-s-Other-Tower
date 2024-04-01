#include <iostream>
#define NOMINMAX
#include <ctime>
#include <random>
#include <windows.h>
#include "Character.h"
#include "Hero.h"
#include "Enemy.h"
#include "GoombaBunch.h"
#include "KoopaDance.h"
#include "BobombDud.h"
#include "ParaSmart.h"
#include "PlayerClone.h"
#include "Alien.h"
#include "BloompBreak.h"
#include "HoppoRain.h"
#include "Mushroom.h"
#include "Bruce.h"

using namespace std;
// Color text handler
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
// Typedefs
typedef unsigned short POS;
typedef unsigned int POS32;
// Objects
Hero mario(10, 8, 5, 1, 2);
Enemy *boss;
// Global vars
enum class GameState {TITLE, STORY, PRELUDE, BOSS_SPAWN, YOUR_TURN, JUMP, HAMMER, POWER, ENEMY_TURN, INVENTORY, VICTORY,
	REROUTE, LEVELUP, SHOP, ALIEN_BOSS, LOGIC_BREAK, PUMP, GAMEOVER, ALIEN, COMPLETE, DEMO_END, QUIT};
const string DOBERVICH_BUMPER_STICKER = "USE YOUR VARIABLES!";
const short FLOOR_NUMS[10] = { 1, 6, 10, 12, 15, 20, 36, 47, 55, 69 };
const bool DEMO_MODE = false;

short response = 0;
bool running = true;
bool openedInv = false;
POS tries;
POS alienLosses = 0;
bool guessedStars[10];
POS i; // Loop count

GameState sequence = GameState::TITLE;
GameState prevSequence;
// Visible vars
POS currentFloor = 0;
// Function prototypes
void welcome();
void intro();
void cutscene();
void outro();
void gameOver();
POS rngesus(POS low, POS high);
void goodbye();
void setColor(POS color);
void getInput(POS range);

int main() {
	srand((unsigned)time);

	while (running) {
		switch (sequence) {
		case GameState::TITLE:
			welcome();
			setColor(15);
			cout << "1. Start\n2. Play Alien Game\n-1. Exit" << endl;
			getInput(2);
			// Do stuff based on response
			switch (response) {
			case 1:
				sequence = GameState::STORY;
				prevSequence = GameState::TITLE;
				break;
			case 2:
				sequence = GameState::ALIEN;
				break;
			}
			break;
		case GameState::STORY:
			if (prevSequence == GameState::TITLE) { // If you started the game
				intro();
				system("pause");
				// Setting up the game
				currentFloor = 1;
				mario.setLevel(1); // Back to Level 1
				mario.setCoins(0); // Without any money
				mario.setHP(10); // Stats
				mario.setHPMax(10);
				mario.setSP(8);
				mario.setSPMax(8);
				mario.setAttack(5);
				mario.setDefense(1);
				mario.setLuck(2);
				mario.setBreakableLogic(false);
				// Item setup
				Item::setNoHeal(true);
				mario.clearInventory(); // Reset items
				for (i = 0; i < 3; i++) { // Start with 3 Mushrooms
					mario.setItem(i, 1);
				}

				mario.setItem(3, 3); // Hidden Star
				mario.setItemSlot(4);

				setColor(14); // Set color to tan
				cout << "You brought 3 Mushrooms along the way to assist you." << endl; // Ignore the star for fools
				
				sequence = GameState::BOSS_SPAWN;
			}
			else { // If you finished the game
				outro();
				system("pause");
				sequence = GameState::TITLE;
			}

			break;
		case GameState::PRELUDE:
			cutscene();
			system("pause");
			sequence = GameState::VICTORY;
			break;
		case GameState::BOSS_SPAWN:
			setColor(7); // Set color to light gray
			cout << "Floor " << FLOOR_NUMS[currentFloor - 1] << endl;

			if (boss != NULL) { // If a boss is already loaded
				delete boss; // Clear it out of memory to make room for the next
				boss = NULL;
			}

			setColor(12); // Set color to red
			switch (currentFloor) { // Boss deciding process
			case 1:
				boss = new GoombaBunch(); // Thousands of Goombas
				break;
			case 2: // Between 4 to 6 dances minus your luck stat (should be between 1 and 3)
				boss = new KoopaDance(rngesus(4, 6) - mario.getLuck()); // Dancing Koopa
				break;
			case 3:
				boss = new BobombDud(); // Dud Bob-omb
				break;
			case 4:
				boss = new ParaSmart(); // Ceiling Condart
				break;
			case 5:
				boss = new PlayerClone(mario.getHP(), mario.getHPMax(), mario.getAttack(), mario.getDefense(), mario.getCoins()); // Doppelganger
				break;
			case 6:
				boss = new Alien(rngesus(1, 25)); // Alien Goomba
				break;
			case 7:
				mario.setBreakableLogic(true);
				boss = new BloompBreak(5); // Inflatable Bloomp
				break;
			case 8:
				boss = new HoppoRain(rngesus(1, 3)); // Hoppo Rain
				break;
			case 9:
				boss = new Mushroom(); // Mushroom?
				break;
			case 10:
				boss = new Bruce(); // Bruce
				break;
			}
			if (boss != NULL) {
				boss->introduce();
			}
			else if (DEMO_MODE) {
				sequence = GameState::DEMO_END;
				break;
			}
			setColor(15); // Back to white
			cout << "1. Fight\n2. Check stats" << endl;
			getInput(2);

			switch (response) {
			case 1: // Start battle
				sequence = (currentFloor != 6 ? GameState::YOUR_TURN : GameState::ALIEN_BOSS);
				break;
			case 2: // Look at stats
				setColor(7);
				mario.print();
				break;
			}
			break;
		case GameState::YOUR_TURN:
			setColor(15);
			cout << "1. Jump\n2. Hammer\n3. Use power (" << mario.getPowerUses() << ")\n4. Items\n5. Defend\n6. Check stats" << endl;

			getInput(5);
			switch (response) {
			case 1:
				sequence = GameState::JUMP;
				break;
			case 2:
				sequence = GameState::HAMMER;
				break;
			case 3:
				sequence = GameState::POWER;
				break;
			case 4:
				if (!openedInv) {
					setColor(11);
					cout << "Oops, I forgot to mention you also brought a Star with you." << endl;
					system("pause");
					openedInv = true;
				}

				prevSequence = sequence; // Set the previous sequence accordingly
				sequence = GameState::INVENTORY;
				break;
			case 5:
				setColor(9); // Set color to blue
				cout << "Your guard is raised! You'll take less damage this turn." << endl;
				mario.setTempDef(2);
				break;
			case 6:
				setColor(7);
				mario.print();
				break;
			}

			break;
		case GameState::JUMP:
			setColor(14); // Set color to tan
			mario.jump(*boss);
			
			if (boss->isAlive()) {
				sequence = GameState::ENEMY_TURN;
			}
			else { // If the boss is dead
				cout << "You did it!" << endl;
				sequence = GameState::REROUTE;
			}

			break;
		case GameState::HAMMER:
			setColor(14); // Set color to tan
			mario.hammer(*boss);
			
			if (boss->isAlive()) {
				sequence = (mario.brokeLogic() ? GameState::LOGIC_BREAK : GameState::ENEMY_TURN);
			}
			else { // If the boss is dead
				cout << "You did it!" << endl;
				sequence = GameState::REROUTE;
			}

			break;
		case GameState::PUMP:
			boss->jumpResponse1(1);
			boss->jumpResponse2(1);

			if (boss->isAlive()) {
				sequence = GameState::LOGIC_BREAK;
			}
			else { // If the boss is dead
				setColor(14);
				cout << "BOOM! You popped it!" << endl;
				mario.setLogicBroken(false);
				sequence = GameState::REROUTE;
			}

			break;
		case GameState::POWER:
			setColor(14); // Set color to tan
			if (mario.getPowerUses()) { // If you have some left
				mario.powerAttack(*boss);
				mario.addToPowerUses(-1);

				if (boss->isAlive()) {
					sequence = GameState::ENEMY_TURN;
				}
				else { // If the boss is dead
					cout << "You did it!" << endl;
					sequence = GameState::REROUTE;
				}
			}
			else { // No fire left
				setColor(13);
				cout << "You don't have a powerup equipped." << endl;
				sequence = GameState::YOUR_TURN;
			}

			break;
		case GameState::ENEMY_TURN:
			setColor(12); // Set color to red
			boss->action(mario); // They attack you
			cout << "You now have " << mario.getHP() << " HP." << endl;
			mario.setTempDef(0);

			if (boss->isAlive()) {
				sequence = (mario.isAlive() ? GameState::YOUR_TURN : GameState::GAMEOVER);
			}
			else {
				setColor(14);
				cout << "...You did it?" << endl;
				sequence = GameState::REROUTE;
			}
			break;
		case GameState::GAMEOVER:
			gameOver(); // Copium
			cout << boss->getHint() << endl;
			sequence = GameState::TITLE;
			
			delete boss; // Deletion process
			boss = NULL;
			break;
		case GameState::INVENTORY:
			setColor(15);
			cout << "0. Go back" << endl; // 0 is to go back
			for (POS i = 0; i < 15; i++) { // Loop through all items
				cout << i + 1 << ". " << mario.getItem(i).getName() << endl; // Display the player's items
			}

			getInput(15); // Select an item

			switch (response) {
			case 0: // Going back
				sequence = prevSequence;
				break;
			default: // Use item
				setColor(14);
				tries = mario.useItem(mario, *boss, response - 1);
				// After trying to use an item,
				if (tries > 0 && tries < 4) { // Using a nothing, Mushroom, Flower, or Star
					mario.shiftItems(response - 1);

					if (prevSequence == GameState::YOUR_TURN) {
						if (boss->isAlive()) {
							sequence = GameState::ENEMY_TURN;
						}
						else { // Check if the boss is dead from a star
							setColor(14);
							cout << "You did it!" << endl;
							sequence = GameState::REROUTE;
						}
					}
					else { // If you were accessing via already having won the battle
						sequence = GameState::VICTORY;
					}
				}
				else if (tries >= 4 && mario.logicIsBreakable()) { // Using the letter P
					mario.shiftItems(response - 1);
					sequence = GameState::LOGIC_BREAK;
				}
			}
			break;
		case GameState::LOGIC_BREAK:
			setColor(15); // White
			cout << "1. Pump\n2. Hammer\n3. Check stats" << endl;

			getInput(3);
			switch (response) {
			case 1:
				sequence = GameState::PUMP;
				break;
			case 2:
				sequence = GameState::HAMMER;
				break;
			case 3:
				setColor(7);
				mario.print();
				break;
			}

			break;
		case GameState::REROUTE: // A simple function that tells the game where to go after a win
			mario.addToCoins(boss->getCoinLoot());
			sequence = (boss->hasLevel() ? GameState::LEVELUP : GameState::VICTORY);
			break;
		case GameState::VICTORY:
			if (currentFloor < 10) {
				setColor(15);
				cout << "1. Keep going up\n2. Use item\n3. Check stats" << endl;

				getInput(3);
				switch (response) {
				case 1: // Next boss
					currentFloor++;
					sequence = GameState::BOSS_SPAWN;
					break;
				case 2:
					prevSequence = sequence;
					sequence = GameState::INVENTORY;
					break;
				case 3:
					setColor(7);
					mario.print();
					break;
				}
			}
			else {
				setColor(7);
				cout << "You know on closer inspection, Bowser is looking a little too black and blue. You've been fighting Bruce the whole time!" << endl;
				cout << "But where could his scarier brother Bowser be hiding? As Bruce loses grip of his Light Essence, it all comes together..." << endl;
				system("pause");

				sequence = GameState::COMPLETE;
			}

			break;
		case GameState::LEVELUP:
			mario.addToLevel(1);
			mario.addToHPMax(1);
			mario.setHP(mario.getHPMax());
			mario.addToSPMax(1);
			mario.setSP(mario.getSPMax());
			mario.addToAttack(1);
			mario.addToDefense(1);
			mario.addToLuck(1);

			setColor(14);
			cout << "LEVEL UP!!\n" << endl;

			setColor(11);
			cout << "Your Max HP is now " << mario.getHPMax() << endl;
			cout << "Your Max SP is now " << mario.getSPMax() << endl;
			cout << "Your Attack is now " << mario.getAttack() << endl;
			cout << "Your Defense is now " << mario.getDefense() << endl;
			cout << "Your Luck is now " << mario.getLuck() << endl;

			cout << "...And you get to upgrade one of these stats another time!\n" << endl;

			setColor(15);
			cout << "1. Upgrade Max HP by 1\n2. Upgrade Max SP by 1\n3. Upgrade Attack by 1\n4. Upgrade Defense by 1\n5. Upgrade Luck by 1" << endl;
			getInput(5);

			setColor(11);
			switch (response) {
			case 1:
				mario.addToHPMax(1);
				cout << "Your Max HP is now " << mario.getHPMax() << endl;
				break;
			case 2:
				mario.addToSPMax(1);
				cout << "Your Max SP is now " << mario.getSPMax() << endl;
				break;
			case 3:
				mario.addToAttack(1);
				cout << "Your Attack is now " << mario.getAttack() << endl;
				break;
			case 4:
				mario.addToDefense(1);
				cout << "Your Defense is now " << mario.getDefense() << endl;
				break;
			case 5:
				mario.addToLuck(1);
				cout << "Your Max Luck is now " << mario.getLuck() << endl;
				break;
			}

			sequence = (currentFloor == 5 ? GameState::SHOP : GameState::VICTORY);
			break;
		case GameState::SHOP:
			setColor(11);
			cout << "Select an item to buy." << endl;

			setColor(7);
			cout << "0. Go back" << endl;
			for (i = 1; i < 5; i++) {
				cout << i << ". " << Item::showName(i) << " (" << Item::showPrice(i) << " coins)" << endl;
			}

			getInput(4);
			switch (response) {
			case 0:
				sequence = GameState::PRELUDE;
				break;
			default: // Buying an item
				if (mario.getItemSlot() >= 15) { // If inventory is full
					setColor(12);
					cout << "You can't carry any more items." << endl;
				}
				else if (mario.getCoins() >= Item::showPrice(response)) {
					mario.addItem(response); // Add the item
					setColor(14);
					cout << "You got a " << Item::showName(response) << "!" << endl;

					mario.addToCoins(-Item::showPrice(response)); // Pay for item
					cout << "You now have " << mario.getCoins() << " coins" << endl;
				}
				else {
					setColor(12);
					cout << "That's more than you can afford." << endl;
				}
			}

			break;
		case GameState::ALIEN_BOSS: // Fighting the alien
			setColor(9);
			cout << "The alien is hiding behind one of 25 stars. Your SP has been converted to ammo to fend off the otherworldly foe." << endl;
			// SP counter
			while (mario.getSP() > 0 && !boss->starIsGuessed(boss->getStar() - 1)) { // While you can still guess
				setColor(15);
				cout << "Enter a number to shoot a star: " << endl;
				getInput(25);
				// Response
				if (!boss->starIsGuessed(response - 1)) { // Not guessed star
					setColor(13);
					mario.addToSP(-1);
					boss->setStarGuessed(response - 1, true);
					boss->hammerResponse(response); // Get results
					cout << "You now have " << mario.getSP() << " SP." << endl;
				}
				else { // Guessed star
					setColor(12);
					cout << "You already guessed that star." << endl;
				}
			}

			if (boss->starIsGuessed(boss->getStar() - 1)) { // Guessed right
				setColor(10);
				cout << "The Wonder Seed it dropped transports you back to Trial Tower to continue." << endl;
				sequence = GameState::VICTORY; // Send straight to victory screen
			}
			else {
				setColor(12); // Out of tries
				boss->action(mario); // Kill you
				sequence = GameState::GAMEOVER;
			}

			break;
		case GameState::DEMO_END:
			setColor(10);
			cout << "You reached the end of the demo! See you on April 1." << endl;
			system("pause");
			sequence = GameState::TITLE;

			break;
		case GameState::COMPLETE:
			outro();
			// Win message depending if you used Mushrooms or not
			if (Item::getNoHeal()) {
				setColor(11);
				cout << "No heals? You're truly a Superstar! Remember, Mr. Dobervich says to always " << DOBERVICH_BUMPER_STICKER << endl;
			}
			else {
				setColor(13);
				cout << "Wow! You beat the game! But what if I told you you could've done it without using a single Mushroom?" << endl;
			}

			system("pause");
			sequence = GameState::TITLE;
			break;
		case GameState::ALIEN:
			for (POS i = 0; i < 10; i++) { // Loop through all stars
				guessedStars[i] = false; // Set them to not guessed
			}
			tries = 3; // You have 3 tries to find the alien before running out of ammo
			// Message about alien
			setColor(9);
			cout << "The alien is hiding behind one of ten stars! Find it by blasting the star with your ship." << endl;
			// Minigame loop
			while (tries > 0) { // While you still have tries left or guessed right
				setColor(15);
				cout << "Enter a number between 1 and 10 to shoot a star (Tries: " << tries << ")." << endl;
				getInput(10); // Get input on which star you guess
				// Response to your response
				if (!response) { // Go back
					sequence = GameState::TITLE; // Go back to the title screen
					break;
				}
				// Guessing
				if (!guessedStars[response - 1]) { // If you haven't guessed that star yet
					guessedStars[response - 1] = true; // Mark it as guessed and then...
					setColor(13);
					cout << "That star was empty." << endl; // Fail message
					tries--; // Lose a try
				}
				else { // If you already guessed the star
					setColor(4);
					cout << "You already guessed that star." << endl;
				}

				if (!tries) { // If you run out of tries
					setColor(12);
					cout << "Sorry Captain, but your alien is in another parsec." << endl; // Lose message
					alienLosses++; // Give a loss
				}
			}

			setColor(11);
			cout << "Wins: 0, Losses: " << alienLosses << "\n" << endl;
			sequence = GameState::TITLE; // Go back to the title screen
			break;
		case GameState::QUIT:
			goodbye();
			running = false;
			break;
		}
	}

	setColor(15); // Go back to white
	return 0;
}

void welcome() {
	setColor(6); // Set color to gold
	cout << "====================================" << endl;
	cout << "= Welcome to Bowser's Other Tower! =" << endl;
	cout << "= Enter if you dare... V1.0.0      =" << endl;
	cout << "====================================" << endl;
}
// The intro text scene
void intro() {
	setColor(6); // Set color to gold
	cout << "----------------------------------------------------------------------------------------------------" << endl;
	cout << "|| OK, you know the deal. Get to the top and get the light essence to know why you wound up here. ||" << endl;
	cout << "----------------------------------------------------------------------------------------------------" << endl;
}

void cutscene() {
	setColor(6);
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "|| As you climb what you're slowly questioning what's really Trial Tower, you start to wonder ||" << endl;
	cout << "|| some things. Why are there so many empty rooms between enemies? How did so many foes turn  ||" << endl;
	cout << "|| out so strange? What is Bowser up to putting you through all this? Speaking of Wonder...   ||" << endl;
	cout << "|| there's a Wonder Flower dead ahead! As you carefully lay your fingers on it, the walls     ||" << endl;
	cout << "|| fold open, and the floor blasts its way into space to face your next adversary. Good luck! ||" << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;
}

void outro() {
	setColor(6);
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "|| STORY:                                                                                ||" << endl;
	cout << "|| On your way to Trial Tower to overthrow the evil Koopa King, you lost your way in the ||" << endl;
	cout << "|| Ruined Kingdom. Navigating thousands of identical purple stones in the rain isn't     ||" << endl;
	cout << "|| easy! Instead of Trial Tower, you had made it into Bowser's decoy, TROLL Tower! You   ||" << endl;
	cout << "|| have your work cut out for you once you reach the real deal... Happy April Fools Day! ||" << endl;
	cout << "|| THE END                                                                               ||" << endl;
	cout << "------------------------------------------------------------------------------------------=" << endl;
}

void gameOver() {
	setColor(4);
	cout << "==========" << endl;
	cout << "= COPIUM =" << endl;
	cout << "==========\n" << endl;

	setColor(1);
	cout << "Only " << currentFloor << " floors? Get REKT!" << endl;
}

POS rngesus(POS low, POS high) { // Generates a random number within a range
	return rand() % ((high - low) + 1) + low;
}

void goodbye() {
	setColor(6); // Set color to gold
	cout << "============" << endl;
	cout << "= Goodbye. =" << endl;
	cout << "============" << endl;
}

void setColor(POS color) {
	SetConsoleTextAttribute(h, color);
}

void getInput(POS range) { // Gets user input to do stuff with
	setColor(15); // Set color to white
	cout << "What will you do: ";
	setColor(3); // Set color to dark cyan
	cin >> response;
	// Detects the wrong input (Shoutouts to greyfade on Stack Overflow for this code snippet)
	while (!cin || response > range) { // cin.fail() and check if the number wasn't too high
		cin.clear(); // Clear the bad input
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Only works with NOMIXMAX definition
		setColor(4);
		cout << "INVALID ANSWER - That was a number out of range, or just not a number. Try again: "; // Ask for valid input
		setColor(3);
		cin >> response; // Get a valid input
	}
	// Input a negative number to end the sentinel loop
	if (response < 0) {
		sequence = GameState::QUIT;
	}
}