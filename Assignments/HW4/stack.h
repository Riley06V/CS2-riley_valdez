//
// Created by riley on 11/26/2025.
//

#ifndef STACK_H
#define STACK_H
#include "list.h" //doubly linked list

template <class T>
class stack {
  private:
    List<T> list;

  public:
    bool empty() {return list.empty();}
    size_t size() {return list.size();}

    void push(T data) {list.push_front(data);} //stack push
    T pop() {return list.pop_front();} //stack pop
    T top() {return list.front();} //peek at front

};



#endif //STACK_H
