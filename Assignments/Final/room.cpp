//
// Created by riley on 12/1/2025.
//

#include "room.h"
#include "item.h"
#include "enemy.h"
#include "player.h"
#include <algorithm>
#include <iostream>

room::room(const std::string& description,
           const std::vector<std::string>& grid,
           bool isTreasureRoom)
    : _description(description),
      _x(0), _y(0), // starting coordinates for the room itself
      _enemy(nullptr),
      _isTreasureRoom(isTreasureRoom),
      _grid(grid),
      _height(static_cast<int>(grid.size())),
      _width(_height ? static_cast<int>(grid[0].size()) : 0),
      _doorX(-1),
      _doorY(-1),
	  _prevDoorX(-1), _prevDoorY(-1) {

    // Scan the grid for special tiles
    for (int y = 0; y < _height; ++y) {
        for (int x = 0; x < _width; ++x) {
            char c = _grid[y][x];
            if (c == '!') {
                _itemPositions.emplace_back(x, y);
            } else if (c == 'D') {
                _doorX = x;
                _doorY = y;
            } else if (c == 'P') {
              _prevDoorX = x;
              _prevDoorY = y;
            }
            //enemies are hidden: will be added with helper
        }
    }
}

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

void room::setDoor(int x, int y) {
  _doorX = x;
  _doorY = y;
}

void room::setPrevDoor(int x, int y) {
  _prevDoorX = x;
  _prevDoorY = y;
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

std::pair<int,int> room::getDoor() const {
    return {_doorX, _doorY};
}

std::pair<int,int> room::getPrevDoor() const {
    return {_prevDoorX, _prevDoorY};
}


bool room::isTreasureRoom() const {
  return _isTreasureRoom;
}

bool room::isDoor(int x, int y) const {
  return (x == _doorX && y == _doorY);
}

bool room::isPrevDoor(int x, int y) const {
  return (_prevDoorX == x && _prevDoorY == y);
}
//item management
void room::addItem(item* it) {
  	int x = it->getX();
    int y = it->getY();
    if(y >= 0 && y < _height && x >= 0 && x < _width) {
		_items.push_back(it);
    	_itemPositions.emplace_back(it->getX(), it->getY());
    	_grid[it->getY()][it->getX()] = '!'; // mark on map
    } else {
      std::cerr << "item out of bounds at " << x << "," << y << std::endl;
    }

}

void room::removeItem(item* target) {
    auto it = std::find(_items.begin(), _items.end(), target);
    if (it != _items.end()) {
        _items.erase(it);
    }
}

const std::vector<item*>& room::getItems() const {
  return _items;
}
//movement
bool room::canMoveTo(int x, int y) const {
    if (y < 0 || y >= _height || x < 0 || x >= _width) return false;
    char tile = _grid[y][x];
    // '#' = wall, blocked
    return (tile != '#');
}

bool room::isItem(int x, int y) const {
  return std::find (_itemPositions.begin(), _itemPositions.end(),
                   std::make_pair(x, y)) != _itemPositions.end();
}

bool room::isEnemy(int x, int y) const {
    return std::find(_enemyPositions.begin(), _enemyPositions.end(),
                     std::make_pair(x, y)) != _enemyPositions.end();
}

//state changes
void room::pickupItemAt(int x, int y) {
  auto it = std::find(_itemPositions.begin(), _itemPositions.end(), std::make_pair(x, y));
  if (it != _itemPositions.end()) {
    _itemPositions.erase(it);
    _grid[y][x] = '.'; //clear title
  }
}

bool room::revealEnemyAt(int x, int y) {
  auto it = std::find(_enemyPositions.begin(), _enemyPositions.end(), std::make_pair(x, y));
  if (it != _enemyPositions.end()) {
    _enemyPositions.erase(it);
    return true;
    //enemy stays hidden visually, combat trigggers
  }
  return false;
}

void room::addHiddenEnemy(int x, int y) {
  _enemyPositions.emplace_back(x, y);
}
//ASCII rendering
std::vector<std::string> room::renderAscii(const player* player) const {
	std::vector<std::string> rendered = _grid;
    if (player) {
      int playerX = player->getX();
      int playerY = player->getY();
      if(playerY >= 0 && playerY < _height && playerX >= 0 && playerX < _width) {
        rendered[playerY][playerX] = '@';
      }
    }
    return rendered;
}