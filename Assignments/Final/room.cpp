//
// Created by riley on 12/1/2025.
//

#include "room.h"
#include "item.h"
#include "enemy.h"
#include <iostream>

room::room(const std::string& description, int x, int y, bool isTreasureRoom)
    : _description(description), _x(x), _y(y), _enemy(nullptr), _isTreasureRoom(isTreasureRoom) {}

//destructor
room::~room() {
  for (auto* i : _items) {
    delete i;
  }
  delete _enemy;
}

//setters
void room::setDescription(const std::string& description) {
  _description = description;
}

void room::setEnemy(enemy* enemyPtr) {
  _enemy = enemyPtr;
}

void room::setTreasure(bool treasure) {
  _isTreasureRoom = treasure;
}

//getters;
std::string room::getDescription() const {
  return _description;
}

enemy* room::getEnemy() const {
  return _enemy;
}

int room::getX() const {
  return _x;
}

int room::getY() const {
  return _y;
}

bool room::isTreasureRoom() const {
  return _isTreasureRoom;
}

void room::addItem(item* item) {
  _items.push_back(newItem);
}

void room::removeItem(item* item) {
  if (index < _items.size()) {
    _items.erase(_items.begin() + index);
  }
}

const std::vector<item*>& room::getItems() const {
  return _items;
}

//ASCII rendering

std::vector<std::string> room::renderAscii(const player* p) const {
  //more to do
}