#include <string>
#include "StackType.h"
#include "QueType.h"

bool isCodeChar( char ch, const std::string& code) {
  return code.find(ch) != std::string::npos;
}

std::string decode(std::string exp, std::string code) {
  StackType<char> codeStack;
  QueType<char> normalQueue;

  for (int i = 0; i < exp.length(); i++) {
    char current = exp.at(i);

    if (isCodeChar(current, code)) {
      codeStack.Push(current);
    } else {
      normalQueue.Enqueue(current);
    }
  }

  std::string result = "";

  while (!normalQueue.IsEmpty()) {
    char ch;
    normalQueue.Dequeue(ch);
    result += ch;
  }

  while (!codeStack.IsEmpty()) {
    char ch;
    codeStack.Pop(ch);
    result += ch;
  }

  return result;
}
