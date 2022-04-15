/**
 * Author: Ayşe Kelleci
 * 21902532
 * 4 January 2022 
 * VERSİON:1.0
 * Array based Stack implementation 
 */

#include <iostream>
using namespace std;
#include "Stack.h"


//constructor
Stack :: Stack() : top(-1)
{}

bool Stack:: isEmpty() const
{
    if(top < 0)
        return true;

    return false;
}

bool Stack:: push(StackItemType newItem) // push new item if stack is not exceed the capacity
{
    if( top >= MAX_STACK -1)
        return false;

    else
    {
        top++;
        items[ top] = newItem;
    }
    return true;
}

bool Stack:: pop()
{
    if( top < 0)
    {
        return false;
    }
    else
    {
        top--;
        return true;
    }
}

bool Stack:: pop( StackItemType& stackTop) //pops the top item and store it in stackTop
{
    if( isEmpty())
    {
        return false;
    }

    else {  
        stackTop = items[top];
        top--;
        return true;
   }
}

bool Stack::getTop(StackItemType& stackTop) const
{
    if(isEmpty())
    {
        return false;
    }

    else
    {
        stackTop = items[top];
        return true;
    }
}

string Stack:: gettingTop()
{
    //returns top item
    return items[top];
}

