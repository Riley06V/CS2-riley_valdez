//
// Created by riley on 12/1/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class player {
  private:
    //player info
    std::string name;
    int health;
    int atkPower;
    int defense;
    int inventorySpace[];
    //player position
    int x;
    int y;
  public:
    //Constructor
    Player(std::string name, int startX, int startY, int health, int atkPower, int defense);

    //setters
    void setName();
    void setHealth();
    void setAtkPower();
    void setDefense();
    void setInventorySpace();
    void setX();
    void setY();
    //getters
    std::string getName();
    int getHealth();
    int getAtkPower();
    int getDefense();
    int getInventorySpace();
    int getX();
    int getY();
    //helpers
    void takeDamage(int damage);
    void heal(int healAmt);
    void addItem(const Item &item);
    void removeItem(const Item &item);
    void showInventory();
    bool isAlive();
};



#endif //PLAYER_H
