//
// Created by riley on 9/16/2025.
//

#include "Jedi.h"
#include <iostream>

starwars::Jedi::Jedi(std::string name, int health, int lightsaberSkill, int forcePower) { //Paramertierzied Constructor
  _name = name;
  _health = health;
  _lightsaberSkill = lightsaberSkill;
  _forcePower = forcePower;
}

starwars::Jedi::~Jedi() { //Default Destructor
	//Nothing dynamic to clean
  }
//Setters
void starwars::Jedi::setName(std::string name) {
	_name = name;
}
void starwars::Jedi::setHealth(int health) {
	_health = health;
}
void starwars::Jedi::setLightsaberSkill(int lightsaberSkill) {
	_lightsaberSkill = lightsaberSkill;
}
void starwars::Jedi::setForcePower(int forcePower) {
	_forcePower = forcePower;
}
//Getteres
std::string starwars::Jedi::getName() {
  return _name;
}
int starwars::Jedi::getHealth() {
  return _health;
}
int starwars::Jedi::getLightsaberSkill() {
  return _lightsaberSkill;
}
int starwars::Jedi::getForcePower() {
  return _forcePower;
}
//Helpers/bonus functions
int starwars::Jedi::attack() {
  return _lightsaberSkill;
}

int starwars::Jedi::useForce(int power) {
	_forcePower -= power;
	return _forcePower;
}
int starwars::Jedi::takeDamage(int damage) {
  	_health -= damage;
	return _health;
}

//file I/O Functions

void starwars::Jedi::saveToFile(std::string &fileName) {
    std::ofstream outFile(fileName);
    if (outFile.is_open()) { //Human readable information in case user wants to mod
      outFile << "Name: " << _name << "\n"
      		  << "Health: " << _health << "\n"
      		  << "LightsaberSkill: " << _lightsaberSkill << "\n"
      		  << "ForcePower: " << _forcePower << "\n";
      outFile.close();
      } else {
        std::cerr << "Unable to open file " << fileName << "\n";
    }

}

void starwars::Jedi::loadFromFile(std::string &fileName) {
	std::ifstream inFile(fileName);
        if (!inFile.is_open()) {
          std::cerr << "Unable to open file " << fileName << "\n";
          return; //exit
        }
        inFile.ignore(32, ' '); //ignore 32 characters, or until reaching a space
        std::getline(inFile, _name); //Since it is a string
		inFile.ignore(32, ' ');
		inFile >> _health; //Since it is an int
		inFile.ignore(32, ' ');
		inFile >> _lightsaberSkill;
		inFile.ignore(32, ' ');
		inFile >> _forcePower;
    inFile.close();
    std::cout << "Name: " << _name << "\n"
    		  << "Health: " << _health << "\n"
    		  << "LightsaberSkill: " << _lightsaberSkill << "\n"
    		  << "ForcePower: " << _forcePower << "\n";
}