//
// Created by riley on 10/7/2025.
//

#include "Darth.h"
#include <iostream>
namespace starwars {
	starwars::Darth::Darth(std::string name)
		: Sith(name, 120, 75, 25) {} //Higher base health and saber skill. Starting rage

	int starwars::Darth::attack() {
  		if(_rageLevel >= 50) {
        	std::cout << getName() << " uses Force Choke to crush the enemy!\n";
            resetRage();
            return _lightsaberSkill + 35;
  		}
		return Sith::attack();
	}

    std::string starwars::Darth::getType() {
      return "Darth";
    }

}