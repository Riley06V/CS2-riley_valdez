//
// Created by riley on 12/1/2025.
//

// enemy.cpp
#include "enemy.h"
#include "dungeon.h"
#include <iostream>

enemy::enemy(std::string name, int health, int attkPower,
             int difficultyLevel, int xPos, int yPos)
    : character(std::move(name), health, attkPower, xPos, yPos),
      _difficultyLevel(difficultyLevel) {}

void enemy::setDifficultyLevel(int difficultyLevel) {
    _difficultyLevel = difficultyLevel;
}

int enemy::getDifficultyLevel() const {
    return _difficultyLevel;
}

// Polymorphic attack used by combatLoop
int enemy::attack() {
    return _atkPower;
}


void enemy::takeDamage(int damage) {
    _health -= damage;
    if (_health < 0) _health = 0;
    std::cout << _name << " took " << damage << " damage.\n";
}