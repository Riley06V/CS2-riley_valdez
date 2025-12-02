//
// Created by riley on 12/1/2025.
//

#ifndef DAMAGE_BOOST_ITEM_H
#define DAMAGE_BOOST_ITEM_H
#include "item.h"
#include <string>
class player;

class damage_Boost_Item : public item {
	private:
          int _boostToDamage;
          int _durability;
	public:
          //constrtuctor
          damage_Boost_Item(std::string name, std::string description, int x, int y int boostToDamage, int durability);
          //destructor
          ~damage_Boost_Item() override;
          //setters
          void setDurability(int durability);
          void setBoostToDamage(int boostToDamage);
          //getters
          int getBoostToDamage() const;
          int getDurability() const;
          //override
          void use(player *player) override; //equip, uses durability over time

};

#endif //DAMAGE_BOOST_ITEM_H
