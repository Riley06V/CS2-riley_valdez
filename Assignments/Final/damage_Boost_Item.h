//
// Created by riley on 12/1/2025.
//

#ifndef DAMAGE_BOOST_ITEM_H
#define DAMAGE_BOOST_ITEM_H
#include "item.h"
#include <string>


class damage_Boost_Item : protected item {
	private:
          int _boostToDamage;
          int _durability;
	public:
          //constrtuctor
          damage_Boost_Item(std::string name, std::string description, int x, int y int boostToDamage, int durability);
          //destructor
          virtual ~damage_Boost_Item();
          //setters
          void setDurability(int durability);
          void setBoostToDamage(int boostToDamage);
          //getters
          int getBoostToDamage();
          int getDurability();

};



#endif //DAMAGE_BOOST_ITEM_H
