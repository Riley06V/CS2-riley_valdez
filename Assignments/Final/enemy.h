#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "character.h"
#include "item.h"
#include "damage_Boost_Item.h"
#include "defense_Item.h"
#include "consumable_Item.h"

class enemy : public character {
private:
    int _difficultyLevel;
public:
    // constructor
    enemy(std::string name, int health, int attkPower,
          int difficultyLevel, int xPos, int yPos);

    // destructor
    ~enemy() override = default;

    // setters
    void setDifficultyLevel(int difficultyLevel);

    // getters
    int getDifficultyLevel() const;

    // overrides
    int attack() override;
    void takeDamage(int damage) override;

    // loot factory
    virtual item* createDrop() const { return nullptr; }
};

// Goblin enemy
class goblin : public enemy {
public:
    goblin(int x, int y)
        : enemy("Goblin", 20, 3, 1, x, y) {}

    item* createDrop() const override {
        return new damage_Boost_Item("Rusty Sword", "Dropped by goblin",
                                     getX(), getY(), 2, 5); // boost, durability
    }
};

// Skeleton enemy
class skeleton : public enemy {
public:
    skeleton(int x, int y)
        : enemy("Skeleton", 25, 4, 2, x, y) {}

    item* createDrop() const override {
        return new defense_Item("Bone Shield", "Dropped by skeleton",
                                getX(), getY(), 3, 10); // defense, durability
    }
};

// Mage enemy
class mage : public enemy {
public:
    mage(int x, int y)
        : enemy("Mage", 30, 6, 3, x, y) {}

    item* createDrop() const override {
        return new consumable_Item("Potion", "Restores Health", getX(), getY(), 15);
    }
};

#endif // ENEMY_H