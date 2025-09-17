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

void starwars::Jedi::saveToFile(std::string &fileName) {
  	std::ofstream saveFile;
	std::cout << "Enter the name of your saved file: ";
    std::cin >> fileName;


}

void starwars::Jedi::loadFromFile() {

}