//
// Created by riley on 10/7/2025.
//

#ifndef ACOLYTE_H
#define ACOLYTE_H
#include <string>

#include "Sith.h"


class Acolyte : public starwars::Sith{
	public:
		Acolyte(std::string name = "Acolyte");
		float stealth;

		std::string getType() override;
		void saveToFile(std::string &fileName) override;
		void loadFromFile(std::string &fileName) override;

};



#endif //ACOLYTE_H
