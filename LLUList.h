#ifndef LLULIST_H
#define LLULIST_H

struct LNode;

class LLUList {
public:
  LLUList();
  ~LLUList();

  void MakeEmpty();
  bool IsFull() const;
  int GetLength() const;
  int GetItem(int);
  void PutItem(int);
  void DeleteItem(int);
  void ResetList();
  void PrintList();
  int GetNextItem();

  int getMin();   // Added
  int getRange(); // Added

private:
  LNode* ListStart;
  LNode* curPos;
};

#endif
