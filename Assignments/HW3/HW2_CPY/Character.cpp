//
// Created by riley on 10/7/2025.
//
#include "Character.h"
#include <fstream>
#include <iostream>

starwars::character::character(std::string name, int health, int lightsaberSkill) {
	//Paramertierzied Constructor
	_name = name;
	_health = health;
	_lightsaberSkill = lightsaberSkill;
}

starwars::character::~character() {
	//Nothing currently dynamic
}
//Setters
void starwars::character::setName(std::string name) {
	_name = name;
}
void starwars::character::setHealth(int health) {
	_health = health;
}
void starwars::character::setLightsaberSkill(int lightsaberSkill) {
	_lightsaberSkill = lightsaberSkill;
}

void starwars::character::setType(std::string type) {
	_type = type;
}
std::string starwars::character::getName() const {
	return  _name;
}
int starwars::character::getHealth() const {
	return _health;
}
int starwars::character::getLightsaberSkill() const {
	return _lightsaberSkill;
}

std::string starwars::character::getType() {
	return _type;
}

int starwars::character::attack() {
	return _lightsaberSkill;
}
int starwars::character::takeDamage(int damage) {
	_health -= damage;
	return _health;
}

void starwars::character::saveToFile(std::string &fileName) {
	std::ofstream outFile("./saves/" + fileName);
	if (outFile.is_open()) { //Human readable information in case user wants to mod
		outFile << "Name: " << _name << "\n"
				<< "Type: " << _type << "\n"
				  << "Health: " << _health << "\n"
				  << "LightsaberSkill: " << _lightsaberSkill << "\n";
		outFile.close();
	} else {
		std::cerr << "Unable to open file " << fileName << "\n";
	}

}

void starwars::character::loadFromFile(std::string &fileName) {
	std::ifstream inFile("./saves/" + fileName);
	if (!inFile.is_open()) {
		std::cerr << "Unable to open file " << fileName << "\n";
		return; //exit
	}
	inFile.ignore(32, ' '); //ignore 32 characters, or until reaching a space
	std::getline(inFile, _name); //Since it is a string
	inFile.ignore(32, ' ');
	std::getline(inFile, _type); //Since it is a string
	inFile.ignore(32, ' ');
	inFile >> _health; //Since it is an int
	inFile.ignore(32, ' ');
	inFile >> _lightsaberSkill;
	inFile.ignore(32, ' ');
	inFile.close();
	std::cout << "Type: " << _type << "\n"
			  << "Name: " << _name << "\n"
			  << "Health: " << _health << "\n"
			  << "LightsaberSkill: " << _lightsaberSkill << "\n";
}

std::ostream& operator<<(std::ostream& os, const starwars::character& characterOutput) {
	os << "Name: " << characterOutput.getName()
       << "\nHealth: " << characterOutput.getHealth()
	   << "\nAttack Power: " << characterOutput.getLightsaberSkill() << "\n";
	return os;
}


//Comparison Operators based on attack
bool operator!=( starwars::character &character1,  starwars::character &character2) {
	return character1.getLightsaberSkill() != character2.getLightsaberSkill();
}

bool operator==( starwars::character &character1,  starwars::character &character2) {
	return character1.getLightsaberSkill() == character2.getLightsaberSkill();
}

bool operator<( starwars::character &character1,  starwars::character &character2) {
	return character1.getLightsaberSkill() < character2.getLightsaberSkill();
}

bool operator>( starwars::character &character1,  starwars::character &character2) {
	return character1.getLightsaberSkill() > character2.getLightsaberSkill();
}

bool operator<=( starwars::character &character1,  starwars::character &character2) {
	return character1.getLightsaberSkill() <= character2.getLightsaberSkill();
}

bool operator>=( starwars::character &character1,  starwars::character &character2) {
	return character1.getLightsaberSkill() >= character2.getLightsaberSkill();
}

//overloading with + and -
starwars::character& starwars::character::operator-(int damage) {
  _health -= damage;
  if (_health <= 0) _health = 0;
  return *this;
}

starwars::character& starwars::character::operator+(int heal) {
	_health += heal;
	return *this;
}