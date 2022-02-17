// intlist.cpp
// Implements class IntList
// Hao Wu, 01/27/2022

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    this->first = 0;
    Node* temp = source.first;
    while (temp != 0)
    {
        this->append(temp->info);
        temp = temp->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node *cur = first;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node *n = first;
    while (n) {
        sum += n->info;
        n = n->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *n = first;
    while (n) {
        if (value == n->info) {
            return true;
        }
        n = n->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max = 0;
    Node *n = first;
    while (n) {
        if (max < n->info) {
            max = n->info;
        }
        n = n->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double avg = 0;
    Node *n = first;
    double sum1 = sum() + 0.0;
    double count1 = count() + 0.0;
    if (count1 == 0.0) {
        avg = 0.0;
    } else {
        avg = sum1 / count1;
    }
    return avg;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        first = new Node;
        first->info = value;
        first->next = n;
    }
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    this->~IntList();
    this->first = 0;
    Node* temp = source.first;
    while (temp != 0)
    {
        this->append(temp->info);
        temp = temp->next;
    }
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
