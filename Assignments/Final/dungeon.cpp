//
// Created by riley on 12/1/2025.
//

#include "dungeon.h"
#include "room.h"
#include "player.h"
#include <iostream>

dungeon::dungeon() : _currentRoom(nullptr), _currentIndex(0) {}

dungeon::~dungeon() {
  for(size_t i = 0; i < _rooms.size(); ++i) {
    delete _rooms.get(i);
  }
}

//add a room
void dungeon::addRoom(room* r) {
  _rooms.push_back(r);
  if(_rooms.size() == 1) {
    _currentRoom = r;
    _currentIndex = 0;
  //first room becomes current
  }
}

//get current
room* dungeon::getCurrentRoom() const {
  if(_rooms.empty()) return nullptr;
  return _rooms.get(_currentIndex);
}

void dungeon::moveNext() {
  if(_currentIndex + 1 < static_cast<int>(_rooms.size())) {
    _currentIndex++;
    _currentRoom = _rooms.get(_currentIndex);
  }
}

//move to previous room
void dungeon::movePrevious() {
  if(_currentIndex > 0) {
    _currentIndex--;
    _currentRoom = _rooms.get(_currentIndex);
  }
}

//size
size_t dungeon::size() const {
  return _rooms.size();
}

bool dungeon::empty() const {
  return _rooms.empty();
}

void dungeon::renderCurrentRoom(const player* player) const {
  room* current = getCurrentRoom();
  if(!current) {
    std::cout << "Dungeon is empty" << std::endl;
    return;
  }
  const auto& lines = current->renderAscii(player);
  for (const auto& line : lines) {
    std::cout << line << "\n";
  }
}