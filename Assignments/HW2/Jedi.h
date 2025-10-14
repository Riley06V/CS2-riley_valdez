//
// Created by riley on 9/16/2025.
//

#ifndef JEDI_H
#define JEDI_H
#include <string>
#include <fstream>

#include "Character.h"

namespace starwars {
    class Jedi : public starwars::character {
        private:
            int _forcePower;
        public:
            Jedi(std::string = "Unknown Jedi", int = 100, int = 50, int  = 75); //Paramertierzied Constructor
            ~Jedi(); //Default Destructor
            //Setters
            void setForcePower(int forcePower);
            //Getteres

            int getForcePower();
            //Helpers/bonus function
            int useForce(int power);
            //File IO
            void saveToFile(std::string &fileName);
            void loadFromFile(std::string &fileName);
    };
}


#endif //JEDI_H
