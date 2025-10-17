//
// Created by riley on 10/7/2025.
//

#include "Consular.h"
#include <algorithm> // for std::max
#include <iostream>

namespace starwars {

	Consular::Consular(std::string name, int health, int lightsaberSkill, int forcePower)
		: Jedi(name, 100, 40, 120) {
		// Lower health, modest saber skill, high force power
	}

	int Consular::takeDamage(int damage) {
		int mitigation = getForcePower() / 10;
		int actualDamage = std::max(1, damage - mitigation);
		_health -= actualDamage;
		std::cout << getName() << " uses the Force to reduce damage.\n";
		return _health;
	}

	std::string Consular::getType() {
		return "Consular";
	}

}