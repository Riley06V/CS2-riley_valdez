//
// Created by riley on 12/1/2025.
//

#ifndef ITEM_H
#define ITEM_H
#include <string>
class player;

class item {
  protected:
    std::string _name;
    std::string _description;
    int _x;
    int _y;
  public:
    item(std::string name, std::string description, int x, int y);
    virtual ~item();
    //setters
    void setName(std::string name);
    void setDescription(std::string description);
    void setX(int x);
    void setY(int y);
    //getters
    std::string getName() const;
    std::string getDescription() const;
    int getX() const;
    int getY() const;

    virtual void use(player& player);
};



#endif //ITEM_H
