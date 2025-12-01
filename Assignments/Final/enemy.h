//
// Created by riley on 12/1/2025.
//

#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "item.h"


class enemy {
  private:
    std::string name;
    int health;
    int attkPower;
    int difficultyPower;
    item heldItem;
    int xPos;
    int yPos;
  public:
    //constructor
    enemy(std::string name, int health, int attkPower, int difficultyPower, int xPos, int yPos);
    //Setters
    void setName(std::string name);
    void setHealth(int health);
    void setAttkPower(int attkPower);
    void setDifficultyPower(int difficultyPower);
    void setXPos(int xPos);
    void setYPos(int yPos);
    //Getters
    std::string getName();
    int getHealth();
    int getAttkPower();
    int getDifficultyPower();
    int getXPos();
    int getYPos();
    //helpers
    int attack();
    int takeDamage();
    int dropItem();
    bool isAlive();
};



#endif //ENEMY_H
