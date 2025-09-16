//
// Created by riley on 9/16/2025.
//

#ifndef JEDI_H
#define JEDI_H

namespace starwars {
    class Jedi {
        private:
            std::string _name;
            int _health;
            int _lightsaberSkill;
            int _forcePower;
        public:
            Jedi(std::string = "Uknown Jedi", int = 100, int = 50, int  = 75); //Paramertierzied Constructor
            ~Jedi(); //Default Destructor
            //Setters
            void setName();
            void setHealth();
            void setLightsaberSkill();
            void setForcePower();
            //Getteres
            std::string getName();
            int getHealth();
            int getLightsaberSkill();
            int getForcePower();
            //Helpers/bonus functions
            int attack();
            int useForce(int power);
            int takeDamage(int damage);
    };



}


#endif //JEDI_H
