//
// Created by riley on 9/16/2025.
//

#include "Sith.h"

starwars::Sith::Sith(std::string name, int health, int lightsaberSkill) {
    _name = name;
    _health = health;
    _lightsaberSkill = lightsaberSkill;
} //Paramaterized Constructor
starwars::Sith::~Sith() {
	//nothing dynamic to delete so far
} //Deconstructor
//Getters
 std::string starwars::Sith::getName() {
    return _name;
}
 int starwars::Sith::getHealth() {
 	return _health;
}
 int starwars::Sith::getLightsaberSkill() {
	return _lightsaberSkill;
}
//Setters
void starwars::Sith::setName(std::string name) {
	_name = name;
}
void starwars::Sith::setHealth(int health) {
    _health = health;
}
void starwars::Sith::setLightsaberSkill(int lightsaberSkill) {
  	_lightsaberSkill = lightsaberSkill;
}
//Helpers
int starwars::Sith::attack() {
	return _lightsaberSkill;
}
int starwars::Sith::takeDamage(int damage) {
	_health -= damage;
	return _health;
}