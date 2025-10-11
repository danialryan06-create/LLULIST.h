#ifndef AULIST_H
#define AULIST_H

#include <stdexcept>  // for std::runtime_error

class AUList {
private:
    int* ListItems;   // pointer to array holding elements
    int length;       // current number of elements
    int capacity;     // max capacity of the array

public:
    AUList(int cap = 100);   // constructor
    ~AUList();               // destructor

    int getLength() const { return length; }
    int getMin();
    int getRange();

    // Other member functions you may have like add, remove, etc.

    // For the DuplicateSE task (not included here)
    // AUList DuplicateSE(int first, int last);
};

#endif
