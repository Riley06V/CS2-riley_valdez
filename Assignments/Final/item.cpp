//
// Created by riley on 12/1/2025.
//

#include "item.h"
#include "player.h"
#include <iostream>

item::item(std::string name, std::string description, int x, int y)
    : _name(name), _description(description), _x(x), _y(y) {}

item::~item() {}

void item::setName(std::string name) { _name = name; }
void item::setDescription(std::string description) { _description = description; }
void item::setX(int x) { _x = x; }
void item::setY(int y) { _y = y; }

std::string item::getName() const { return _name; }
std::string item::getDescription() const { return _description; }
int item::getX() const { return _x; }
int item::getY() const { return _y; }

void item::use(player& player) {
  return; //nothing cuz base class
}