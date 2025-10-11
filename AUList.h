#ifndef AULIST_H
#define AULIST_H

class AUList {
public:
    AUList(int cap = 100);   // Constructor with default parameter
    
    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;
    int GetItem(int gitem) const;
    void PutItem(int item);
    void DeleteItem(int item);
    void ResetList();
    int GetNextItem();
    void PrintList() const;
    AUList DuplicateSE(int first, int last) const;

private:
    int* items;
    int length;
    int capacity;
    int currentPos;
};

#endif
