//
// Created by riley on 10/7/2025.
//

#ifndef ACOLYTE_H
#define ACOLYTE_H
#include <string>

#include "Sith.h"

namespace starwars {
	class Acolyte : public starwars::Sith{
	public:
		Acolyte(std::string name = "Acolyte", int health =90, int lightsaberSkill= 65, int rageLevel= 40);

		std::string getType() override;
		int takeDamage(int damage) override; //Dodge

	};
}

#endif //ACOLYTE_H
