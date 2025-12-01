//
// Created by riley on 12/1/2025.
//

#ifndef CONSUMABLE_ITEM_H
#define CONSUMABLE_ITEM_H
#include "item.h"
#include <string>


class consumable_Item : protected item {
	private:
          int effectLevel;
	public:
          consumable_Item();
          consumable_Item(std::string itemName, std::string itemDescription, int effectLevel);
          ~consumable_Item();
          //setters
          void setEffectLevel(int effectLevel);
          //getters
          int getEffectLevel();
          //helpers
          bool consumed();
};



#endif //CONSUMABLE_ITEM_H
