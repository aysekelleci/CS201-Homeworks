/** Ayşe Kelleci 21902532
 *  Stack header file 
 *  @version 1.0
 */

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>

using namespace std;

const int MAX_STACK = 100;
typedef string StackItemType;

class Stack{

public:
   Stack();

   bool isEmpty() const;
   bool push(StackItemType newItem);
   bool pop();
   bool pop(StackItemType& stackTop);
   bool getTop(StackItemType& stackTop) const;
   string gettingTop();

private:
   // array of stack items
   StackItemType items[MAX_STACK];
   // index to top of stack
   int top;               
};


#endif // STACK_H


