//
// Created by riley on 10/7/2025.
//

#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

namespace starwars {
	class character {
	protected:
		std::string _name;
		int _health;
		int _lightsaberSkill;
		std::string _type;
	public:
		character(std::string name, int health, int skill); // full base constructor
		virtual ~character(); // virtual destructor
		void setName(std::string name);
        void setHealth(int health);
        void setLightsaberSkill(int lightsaberSkill);
		void setType(std::string type);
        std::string getName();
        int getHealth();
        int getLightsaberSkill();
		virtual std::string getType();
        virtual int attack();
        virtual int takeDamage(int damage);
		virtual void saveToFile(std::string &fileName);
		virtual void loadFromFile(std::string &fileName);
	};
}


#endif //CHARACTER_H
