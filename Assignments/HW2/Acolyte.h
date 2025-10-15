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
		Acolyte(std::string name = "Acolyte");

		std::string getType() override;
		int takeDamage(int damage) override; //Dodge

	};
}

#endif //ACOLYTE_H
