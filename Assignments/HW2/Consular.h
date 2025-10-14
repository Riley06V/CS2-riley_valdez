//
// Created by riley on 10/7/2025.
//

#ifndef CONSULAR_H
#define CONSULAR_H

#include "Jedi.h"

namespace starwars {
	class Consular : public Jedi {
	public:
		Consular(std::string name = "Consular");

		// Override takeDamage to include stronger force-based mitigation
		int takeDamage(int damage) override;

		// Identify class type
		std::string getType() const override;
	};
}

#endif // CONSULAR_H
