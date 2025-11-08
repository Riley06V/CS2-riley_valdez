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
    Node<T1> *curr = _head;
    while (curr != nullptr) {
        Node<T1> *nextNode= curr->_next;
        delete curr;
        curr = nextNode;
    }
    listSize = 0;
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
    newNode->setNext(_head);
    newNode->setPrev(nullptr);
    if (_head != nullptr) {
        _head->setPrev(newNode);
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
    return _head->getData();
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_front()
{
    //make sure its not empty
    if (empty()) {
        cout << "List is empty" << endl;
        return 0;
    }
    Node<T1> *temp = _head;
    T1 data = temp->getData();
    //move head to the next node
    _head = temp->getNext();
    if (_head != nullptr) {
        _head->setPrev(nullptr);
    } else {
        _tail = nullptr;
    }
    delete temp;
    listSize--;
    return data;
}

// add an element to the end of hte list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
    Node<T1> *newNode = new Node<T1>(data);
    newNode->getPrev() = _tail; //add-on to the back, newNode now end
    if (_tail != nullptr) {
        _tail->setNext(newNode);
    } else {
        _head = newNode; //first node case
    }
    _tail = newNode;
    listSize++;
}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
    if (empty()) {
        cout << "List is empty" << endl;
        return 0;
    }
    return _tail->getData();
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_back()
{
    if (empty()) {
        cout << "List is empty" << endl;
        return 0;
    }
    Node<T1> *temp = _tail;
    T1 data = temp->getData();
    //move tail to the previous
    _tail = temp->getPrev();
    if (_tail != nullptr) {
        _tail->setNext(nullptr);
    } else {
        _head = nullptr; //empty list
    }
    delete temp;
    listSize--;
    return data;
}

// overloading <<, should return a space separated stream of all of the elements
template <class T1>
ostream &operator<<(ostream &os, const List<T1> &list)
{
    Node<T1> *curr = list.getHead();
    while (curr != nullptr) {
        os << curr->getData() << " "; //print element's data
        curr = curr->getNext(); //Go to the next element
    }
    return os;
}

// should iterate through each list to check that they are exactly the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
    if (listSize != rhs.listSize) return false;
    Node<T1> *curr1 = _head;
    Node<T1> *curr2 = rhs._head;
    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr1->getData() != curr2->getData()) return false; //if one is not equal to the other in the location break
        curr1 = curr1->getNext(); //go through both until nullptr
        curr2 = curr2->getNext();
    }
    return true; //both reached nullptr at the same time, so equal
}