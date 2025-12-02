//
// Created by riley on 12/1/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "character.h"

class item;
class room;
//Constant inventory size, (slots 1-0 for num row)
const int inventorySize = 10;
class player : public character {
  private:
    //player info
    int _defense;
    Item* _inventory[inventorySize];
    int _itemCount;
    Item* _weaponSlot; //Equipped weapon
    Item* _armorSlot; //Equipped Armor
  public:
    //Constructor
    player(std::string name, int startX, int startY, int health, int atkPower, int defense);
    //destructor
    ~player() override;
    //setters from character.h
    void setDefense(int defense);
    void setWeapon(Item* weapon);
    void setArmor(Item* armor);
    //getters most from character.h
    int getDefense() const;
    int getCurrentItemCount() const;
    Item* getWeapon() const;
    Item* getArmor() const;
    //helpers
    void heal(int healAmt);
    void addItem(const Item &item);
    void removeItem(const int slotIndex);
    void showInventory() const;
    void unequipWeapon(room* currentRoom);
    void unequipArmor(room* currentRoom);
    //overrides
    void attack() override;
    void takeDamage(int damage) override;
    void equipItem
};



#endif //PLAYER_H
