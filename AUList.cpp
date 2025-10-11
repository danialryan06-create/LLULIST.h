#include <iostream>
#include "AUList.h"

AUList::AUList() {
    length = 0;
    currentPos = -1;
}

void AUList::MakeEmpty() {
    length = 0;
}

bool AUList::IsFull() const {
    return length == MAXSIZE;
}

int AUList::GetLength() const {
    return length;
}

int AUList::GetItem(int gitem) {
    for (int i = 0; i < length; i++) {
        if (ListItems[i] == gitem)
            return i;
    }
    return -1;
}

void AUList::PutItem(int item) {
    if (!IsFull()) {
        ListItems[length] = item;
        length++;
    }
}

void AUList::DeleteItem(int item) {
    int index = GetItem(item);
    if (index == -1)
        return;

    for (int i = index; i < length - 1; i++) {
        ListItems[i] = ListItems[i + 1];
    }
    length--;
}

void AUList::ResetList() {
    currentPos = -1;
}

int AUList::GetNextItem() {
    currentPos++;
    if (currentPos < length)
        return ListItems[currentPos];
    else
        return -1;
}

void AUList::PrintList() {
    std::cout << "(";
    for (int i = 0; i < length; i++) {
        std::cout << ListItems[i];
        if (i < length - 1)
            std::cout << ", ";
    }
    std::cout << ")" << std::endl;
}

int AUList::getMin() {
    if (length == 0) {
        // Handle empty list, could throw or return a sentinel value
        return -1; // Assuming -1 means empty list or no min
    }

    int minVal = ListItems[0];
    for (int i = 1; i < length; i++) {
        if (ListItems[i] < minVal) {
            minVal = ListItems[i];
        }
    }
    return minVal;
}

int AUList::getRange() {
    if (length == 0) {
        // Handle empty list, no range possible
        return -1; 
    }

    int minVal = ListItems[0];
    int maxVal = ListItems[0];
    for (int i = 1; i < length; i++) {
        if (ListItems[i] < minVal) {
            minVal = ListItems[i];
        }
        if (ListItems[i] > maxVal) {
            maxVal = ListItems[i];
        }
    }
    return maxVal - minVal;
}
AUList AUList::DuplicateSE(int first, int last) {
    AUList newList;

    if (first < 0 || last >= length || first > last)
        return newList;

    for (int i = first; i <= last && !newList.IsFull(); i++) {
        newList.PutItem(ListItems[i]);
    }

    return newList;
}
