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

        // Overrides
        int attack() override;
        int takeDamage(int damage) override;

        // Optional: identify type
        std::string getType() const override;
    };
}

#endif // DARTH_H

