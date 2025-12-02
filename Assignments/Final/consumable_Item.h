//
// Created by riley on 12/1/2025.
//

#ifndef CONSUMABLE_ITEM_H
#define CONSUMABLE_ITEM_H
#include "item.h"
#include <string>
class player;

class consumable_Item : public item {
	private:
          int _effectLevel;
          bool _consumed;
	public:
          consumable_Item();
          consumable_Item(std::string itemName, std::string itemDescription, int effectLevel);
          ~consumable_Item() override;
          //setters
          void setEffectLevel(int effectLevel);
          //getters
          int getEffectLevel() const;
          //helpers
          bool consumed(); //returns true if the item was consumed successfully.
          //override
          void use(player& player) override; //one time buff since consumable
};



#endif //CONSUMABLE_ITEM_H
