#include "Acolyte.h"
#include <iostream>
#include <cstdlib> // for rand()

namespace starwars {

	Acolyte::Acolyte(std::string name, int health, int lightsaberSkill, int rageLevel)
		: Sith(name, 90, 65, 40) {
		// Lower health, decent saber skill, moderate rage
	}

	int Acolyte::takeDamage(int damage) {
		// Dodge chance scales with rageLevel (e.g., 0–100 → 0–30% dodge)
		int dodgeChance = std::min(30, _rageLevel / 3); // cap at 30%
		bool dodged = (rand() % 100) < dodgeChance;

		if (dodged) {
			std::cout << getName() << " dodges the attack with Sith agility!\n";
			buildRage(5); // small rage gain from adrenaline
			return _health;
		}

		// If not dodged, take damage and build rage
		_health -= damage;
		buildRage(damage / 2);
		return _health;
	}

	std::string Acolyte::getType() {
		return "Acolyte";
	}

}