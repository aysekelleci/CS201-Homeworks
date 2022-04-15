#ifndef ALGEBRAIC_EXPRESSION_H
#define ALGEBRAIC_EXPRESSION_H

#include "Stack.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//It converts an infix expression exp to its equivalent prefix form.
string infix2prefix( const string exp );
// It converts an infix expression exp to its equivalent postfix form.
string infix2postfix( const string exp );
// It converts a prefix expression exp to its equivalent infix form.
string prefix2infix( const string exp );
// It converts a prefix expression exp to its equivalent postfix form.
string prefix2postfix( const string exp );
// It converts a postfix expression exp to its equivalent infix form.
string postfix2infix( const string exp );
// It converts a postfix expression exp to its equivalent prefix form.
string postfix2prefix( const string exp );
//It evaluates an infix expression.
double evaluateInfix( const string exp );
//It evaluates a prefix expression.
double evaluatePrefix( const string exp );
//It evaluates a postfix expression.
double evaluatePostfix( const string exp );

int priority(string expression);
bool isOperator( string op);
double operations( string operand1, string operand2, string operation);

#endif //ALGEBRAIC_EXPRESSION_H
