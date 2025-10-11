#include <iostream>
#include "AUList.h"

AUList::AUList() {
  length = 0;
}

bool AUList::IsFull() const {
  return (length == MAXSIZE);
}

int AUList::GetLength() const {
  return length;
}

int AUList::GetItem(int gitem) {
  for (int i = length - 1; i >= 0; i--) {
    if (ListItems[i] == gitem)
      return i;
  }
  return -1;
}

void AUList::MakeEmpty() {
  length = 0;
}

void AUList::PutItem(int item) {
  if (!IsFull()) {
    ListItems[length++] = item;
  } else {
    std::cerr << "Warning: Tried to insert into full list." << std::endl;
  }
}

void AUList::DeleteItem(int item) {
  int index = GetItem(item);
  if (index == -1) return;

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
  return ListItems[currentPos];
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
    std::cerr << "Error: List is empty." << std::endl;
    return -1;
  }

  int minVal = ListItems[0];
  for (int i = 1; i < length; i++) {
    if (ListItems[i] < minVal)
      minVal = ListItems[i];
  }
  return minVal;
}

int AUList::getRange() {
  if (length == 0) {
    std::cerr << "Error: List is empty." << std::endl;
    return -1;
  }

  int minVal = ListItems[0];
  int maxVal = ListItems[0];

  for (int i = 1; i < length; i++) {
    if (ListItems[i] < minVal)
      minVal = ListItems[i];
    if (ListItems[i] > maxVal)
      maxVal = ListItems[i];
  }

  return maxVal - minVal;
}

AUList AUList::DuplicateSE(int first, int last) {
  AUList newList;

  if (first < 0 || last >= length || first > last) {
    std::cerr << "Error: Invalid range in DuplicateSE." << std::endl;
    return newList;
  }

  for (int i = first; i <= last; i++) {
    if (newList.IsFull()) {
      std::cerr << "Warning: Reached max capacity in DuplicateSE." << std::endl;
      break;
    }
    newList.PutItem(ListItems[i]);
  }

  return newList;
}
