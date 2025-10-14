//
// Created by riley on 9/16/2025.
//

#include "Jedi.h"

#include <iostream>

starwars::Jedi::Jedi(std::string name, int health, int lightsaberSkill, int forcePower)
	: character(name, health, lightsaberSkill), _forcePower(forcePower) {}


starwars::Jedi::~Jedi() { //Default Destructor
	//Nothing dynamic to clean
  }
//Setters

void starwars::Jedi::setForcePower(int forcePower) {
	_forcePower = forcePower;
}
//Getteres

int starwars::Jedi::getForcePower() {
	return _forcePower;
}

int starwars::Jedi::useForce(int power) {
	_forcePower -= power;
	return _forcePower;
}

int starwars::Jedi::attack() {
	return getLightsaberSkill() + (_forcePower / 25);
}

int starwars::Jedi::takeDamage(int damage) {
	int mitigated = damage - (_forcePower / 15);
	_health -= std::max(1, mitigated);
	return _health;
}

void starwars::Jedi::loadFromFile(std::string fileName) {
	character::loadFromFile(fileName);
	std::ifstream inFile("./saves/" + fileName);
	if (!inFile.is_open()) {
		std::cerr << "Unable to open file " <<fileName << " for Jedi load.\n";
		return;
	}

	std::string line;
	while (std::getline(inFile, line)) {
		if (line.find("ForcePower: ") != std::string::npos) {
			_forcePower = std::stoi(line.substr(line.find(":")+2));
		}
	}
	inFile.close();
}

void starwars::Jedi::saveToFile(std::string fileName) {
	character::saveToFile(fileName);
	std::ofstream outFile("./saves/" + fileName, std::ios::app); //needed to append file
	if (outFile.is_open()) {
		outFile << "ForcePower: " << _forcePower << "\n";
		outFile.close();
	} else {
		std::cerr << "Unable to open file " << fileName << "\n";
	}
}






