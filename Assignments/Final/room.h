//
// Created by riley on 12/1/2025.
//

#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <vector>
class enemy;
class item;
class player;

class room {
  private:
    std::string _description;
    int _x;
    int _y;
    enemy* _enemy;
    std::vector<item*> _items;
    bool _isTreasureRoom;
  public:
    room(const std::string& description, int x, int y, bool isTreasureRoom);
    ~room();

    //setters
    void setDescription(const std::string& description);
    void setEnemy(enemy* enemy);
    //getters
    std::string getDescription() const;
    enemy* getEnemy() const;
    int getX() const;
    int getY() const;
    //metho;ds
    void addItem(item* item);
    void removeItem(size_t index);
    const std::vector<item*>& getItems() const;
    void setTreasure(bool treasure);
    bool isTreasureRoom() const;
    //ASCII rendering
    std::vector<std::string> renderAscii(const Player* player) const;
    //more research needed


};



#endif //ROOM_H
