//
// Created by riley on 12/1/2025.
//

#ifndef DEFENSE_ITEM_H
#define DEFENSE_ITEM_H
#include "item.h"
#include <string>
class player;

class defense_Item : public item {
	private:
		int _defenseAmount;
		int _durability;
	public:
		//constructor
          defense_Item(std::string name, std::string description, int x, int y, int defenseAmount, int durability);
          //destructor
          ~defense_Item() override;
          //setters
          void setDefenseAmount(int defenseAmount);
          void setDurabilityLevel(int durabilityLevel);
          //getters
          int getDurabilityLevel() const;
          int getDefenseAmount() const;
          //override
          void use(player& player) override; //equipable uses durability over time
};



#endif ///DEFENSE_ITEM_H
