//
// Created by riley on 12/1/2025.
//

#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <vector>
#include <utility>
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

//ascii grid stuff
  	std::vector<std::string> _grid;
    int _width;
    int _height;
    int _doorX;
    int _doorY;
    std::vector<std::pair<int, int>> _itemPositions;
    std::vector<std::pair<int, int>> _enemyPositions;
  public:
    room(const std::string& description,const std::vector<std::string>& grid, bool isTreasureRoom);
    ~room();

    //setters
    void setDescription(const std::string& description);
    void setEnemy(enemy* enemy);
    void setTreasure(bool treasure);
    //getters
    std::string getDescription() const;
    enemy* getEnemy() const;
    int getX() const;
    int getY() const;
    bool isTreasureRoom() const;
    //methods item management
    void addItem(item* item);
    void removeItem(item* target);
    const std::vector<item*>& getItems() const;
    //movement + queries
    bool canMoveTo(int x, int y) const;
    bool isDoor(int x, int y) const;
    bool isItem(int x, int y) const;
    bool isEnemy(int x, int y) const;
    //state changes
    void pickupItemAt(int x, int y);
    bool revealEnemyAt(int x, int y);
    void addHiddenEnemy(int x, int y);
    //ASCII rendering
    std::vector<std::string> renderAscii(const player* player) const;
    //more research needed for this last one
};



#endif //ROOM_H
