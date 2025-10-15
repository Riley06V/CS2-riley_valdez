//
// Created by riley on 10/7/2025.
//

#ifndef GUARDIAN_H
#define GUARDIAN_H

#include "Jedi.h"

namespace starwars {
	class Guardian : public Jedi {
	public:
		Guardian(std::string name = "Guardian");

		// Override attack to include critical hit chance
		int attack() override;

		// Identify class type
		std::string getType() override;
	};
}

#endif // GUARDIAN_H