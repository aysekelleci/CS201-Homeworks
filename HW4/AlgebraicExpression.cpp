/**
 * Author: Ayşe Kelleci
 * 21902532
 * 4 January 2022 
 * VERSİON:1.0
 * Array based Stack implementation 
 */

#include <iostream>
#include <string.h>
#include <string>
using namespace std;
#include "AlgebraicExpression.h"
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

int priority(string exp) {

    if( exp == "/" || exp == "*")
        return 2;
    else if( exp == "+" || exp == "-")
        return 1;
    else
        return 0;
}


bool isOperator(string op)
{
    if( op == "+" || op == "-" || op == "/" || op == "*")
    {
        return true;
    }
    return false;
}

double operations( string operand1, string operand2, string operation)
{
    double value1 = strtod( operand1.c_str(), NULL);
    double value2 = strtod( operand2.c_str(), NULL);

    if( operation == "*")
    {
        return value1 * value2;
    }

    else if( operation == "/")
    {
        return value1 / value2;
    }

    else if( operation == "+")
    {
        return value1 + value2;
    }

    else 
    {
        return value1 - value2;
    }
}

string postfix2prefix( const string exp )
{
    Stack s;
    int length = exp.size();
    string temp;
    for( int i = 0; i < length; i++ )
    {
        if( exp[i] != ' ' && i < length-1)
        {
            temp = temp + exp[i];
            //cout << temp << endl;
            
        }

        else
        {
            if( i == length -1)
            {
                temp = temp + exp[i];
            }

            if( isOperator( temp))
            {
                string exp1;
                s.pop( exp1);
                string exp2;
                s.pop(exp2);

                string tmpResult =  temp +' ' +  exp2 + ' '+ exp1;
                s.push( tmpResult);
            }

            else
            {
                s.push( temp);
            }

            temp = "";
        }

    }
    string result;

    while( !s.isEmpty())
    {
        result = result + s.gettingTop();
        s.pop();
    }
    return result;
}

string prefix2postfix( const string exp)
{
    Stack s;
    int length = exp.size();
    string temp;
    for( int i = length - 1 ; i >= 0; i-- )
    {
        if( exp[i] != ' ' && i > 0)
        {
            temp = exp[i] + temp;
            //cout << temp << endl;  
        }

        else
        {
            if( i == 0)
            {
                temp = exp[i] + temp;
            }

            if( isOperator( temp) )
            {
                string exp1;
                s.pop( exp1);
                string exp2;
                s.pop(exp2);

                string tmpResult =  exp1 +' ' +  exp2 + ' '+ temp;
                s.push( tmpResult);
            }

            else
            {
                s.push( temp);
            }

            temp = "";
        }

    }
    string result;

    while( !s.isEmpty())
    {
        result = result + s.gettingTop();
        s.pop();
    }
    return result;
}

//convert prefix to infix
string prefix2infix( const string exp )
{
    Stack s;
    int length = exp.size();
    string temp;
    for( int i = length-1; i>= 0; i--)
    {
        if( exp[i] != ' ' && i > 0)
        {
            temp = exp[i] + temp;
        }

        else
        {
            if( i == 0)
            {
                temp = exp[i] + temp;
            }

            if( isOperator( temp))
            {
                string exp1;
                s.pop( exp1);
                string exp2;
                s.pop(exp2);
                
                string tempResult = "( " + exp1 + ' ' + temp + ' ' + exp2 + " )";
                s.push( tempResult);
            }
            else
            {
                s.push( temp);
            }
            temp = "";
        }
    } 
    string result;

    while( !s.isEmpty())
    {
        result = result + s.gettingTop();
        s.pop();
    }
    return result;
}

//conver infix to postfix
string infix2postfix( const string exp )
{
    Stack s;
    int length = exp.size();
    string temp;
    string result;
    for( int i = 0; i < length; i++ )
    {
        if( exp[i] != ' ' && i < length-1)
        {
            temp = temp + exp[i];
            //cout << temp << endl;  
        }

        else
        {
            if( i == length -1)
            {
                temp = temp + exp[i];
            }

            if( isOperator( temp))
            {
                while(!s.isEmpty() && priority( temp) <= priority(s.gettingTop()))
                {
                    result += ' ' + s.gettingTop();
                    s.pop(); 
                }
                s.push(temp);
            }

            else if( temp == "(")
            {
                s.push( temp);
            }

            else if( temp == ")") 
            {
                while(s.gettingTop() != "(" &&  !s.isEmpty())
                {
                    result += ' ' + s.gettingTop();
                    s.pop();
                }

                s.pop();
                
            }

            else //operand
            {
                result = result + ' ' + temp;
            }

            temp = "";
        }

    }

    while( !s.isEmpty())
    {
        result = result+ ' ' + s.gettingTop();
        s.pop();
    }
    if(result[0] == ' ')
    {
        result.erase(0,1);
    }
    return result;
}

//convert infix to prefix
string infix2prefix( const string exp)
{
    string postfix = infix2postfix( exp);

    string prefix = postfix2prefix( postfix);

    return prefix;
}

//convert postfix to infix
string postfix2infix( const string exp)
{
    string prefix = postfix2prefix( exp);
    string infix  = prefix2infix( prefix);

    return infix;
}

//evaluate the result of profix expression
double evaluatePostfix( const string exp )
{
    Stack s;
    int length = exp.size();
    string temp;
    for( int i= 0; i< length; i++)
    {
        if( exp[i] != ' ' && i < length-1)
        {
            temp = temp + exp[i]; 
  
        }

        else
        {
            if( i == length -1)
            {
                temp = temp + exp[i];
            }

            if( isOperator( temp ))
            {
                string exp1;
                string exp2;
                s.pop( exp1);
                s.pop( exp2);
                double tempResult = operations( exp2, exp1, temp);
                string tempStr;
                /*char c[5];
                printf( c, "%d", tempResult);
                tempStr = c;*/
                std::ostringstream sstream;
                sstream << tempResult;
                std::string nom = sstream.str();
                s.push( nom);
            }

            else
            {
                s.push(temp);
            }
            temp = "";
        }
    }
    string result = s.gettingTop();
    return strtod( result.c_str(), NULL);
}

//evaluate the result of prefix expression
double evaluatePrefix( const string exp)
{
    string postfix = prefix2postfix( exp);
    return evaluatePostfix( postfix);
}

//evaluate the result of infix expression
double evaluateInfix( const string exp)
{
    string postfix = infix2postfix( exp);
    return evaluatePostfix( postfix);
}

