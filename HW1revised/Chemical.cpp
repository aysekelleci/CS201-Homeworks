//Ayse Kelleci 21902532
#include <iostream>
using namespace std;

#include "Chemical.h" // include definition of class Chemical

//constructor
Chemical:: Chemical( string chemType, int chemID)
{
    theChemType = chemType;
    theChemID = chemID;
}

Chemical:: Chemical()
{
    theChemType = "+";
    theChemID = 0;
}

//destructor
Chemical:: ~Chemical()
{
    theChemID = 0;
    theChemType = "+";
}

int Chemical:: getChemID() 
{
    return theChemID; //returns Chemical ID
}

string Chemical::getChemType()
{
    return theChemType; //return Chemical type
}


