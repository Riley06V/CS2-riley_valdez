//
// Created by riley on 10/7/2025.
//

#include "Guardian.h"
#include <cstdlib> // for rand()
#include <iostream>

namespace starwars {

	Guardian::Guardian(std::string name)
		: Jedi(name, 150, 70, 60) {
		// High health, strong saber skill, moderate force
	}

	int Guardian::attack() {
		int base = Jedi::attack(); // Use Jedi's base attack logic
		bool crit = (rand() % 5 == 0); // 20% chance for critical hit
		if (crit) {
			std::cout << getName() << " lands a critical strike!\n";
			return base * 2;
		}
		return base;
	}

	std::string Guardian::getType() const {
		return "Guardian";
	}

}