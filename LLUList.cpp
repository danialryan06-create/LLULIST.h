// Implementation file for AUList 
#include <iostream> 
#include "LLUList.h" 
 
struct LNode { 
    int item; 
    LNode* next; 
}; 
 
LLUList::LLUList() { 
  ListStart=NULL;   
} 
 
LLUList::~LLUList() {
  LNode* tempPtr;
  while (ListStart != NULL) {
    tempPtr = ListStart;
    ListStart = ListStart->next;
    delete tempPtr;
  }
}
 
bool LLUList::IsFull() const { 
  LNode* testNode; 
  try { 
    testNode = new LNode; 
    delete testNode; 
    return false; 
  } 
  catch(std::bad_alloc exception) { 
    return true; 
  } 
} 
 
int LLUList::GetLength() const { 
  LNode* LenPos = ListStart; 
  int length=0; 
  while (LenPos != NULL) { 
    LenPos=LenPos->next; 
    length++; 
  } 
  return length; 
}; 
 
int LLUList::GetItem(int gitem) { //Procedure is similar to that of AUList, although the 
relevant data is stored different. 
                           //also, it's better for LLUList to proceed in order from the 
beginning 
   int position=0; 
   LNode* nodeIter; 
   nodeIter=ListStart; 
   while ((nodeIter != NULL) && (nodeIter->item !=gitem)) { 
      nodeIter=nodeIter->next; 
      position++; } 
   if (nodeIter==NULL) 
      return -1; 
   else 
      return position; 
} 
 
void LLUList::MakeEmpty() { //Unlike the AUList implementation, we need to step through 
and delete EVERY node 
  LNode* tempPtr; 
  while (ListStart != NULL) { 
    tempPtr = ListStart; 
    ListStart = ListStart->next; 
    delete tempPtr; 
  }   
} 
 
 
void LLUList::PutItem(int newitem) { 
  LNode* newNode; //Get a pointer          
 newNode = new LNode; //Create a new node.  
 newNode->item = newitem; // Store the item in the node 
  newNode->next = ListStart; // Store address of next node  
 ListStart = newNode; // Redirect start of list 
} 
 
void LLUList::DeleteItem(int ditem) {
  LNode *tmpNode, *nodeIter;

  if (ListStart == nullptr) return;

  if (ListStart->item == ditem) {
    tmpNode = ListStart;
    ListStart = ListStart->next;
    delete tmpNode;
    return;
  }

  nodeIter = ListStart;
  while (nodeIter->next != nullptr && nodeIter->next->item != ditem)
    nodeIter = nodeIter->next;

  if (nodeIter->next == nullptr)
    return; // Item not found

  tmpNode = nodeIter->next;
  nodeIter->next = nodeIter->next->next;
  delete tmpNode;
}
 
 
void LLUList::ResetList() { 
  curPos=ListStart; 
} 
 
int LLUList::GetNextItem() { 
  int myitem; 
  if (curPos == NULL) //The implemented option throw an errors if someone tries to access 
an item past the last one.  
   throw(38); //EOS Exception 
  myitem = curPos->item; 
  curPos=curPos->next; 
  return myitem; 
}; 
 
void LLUList::PrintList() { 
  LNode* printPtr; 
  printPtr=ListStart; 
  std::cout<<"("; 
  while (printPtr != NULL) { 
    std::cout<<printPtr->item; 
    if (printPtr->next!=NULL) 
      std::cout<<", "; 
    printPtr=printPtr->next; 
  }     
 std::cout<<")"<<std::endl; 
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
