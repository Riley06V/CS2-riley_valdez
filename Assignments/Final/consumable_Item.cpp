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

// parameterized constructor
consumable_Item::consumable_Item(std::string itemName, std::string itemDescription, int effectLevel)
	: item(std::move(itemName), std::move(itemDescription), 0, 0),
	  _effectLevel(effectLevel),
	  _consumed(false) {}

// destructor
consumable_Item::~consumable_Item() {}

// setters
void consumable_Item::setEffectLevel(int effectLevel) {
	_effectLevel = effectLevel;
}

// getters
int consumable_Item::getEffectLevel() const {
	return _effectLevel;
}

// helpers
bool consumable_Item::consumed() {
	return _consumed;
}

// override
void consumable_Item::use(player& player) {
	if (_consumed) {
		std::cout << getName() << " has already been used.\n";
		return;
	}

	// For now, treat effectLevel as healing amount
	player.heal(_effectLevel);

	_consumed = true;
	std::cout << getName() << " was consumed.\n";
}