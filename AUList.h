#ifndef AULIST_H
#define AULIST_H

class AUList {
public:
    AUList(int cap = 100);         // Constructor
    void MakeEmpty();              // Empties the list
    bool IsFull() const;           // Checks if full
    int GetLength() const;         // Gets current length
    int GetItem(int index);        // Gets item at index
    void PutItem(int item);        // Adds item
    void DeleteItem(int item);     // Deletes item
    void ResetList();              // Prepares for iteration
    int GetNextItem();             // Returns next item
    void PrintList();              // Outputs list
    int getMin();                  // Returns min value (NEW)
    int getRange();                // Returns range (NEW)
    AUList DuplicateSE(int start, int end); // Returns sublist

private:
    int* items;
    int capacity;
    int length;
    int currentPos;
};

#endif
