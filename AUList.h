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

  int getMin();              // Added
  int getRange();            // Added
  AUList DuplicateSE(int first, int last); // Added

private:
  int length;
  int ListItems[MAXSIZE];
  int currentPos;
};

#endif
