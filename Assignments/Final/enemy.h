//
// Created by riley on 12/1/2025.
//

#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "character.h"
#include "item.h"


class enemy : protected character {
  private:
    int _difficultyLevel;
    item* _heldItem;
  public:
    //constructor
    enemy(std::string name, int health, int attkPower, int difficultyPower, int xPos, int yPos);
    //destructor
    ~enemy();
    //Setters
    void setDifficultyLevel(int difficultyLevel);
    //Getters
    int getDifficultyLevel();
    //helpers
    int dropItem();
};



#endif //ENEMY_H
