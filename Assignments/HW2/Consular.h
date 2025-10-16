//
// Created by riley on 10/7/2025.
//

#ifndef CONSULAR_H
#define CONSULAR_H

#include "Jedi.h"

namespace starwars {
	class Consular : public Jedi {
	public:
		Consular(std::string name = "Unknown Council Member", int health = 150, int skill = 70, int force = 60);

		// Override takeDamage to include stronger force-based mitigation
		int takeDamage(int damage) override;

		// Identify class type
		std::string getType() override;
	};
}

#endif // CONSULAR_H
