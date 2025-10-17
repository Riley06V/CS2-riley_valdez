//
// Created by riley on 10/7/2025.
//

#include "Darth.h"
#include <iostream>
namespace starwars {
	Darth::Darth(std::string name, int health, int lightsaberSkill, int rageLevel)
			: Sith(name, 120, 75, 25) {
          _type = "Darth";
			} //Higher base health and saber skill. Starting rage

	int Darth::attack() {
		if(_rageLevel >= 50) {
			std::cout << getName() << " uses Force Choke to crush the enemy!\n";
			resetRage();
			return _lightsaberSkill + 35;
		}
		return Sith::attack();
	}

	std::string Darth::getType() {
		return "Darth";
	}

}