//
// Created by riley on 12/1/2025.
//

#ifndef CONSUMABLE_ITEM_H
#define CONSUMABLE_ITEM_H

#include "item.h"
#include <string>

class consumable_Item : public item {
private:
    int _effectLevel;   // healing amount
    bool _consumed;
public:
    // default constructor
    consumable_Item();

    // parameterized constructor with position + effect
    consumable_Item(std::string itemName, std::string itemDescription,
                    int x, int y, int effectLevel);

    ~consumable_Item() override;

    // setters/getters
    void setEffectLevel(int effectLevel);
    int getEffectLevel() const;
    bool consumed();

    // override
    void use(player& player) override;
};

#endif // CONSUMABLE_ITEM_H
