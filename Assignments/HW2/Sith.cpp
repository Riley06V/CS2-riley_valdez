//
// Created by riley on 9/16/2025.
//

#include "Sith.h"

#include "Character.h"

starwars::Sith::Sith(std::string name, int health, int lightsaberSkill): character(name, health, lightsaberSkill) {}

	starwars::Sith::~Sith() {
	//nothing dynamic to delete so far
} //Deconstructor

//Revamped stuff
std::string starwars::Sith::getType() {
	return "Sith";
}

int starwars::Sith::attack() {

}

void starwars::Sith::loadFromFile(std::string &fileName) {

}

void starwars::Sith::saveToFile(std::string &fileName) {

}