#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class List
{
    private:
        Node<T1> *_head;
        Node<T1> *_tail;
        size_t listSize;

    public:
        List();
        ~List();

        bool empty();
        size_t size();

        void push_front(T1);
        T1 pop_front();
        T1 front();
        void push_back(T1);
        T1 pop_back();
        T1 back();

        bool operator==(const List<T1>&);
        // Have to declare a template for friend functions using a different template variable
        template <class T2>
        friend ostream &operator<<(ostream &, const List<T2> &);
};

// set to nullptr and initialize listSize
template <class T1>
List<T1>::List()
{
    _head = nullptr;
    _tail = nullptr;
    listSize = 0;
}

// iteratively delete the list starting at _head
template <class T1>
List<T1>::~List()
{
}

// return true if the list is empty, false otherwise.
// Do not just check listSize, should actually check _head and _tail
template <class T1>
bool List<T1>::empty()
{
    return _head == nullptr && _tail == nullptr;
}

// return number of elements in list
template <class T1>
size_t List<T1>::size()
{
    return listSize;
}

// add an element to the beginning of the list, updating _head
template <class T1>
void List<T1>::push_front(T1 data)
{
    Node<T1> *newNode = new Node<T1>(data);
    newNode->next = _head;
    if (_head != nullptr) {
        _head->prev = newNode;
    } else {
        _tail = newNode; //first
    }
    _head = newNode;
    listSize++;
}

// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
{
    if (_head == nullptr) {
        cout << "List is empty" << endl;
        return 0;
    }
    return _head->data;
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_front()
{
    //make sure its not empty
    if (_head == nullptr) return nullptr;
    Node<T1> *temp = _head;
    //move head to the next node
    _head = _head->next;
    if (_head != nullptr) {
        _head->prev = nullptr;
    }
    delete temp;
    listSize--;
    return _head->data;
}

// add an element to the end of hte list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
    if (_tail == nullptr) {
        cout << "List is empty" << endl;
        return 0;
    }
    return _tail->data;
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_back()
{
    if (_tail == nullptr) return nullptr;
    Node<T1> *temp = _tail;
    //move tail to the previous
    _tail = _tail->prev;
    if (_tail != nullptr) {
        _tail->next = nullptr;
    }
    delete temp;
    listSize--;
    return _tail->data;
}

// overloading <<, should return a space separated stream of all of the elements
template <class T1>
ostream &operator<<(ostream &os, const List<T1> &list)
{
}

// should iterate through each list to check that they are exactly the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
}