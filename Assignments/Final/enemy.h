//
// Created by riley on 12/1/2025.
//

#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "character.h"
#include "item.h"


class enemy : public character {
  private:
    int _difficultyLevel;
    item* _heldItem;
  public:
    //constructor
    enemy(std::string name, int health, int attkPower, int difficultyPower, int xPos, int yPos);
    //destructor
    ~enemy() override;
    //Setters
    void setDifficultyLevel(int difficultyLevel);
    //Getters
    int getDifficultyLevel() const;
    //helpers
    Item* dropItem();
    //overrides
    void attack() override;
    void takeDamage(int damage) override;
};



#endif //ENEMY_H
