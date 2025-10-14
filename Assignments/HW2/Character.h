//
// Created by riley on 10/7/2025.
//

#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

namespace starwars {
	class character {
          protected: //copied form Jedi.h
 			std::string _name;
            int _health;
            int _lightsaberSkill;
          public:  //copied from Jedi.h
			character(std::string name = "", int health = 100, int lightsaberSkill = 0);
			~character();
			void setName(std::string name);
            void setHealth(int health);
            void setLightsaberSkill(int lightsaberSkill);
            std::string getName();
            int getHealth();
            int getLightsaberSkill();
            virtual int attack();
            virtual int takeDamage(int damage);
			virtual void saveToFile(std::string &fileName);
			virtual void loadFromFile(std::string &fileName);
	};
}


#endif //CHARACTER_H
