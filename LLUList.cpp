// Implementation file for AUList 
#include <iostream> 
#include "LLUList.h" 
 
struct LNode { 
    int item; 
    LNode* next; 
}; 
 
LLUList::LLUList() {
  ListStart = nullptr;
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
}

 
bool LLUList::IsFull() const {
  try {
    LNode* testNode = new LNode;
    delete testNode;
    return false;
  } catch (std::bad_alloc&) {
    return true;
  }
}
 
int LLUList::GetLength() const {
  int length = 0;
  LNode* ptr = ListStart;
  while (ptr != nullptr) {
    ptr = ptr->next;
    length++;
  }
  return length;
}

int LLUList::GetItem(int gitem) {
  int position = 0;
  LNode* nodeIter = ListStart;
  while ((nodeIter != nullptr) && (nodeIter->item != gitem)) {
    nodeIter = nodeIter->next;
    position++;
  }
  return (nodeIter == nullptr) ? -1 : position;
}

void LLUList::PutItem(int newitem) {
  LNode* newNode = new LNode;
  newNode->item = newitem;
  newNode->next = ListStart;
  ListStart = newNode;
}

void LLUList::DeleteItem(int ditem) {
  if (ListStart == nullptr) return;

  LNode *tmpNode;
  if (ListStart->item == ditem) {
    tmpNode = ListStart;
    ListStart = ListStart->next;
  } else {
    LNode* nodeIter = ListStart;
    while (nodeIter->next != nullptr && nodeIter->next->item != ditem) {
      nodeIter = nodeIter->next;
    }
    if (nodeIter->next == nullptr) return;
    tmpNode = nodeIter->next;
    nodeIter->next = nodeIter->next->next;
  }
  delete tmpNode;
}

void LLUList::ResetList() {
  curPos = ListStart;
}

int LLUList::GetNextItem() {
  if (curPos == nullptr)
    throw 38; // EOS Exception

  int item = curPos->item;
  curPos = curPos->next;
  return item;
}

void LLUList::PrintList() {
  LNode* printPtr = ListStart;
  std::cout << "(";
  while (printPtr != nullptr) {
    std::cout << printPtr->item;
    if (printPtr->next != nullptr)
      std::cout << ", ";
    printPtr = printPtr->next;
  }
  std::cout << ")" << std::endl;
}

int LLUList::getMin() {
  if (ListStart == nullptr) {
    std::cerr << "Error: List is empty." << std::endl;
    return -1;
  }

  int minVal = ListStart->item;
  LNode* current = ListStart->next;
  while (current != nullptr) {
    if (current->item < minVal)
      minVal = current->item;
    current = current->next;
  }
  return minVal;
}

int LLUList::getRange() {
  if (ListStart == nullptr) {
    std::cerr << "Error: List is empty." << std::endl;
    return -1;
  }

  int minVal = ListStart->item;
  int maxVal = ListStart->item;
  LNode* current = ListStart->next;
  while (current != nullptr) {
    if (current->item < minVal)
      minVal = current->item;
    if (current->item > maxVal)
      maxVal = current->item;
    current = current->next;
  }

  return maxVal - minVal;
}
