//
// Created by riley on 12/1/2025.
//

#ifndef HEAL_ITEM_H
#define HEAL_ITEM_H
#include "item.h"
#include <string>

class heal_Item : protected item {
	private:
		int _healAmount;
		int _durability;
	public:
		//constructor
          heal_Item(std::string name, std::string description, int x, int y, int healAmount, int durability);
          //destructor
          virtual ~heal_Item();
          //setters
          void setHealAmount(int healAmount);
          void setUsageLevel(int usageLevel);
          //getters
          int getUsageLevel();
          int getHealAmount();
};



#endif ///HEAL_ITEM_H
