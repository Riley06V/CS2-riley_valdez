//
// Created by riley on 12/1/2025.
//

#include "damage_Boost_Item.h"
#include "player.h"
#include <iostream>

// constructor
damage_Boost_Item::damage_Boost_Item(std::string name, std::string description,
									 int x, int y, int boostToDamage, int durability)
	: item(std::move(name), std::move(description), x, y),
	  _boostToDamage(boostToDamage),
	  _durability(durability) {}

// destructor
damage_Boost_Item::~damage_Boost_Item() {}

// setters
void damage_Boost_Item::setDurability(int durability) {
	_durability = durability;
}

void damage_Boost_Item::setBoostToDamage(int boostToDamage) {
	_boostToDamage = boostToDamage;
}

// getters
int damage_Boost_Item::getBoostToDamage() const {
	return _boostToDamage;
}

int damage_Boost_Item::getDurability() const {
	return _durability;
}

// override
void damage_Boost_Item::use(player& player) {
    player.equipItem(this);

    std::cout << player.getName() << " equipped " << getName()
              << " (+" << _boostToDamage << " attack).\n";
}