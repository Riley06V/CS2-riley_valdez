//
// Created by riley on 12/1/2025.
//

#include "character.h"
#include <iostream>

character::character(std::string name, int health, int atkPower, int xPos, int yPos)
    : _name(name), _health(health), _atkPower(atkPower), _x(xPos), _y(yPos) {}

character::~character() {}

//Setters
void character::setName(std::string name) { _name = name; }
void character::setHealth(int health) { _health = health; }
void character::setAtkPower(int atkPower) { _atkPower = atkPower; }
void character::setX(int xPos) { _x = xPos; }
void character::setY(int yPos) { _y = yPos; }

//getters
std::string character::getName() const { return _name; }
int character::getHealth() const { return _health; }
int character::getAtkPower() const { return _atkPower; }
int character::getX() const { return _x; }
int character::getY() const { return _y; }

//helpers
void character::takeDamage(int damage) {
  _health -= damage;
  if (_health <= 0) _health = 0;
}

int character::attack() {
  //base attack just returns attack power
  return _atkPower;
}

bool character::isAlive() {
  return _health > 0;
}

