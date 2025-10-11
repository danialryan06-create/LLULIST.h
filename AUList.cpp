#include <iostream>
#include <limits>
#include "AUList.h"
using namespace std;

AUList::AUList(int cap) {
    capacity = cap;
    length = 0;
    items = new int[capacity];
    currentPos = 0;
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

int AUList::GetItem(int index) {
    if (index >= 0 && index < length)
        return items[index];
    else
        return -1; // or throw exception
}

void AUList::PutItem(int item) {
    if (!IsFull()) {
        items[length++] = item;
    }
}

void AUList::DeleteItem(int item) {
    int index = -1;
    for (int i = 0; i < length; i++) {
        if (items[i] == item) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < length - 1; i++) {
            items[i] = items[i + 1];
        }
        length--;
    }
}

void AUList::ResetList() {
    currentPos = 0;
}

int AUList::GetNextItem() {
    if (currentPos < length)
        return items[currentPos++];
    else
        return -1; // or throw exception
}

void AUList::PrintList() {
    for (int i = 0; i < length; i++)
        cout << items[i] << " ";
    cout << endl;
}


int AUList::getMin() {
    if (length == 0) return -1;

    int min = items[0];
    for (int i = 1; i < length; i++) {
        if (items[i] < min) {
            min = items[i];
        }
    }
    return min;
}


int AUList::getRange() {
    if (length == 0) return -1;

    int min = items[0];
    int max = items[0];
    for (int i = 1; i < length; i++) {
        if (items[i] < min) min = items[i];
        if (items[i] > max) max = items[i];
    }
    return max - min;
}


AUList AUList::DuplicateSE(int start, int end) {
    AUList newList(end - start + 1);
    for (int i = start; i <= end && i < length; i++) {
        newList.PutItem(items[i]);
    }
    return newList;
}

