//
// Created by riley on 9/16/2025.
//
#include "Character.h"
#include "Sith.h"
#include <iostream>
#include <fstream>


starwars::Sith::Sith(std::string name, int health, int lightsaberSkill, int rageLevel)
: character(name, health, lightsaberSkill), _rageLevel(rageLevel) {}

	starwars::Sith::~Sith() {
	//nothing dynamic to delete so far
} //Deconstructor

//Revamped stuff
std::string starwars::Sith::getType() {
	return "Sith";
}

void starwars::Sith::setRageLevel(int rage) {
	_rageLevel = rage;
}

void starwars::Sith::buildRage(int amount) {
	_rageLevel += amount;
}

void starwars::Sith::resetRage() {
	_rageLevel = 0;
}

int starwars::Sith::getRageLevel() {
	return _rageLevel;
}




int starwars::Sith::attack() {
	int damage = _lightsaberSkill + (_rageLevel / 10);
	std::cout << getName() << " attacks with rage-fueld power!\n";
	resetRage();
	return damage;
}

int starwars::Sith::takeDamage(int damage) {
	_health -= damage;
	buildRage(damage / 2);
	return _health;
}

void starwars::Sith::saveToFile(std::string &fileName) {
	character::saveToFile(fileName);
	//copied from Jedi slight changes
	std::ofstream outFile("./saves/" + fileName, std::ios::app);
	if (outFile.is_open()) {
		outFile << "Rage Level: " << _rageLevel << "\n";
		outFile.close();
	} else {
		std::cerr << "Unable to open file " << fileName << "\n";
	}

}

void starwars::Sith::loadFromFile(std::string &fileName) {
	character::saveToFile(fileName);
	//copied from Jedi (slight changes
	std::ifstream inFile("./saves/" + fileName);
	if (!inFile.is_open()) {
		std::cerr << "Unable to open file " <<fileName << " for Sith load.\n";
		return;
	}

	std::string line;
	while (std::getline(inFile, line)) {
		if (line.find("Rage Level: ") != std::string::npos) {
			_rageLevel = std::stoi(line.substr(line.find(":")+2));
		}
	}
	inFile.close();
}