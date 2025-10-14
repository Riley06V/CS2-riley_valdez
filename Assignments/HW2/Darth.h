//
// Created by riley on 10/7/2025.
//

#ifndef DARTH_H
#define DARTH_H

#include "Sith.h"

namespace starwars {
    class Darth : public Sith {
    public:
        Darth(std::string name = "Darth");
		int rage;
        // Overrides

        std::string getType() override;
        void saveToFile(std::string &fileName) override;
        void loadFromFile(std::string &fileName) override;
    };
}

#endif // DARTH_H

