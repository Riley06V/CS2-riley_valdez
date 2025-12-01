//
// Created by riley on 12/1/2025.
//

#ifndef ITEM_H
#define ITEM_H
#include <string>

class item {
  protected:
    std::string _name;
    std::string _description;
    int _x;
    int _y;
  public:
    virtual item(std::string name, std::string description, int x, int y);
    virtual ~item();
    //setters
    void setName(std::string name);
    void setDescription(std::string description);
    void setX(int x);
    void setY(int y);
    //getters
    std::string getName();
    std::string getDescription();
    int getX();
    int getY();
};



#endif //ITEM_H
