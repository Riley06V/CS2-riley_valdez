//
// Created by riley on 10/7/2025.
//
#ifndef DARTH_H
#define DARTH_H

#include "Sith.h"

namespace starwars {
	class Darth : public Sith {
	public:
  		Darth(std::string = "Unknown Darth", int health= 120 , int lightsaberSkill = 75, int rage = 15);
		// Overrides
		int attack() override;
		std::string getType() override;
	};
}

#endif // DARTH_H

