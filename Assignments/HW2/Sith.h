//
// Created by riley on 9/16/2025.
//

#ifndef SITH_H
#define SITH_H
#include <string>

#include "Character.h"

namespace starwars {
    class Sith : public starwars::character {
    protected:
    	int _rageLevel; //Unique Sith ability
      public:
        Sith(std::string name = "Unknown Sith", int health = 120, int lightsaberSkill = 60, int rageLevel = 0); //Paramaterized Constructor
        ~Sith(); //Deconstructor


    	void setRageLevel(int rage);
    	int getRageLevel();
    	std::string getType() override;
        int attack() override;
    	int takeDamage(int damage) override;
    	void buildRage(int amount); //rage builds based on damage taken
    	void resetRage(); //reset after attack
    	virtual void saveToFile(std::string &fileName);
    	virtual void loadFromFile(std::string &fileName);
    };

}





#endif //SITH_H
