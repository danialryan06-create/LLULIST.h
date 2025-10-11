#include "AUList.h"
#include <iostream>

// Constructor with default capacity
AUList::AUList(int cap) : capacity(cap), length(0), currentPos(-1) {
    items = new int[capacity];
}

void AUList::MakeEmpty() {
    length = 0;
}

bool AUList::IsFull() const {
    return length == capacity;
}

int AUList::GetLength() const {
    return length;
}

int AUList::GetItem(int gitem) const {
    if (gitem >= 0 && gitem < length)
        return items[gitem];
    // Handle error if needed
    return -1; // or throw exception
}

void AUList::PutItem(int item) {
    if (!IsFull()) {
        items[length] = item;
        length++;
    }
    // else handle overflow
}

void AUList::DeleteItem(int item) {
    for (int i = 0; i < length; i++) {
        if (items[i] == item) {
            // Shift left remaining items
            for (int j = i; j < length - 1; j++) {
                items[j] = items[j + 1];
            }
            length--;
            break;
        }
    }
}

void AUList::ResetList() {
    currentPos = -1;
}

int AUList::GetNextItem() {
    currentPos++;
    if (currentPos < length)
        return items[currentPos];
    else
        return -1; // or handle end of list
}

void AUList::PrintList() const {
    for (int i = 0; i < length; i++) {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}

AUList AUList::DuplicateSE(int first, int last) const {
    AUList newList(last - first + 1);
    for (int i = first; i <= last && i < length; i++) {
        newList.PutItem(items[i]);
    }
    return newList;
}
