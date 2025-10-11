#include <iostream>
#include "LLUList.h"

struct LNode {
    int item;
    LNode* next;
};

LLUList::LLUList() {
    ListStart = nullptr;
    curPos = nullptr;
}

LLUList::~LLUList() {
    MakeEmpty();
}

void LLUList::MakeEmpty() {
    LNode* tempPtr;
    while (ListStart != nullptr) {
        tempPtr = ListStart;
        ListStart = ListStart->next;
        delete tempPtr;
    }
    curPos = nullptr;
}

bool LLUList::IsFull() const {
    try {
        LNode* temp = new LNode;
        delete temp;
        return false;
    } catch (std::bad_alloc&) {
        return true;
    }
}

int LLUList::GetLength() const {
    int length = 0;
    LNode* temp = ListStart;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

int LLUList::GetItem(int gitem) {
    int pos = 0;
    LNode* temp = ListStart;
    while (temp != nullptr && temp->item != gitem) {
        temp = temp->next;
        pos++;
    }
    return (temp == nullptr) ? -1 : pos;
}

void LLUList::PutItem(int newItem) {
    LNode* newNode = new LNode;
    newNode->item = newItem;
    newNode->next = ListStart;
    ListStart = newNode;
}

void LLUList::DeleteItem(int item) {
    LNode* temp;
    if (ListStart == nullptr) return;

    if (ListStart->item == item) {
        temp = ListStart;
        ListStart = ListStart->next;
        delete temp;
        return;
    }

    LNode* current = ListStart;
    while (current->next != nullptr && current->next->item != item) {
        current = current->next;
    }

    if (current->next != nullptr) {
        temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

void LLUList::ResetList() {
    curPos = ListStart;
}

int LLUList::GetNextItem() {
    if (curPos == nullptr)
        throw 38;

    int val = curPos->item;
    curPos = curPos->next;
    return val;
}

void LLUList::PrintList() {
    LNode* temp = ListStart;
    std::cout << "(";
    while (temp != nullptr) {
        std::cout << temp->item;
        if (temp->next != nullptr)
            std::cout << ", ";
        temp = temp->next;
    }
    std::cout << ")" << std::endl;
}

int LLUList::getMin() {
    if (ListStart == nullptr)
        return -1;

    int minVal = ListStart->item;
    LNode* temp = ListStart->next;
    while (temp != nullptr) {
        if (temp->item < minVal)
            minVal = temp->item;
        temp = temp->next;
    }
    return minVal;
}

int LLUList::getRange() {
    if (ListStart == nullptr)
        return -1;

    int minVal = ListStart->item;
    int maxVal = ListStart->item;
    LNode* temp = ListStart->next;
    while (temp != nullptr) {
        if (temp->item < minVal)
            minVal = temp->item;
        if (temp->item > maxVal)
            maxVal = temp->item;
        temp = temp->next;
    }
    return maxVal - minVal;
}
