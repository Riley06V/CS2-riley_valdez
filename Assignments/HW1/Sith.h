//
// Created by riley on 9/16/2025.
//

#ifndef SITH_H
#define SITH_H
#include <string>
namespace starwars {
    class Sith {
      private:
        std::string _name;
        int _health;
        int _lightsaberSkill;
      public:
        Sith(std::string name, int health, int lightsaberSkill); //Paramaterized Constructor
        ~Sith(); //Deconstructor
        //Getters
        std::string getName();
        int getHealth();
        int getLightsaberSkill();
        //Setters
        void setName(std::string name);
        void setHealth(int health);
        void setLightsaberSkill(int lightsaberSkill);
        //Helpers
        int attack();
        int takeDamage(int damage);
    };

}





#endif //SITH_H
