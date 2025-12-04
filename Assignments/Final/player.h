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
    item* _inventory[inventorySize];
    int _itemCount;
    item* _weaponSlot; //Equipped weapon
    item* _armorSlot; //Equipped Armor
  	room* _currentRoom;
  public:
    //Constructor
    player(std::string name, int startX, int startY, int health, int atkPower, int defense);
    //destructor
    ~player() override;
    //setters from character.h
    void setDefense(int defense);
    void setWeapon(item* weapon);
    void setArmor(item* armor);
    void setCurrentRoom(room* currentRoom);
    //getters most from character.h
    int getDefense() const;
    int getCurrentItemCount() const;
    item* getWeapon() const;
    item* getArmor() const;
    room* getCurrentRoom() const;
    item* getItemAt(int index) const;
    //helpers
    void heal(int healAmt);
    void addItem(item *item);
    void removeItem(const int slotIndex);
    void showInventory() const;
    void unequipWeapon();
    void unequipArmor();
    void equipItem(item* item);
    void equipItemAt(int index, room* currentRoom);
    void useItemAt(int index);
    void removeItemByPointer(item* item);


    //overrides
    int	 attack() override;
    void takeDamage(int damage) override;
};



#endif //PLAYER_H
