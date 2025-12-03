//
// Created by riley on 12/1/2025.
//

#include "enemy.h"
#include "item.h"
#include "room.h"
#include <iostream>

enemy::enemy(std::string name, int health, int atkPower, int difficultyLevel, int xPos, int yPos)
    : character(name, health, atkPower, xPos, yPos),
      _difficultyLevel(difficultyLevel), _heldItem(nullptr) {}

enemy::~enemy() {
  //
}

void enemy::setDifficultyLevel(int difficultyLevel) {
  _difficultyLevel = difficultyLevel;
}

int enemy::getDifficultyLevel() const {
  return _difficultyLevel;
}

void enemy::setHeldItem(item* item) {
  _heldItem = item;
}

item* enemy::dropItem() {
  item* temp = _heldItem;
  _heldItem = nullptr;
  return temp; //Room takes ownership, then player has choice to pick up item
}

//combat
int enemy::attack(const room* room) const { //unfinished. Damage will scale based on room level and difficulty level
  int roomLevel = room->getLevel();
  return _atkPower + _difficultyLevel * roomLevel;
}

void enemy::takeDamage(int damage) {
  _health -= damage;
  if (_health <= 0) _health = 0;
  std::cout << _name << " took " << damage << " damage." << std::endl;
}