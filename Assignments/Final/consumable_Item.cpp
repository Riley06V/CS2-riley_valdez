//
// Created by riley on 12/1/2025.
//

#include "consumable_Item.h"
#include "player.h"
#include <iostream>

// default constructor
consumable_Item::consumable_Item()
    : item("Unknown", "No description", 0, 0),
      _effectLevel(0),
      _consumed(false) {}

// parameterized constructor with position
consumable_Item::consumable_Item(std::string itemName, std::string itemDescription,
                                 int x, int y, int effectLevel)
    : item(std::move(itemName), std::move(itemDescription), x, y),
      _effectLevel(effectLevel),
      _consumed(false) {}

consumable_Item::~consumable_Item() {}

void consumable_Item::setEffectLevel(int effectLevel) { _effectLevel = effectLevel; }
int consumable_Item::getEffectLevel() const { return _effectLevel; }
bool consumable_Item::consumed() { return _consumed; }

void consumable_Item::use(player& player) {
    if (_consumed) {
        std::cout << getName() << " has already been used.\n";
        return;
    }

    player.heal(_effectLevel);
    _consumed = true;

    std::cout << player.getName() << " consumed " << getName()
              << " and restored " << _effectLevel << " HP.\n";

    // remove from inventory (array version)
    player.removeItemByPointer(this);
}