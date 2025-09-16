//
// Created by riley on 9/16/2025.
//

#include "Jedi.h"

starwars::Jedi::Jedi(std::string name, int health, int lightsaberSkill, int forcePower) { //Paramertierzied Constructor
  _name = name;
  _health = health;
  _lightsaberSkill = lightsaberSkill;
  _forcePower = forcePower;
}

starwars::Jedi::~Jedi() { //Default Destructor

  }
//Setters
void starwars::Jedi::setName(std::string name) {
  _name = name;
}
void starwars::Jedi::setHealth() {

}
void starwars::Jedi::setLightsaberSkill() {

}
void starwars::Jedi::setForcePower() {

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

}
int starwars::Jedi::takeDamage(int damage) {

}