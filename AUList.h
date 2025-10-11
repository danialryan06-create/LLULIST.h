#ifndef AULIST_H
#define AULIST_H

#define MAXSIZE 10

class AUList {
public:
    AUList();

    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;
    int GetItem(int);
    void PutItem(int);
    void DeleteItem(int);
    void ResetList();
    void PrintList();
    int GetNextItem();
    int getMin();
    int getRange();
    AUList DuplicateSE(int first, int last);

private:
    int length;
    int ListItems[MAXSIZE];
    int currentPos;
};

#endif
