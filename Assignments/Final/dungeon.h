//
// Created by riley on 12/1/2025.
//

#ifndef DUNGEON_H
#define DUNGEON_H
#include <iostream> //another thing to get rid of warnings
#include "room.h"
#include "list.h"

class player;

class dungeon {
  private:
    List<room*> _rooms;
    room* _currentRoom;

    public:
      dungeon();
      ~dungeon();

      void addRoom(room* room); //push_back
      room* getCurrentRoom() const;
      void moveNext();
      void movePrevious();

      size_t size() const;
      bool empty() const;

      //Ascii rendering
      void renderCurrentRoom(const player* player) const;

};
#endif //DUNGEON_H
