//
// Created by riley on 12/1/2025.
//

#include "defense_Item.h"
#include "player.h"
#include <iostream>

// constructor
defense_Item::defense_Item(std::string name, std::string description,
						   int x, int y, int defenseAmount, int durability)
	: item(std::move(name), std::move(description), x, y),
	  _defenseAmount(defenseAmount),
	  _durability(durability) {}

// destructor
defense_Item::~defense_Item() {}

// setters
void defense_Item::setDefenseAmount(int defenseAmount) {
	_defenseAmount = defenseAmount;
}

void defense_Item::setDurabilityLevel(int durabilityLevel) {
	_durability = durabilityLevel;
}

// getters
int defense_Item::getDefenseAmount() const {
	return _defenseAmount;
}

int defense_Item::getDurabilityLevel() const {
	return _durability;
}

// override
void defense_Item::use(player& player) {
	// Equip into armor slot
	player.equipItem(this);

	// Example: durability decreases each time it’s used
	if (_durability > 0) {
		_durability--;
		std::cout << player.getName() << " equipped " << getName()
				  << " (+" << _defenseAmount << " defense). "
				  << "Durability remaining: " << _durability << "\n";
	} else {
		std::cout << getName() << " is broken and cannot be used.\n";
	}
}

