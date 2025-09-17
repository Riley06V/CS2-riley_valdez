//
// Created by riley on 9/16/2025.
//

#ifndef JEDI_H
#define JEDI_H
#include <string>
#include <fstream>
namespace starwars {
    class Jedi {
        private:
            std::string _name;
            int _health;
            int _lightsaberSkill;
            int _forcePower;
        public:
            Jedi(std::string = "Unknown Jedi", int = 100, int = 50, int  = 75); //Paramertierzied Constructor
            ~Jedi(); //Default Destructor
            //Setters
            void setName(std::string name);
            void setHealth(int health);
            void setLightsaberSkill(int lightsaberSkill);
            void setForcePower(int forcePower);
            //Getteres
            std::string getName();
            int getHealth();
            int getLightsaberSkill();
            int getForcePower();
            //Helpers/bonus functions
            int attack();
            int useForce(int power);
            int takeDamage(int damage);
            //File IO
            void saveToFile(std::string &fileName);
            void loadFromFile();
    };
}


#endif //JEDI_H
