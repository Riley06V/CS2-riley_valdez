//
// Created by riley on 12/1/2025.
//
#include <iostream>
#include "player.h"
#include "item.h"
#include "damage_Boost_Item.h"
#include "defense_Item.h"
#include "room.h"

player::player(std::string name, int startX, int startY, int health, int atkPower, int defense)
    : character(name, health, atkPower, startX, startY), _defense(defense), _itemCount(0), _weaponSlot(nullptr), _armorSlot(nullptr) {
  for(int i = 0; i < inventorySize; ++i) _inventory[i] = nullptr;
    }

player::~player() {}

void player::setDefense(int defense) { _defense = defense; }
int player::getDefense() const { return _defense; }
int player::getCurrentItemCount() const { return _itemCount; }

void player::heal(int healAmt) {
  _health += healAmt;
  std::cout << _name << " healed for " << _health << " HP.\n" << std::endl;
}

void player::addItem(item *item) {
  if(_itemCount < inventorySize) {
    _inventory[_itemCount++] = item;
  } else {
    std::cout << "Inventory full!" << std::endl;
  }
}

void player::removeItem(const int slotIndex) {
  if (slotIndex < 0 || slotIndex >= _itemCount) {
    _inventory[slotIndex] = nullptr;
    for(int i = slotIndex; i < _itemCount - 1; ++i) {
      _inventory[i] = _inventory[i + 1];
    }
    _inventory[_itemCount - 1] = nullptr;
    _itemCount--;
  }
}

void player::showInventory() const {
  std::cout << _name << "'s inventory: \n" << std::endl;
  for(int i = 0; i < _itemCount; ++i) {
    if(_inventory[i]) {
      std::cout << i << ": " << _inventory[i]->getName() << "\n";
    }
  }
}

void player::setWeapon(item* weapon) {_weaponSlot = weapon; }
item* player::getWeapon() const {return _weaponSlot; }

void player::setArmor(item* armor) {_armorSlot = armor; }
item* player::getArmor() const {return _armorSlot; }

int player::attack() {
  int dmg = _atkPower;
  if (_weaponSlot) {
    //Damage boost item code here
  }
  return dmg;
}

void player::takeDamage(int damage) {
  int reducedDamage = damage - _defense;
  if(_armorSlot) {
    //armor stuff stats
  }
  if (reducedDamage < 1) reducedDamage = 1;
  _health -= reducedDamage;
  if (_health <= 0) _health = 0;
  std::cout << _name << "took " << reducedDamage << "damage" << std::endl;
}

void player::equipItem(item* item) {
  if (auto* weapon = dynamic_cast<damage_Boost_Item*>(item)) {
    setWeapon(weapon);
  } else if (auto* armor = dynamic_cast<defense_Item*>(item)) {
    setArmor(armor);
  } else {
    std::cout << "Item cannot be equipped." << std::endl;
  }

}

void player::unequipWeapon(room* currentRoom) { //If inventory is full, drop item on floor
  if(_weaponSlot) {
    if(_itemCount < inventorySize) {
      _inventory[_itemCount++] = _weaponSlot;
    } else {
      currentRoom->addItem(_weaponSlot);
    }
    _weaponSlot = nullptr;
  }
}

void player::unequipArmor(room* currentRoom) {
  if(_armorSlot) {
    if(_itemCount < inventorySize) {
      _inventory[_itemCount++] = _armorSlot;
    } else {
      currentRoom->addItem(_armorSlot);
    }
    _armorSlot = nullptr;
  }
}