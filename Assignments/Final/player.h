//
// Created by riley on 12/1/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "character.h"

//Constant inventory size, (slots 1-0 for num row)
const int inventorySize = 10;
class player : protected character {
  private:
    //player info
    int _defense;
    int _inventory[inventorySize];
    int _itemCount;
  public:
    //Constructor
    Player(std::string name, int startX, int startY, int health, int atkPower, int defense);
    //destructor
    ~player();
    //setters from character.h
    void setDefense(int defense);
    //getters most from character.h
    int getDefense();
    int getCurrentItemCount();
    //helpers
    void heal(int healAmt);
    void addItem(const Item &item);
    void removeItem(const int slotIndex);
    void showInventory() const;
};



#endif //PLAYER_H
