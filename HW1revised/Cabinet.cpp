/** Ayse Kelleci 21902532
*   Cabinet.cpp
*/
#include <iostream>
using namespace std;

#include "Cabinet.h" // include definition of class Cabinet
#include "Chemical.h" //include definition of class Chemical

//constructor
Cabinet::Cabinet( int id, int rows, int columns)
{
    theId = id;
    theColumns = columns;
    theRows = rows;

    table = new Chemical**[ theRows] ;
    
    for( int i = 0; i < theRows; i++)
    {
        table[i] = new Chemical*[ theColumns];
    }

    for( int i = 0; i < theRows; i++)
    {
        for( int j = 0; j < theColumns; j++)
        {
            table[i][j] = new Chemical();
        }
    } 
   
}

Cabinet::Cabinet() //default constructor
{
    theId = 0;
}

Cabinet::~Cabinet()
{
    theId = 0;
    theRows = 0;
    theColumns = 0;

}

/** print the cabinet id, row, columns and chemicals in the cabinet
*   also prints the table 
*/
void Cabinet::cabinetContents()
{
    //cabinet ıd and chemicals with IDs and locations
    cout << "ID: " << theId << ", " << theRows << "x" << theColumns << ", empty:" << numberOfEmptySlots() << " Chemicals: ";
    
    for( int i = 0; i < theRows; i++)
    {
        for( int j = 0; j < theColumns; j++)
        {
            if( (*table[i][j]).getChemID() != 0)
            {
                cout << char( i+ 65) << (j+1) << ": "<< (*table[i][j]).getChemID() << ", ";
            }
        }
    } 
    cout<< endl;

    //table of cabinet
    cout << "   ";
    for( int i= 0; i< theColumns; i++)
    {
        cout << i+1 << "  ";
    }
    cout << endl;

    for( int i = 0; i < theRows; i++)
    {
        cout << char( i+ 65) << "  ";
        for( int j = 0; j < theColumns; j++)
        {
            cout<< (*table[i][j]).getChemType().at(0) << "  ";
            
        }

        cout << endl;
    } 
}

void Cabinet:: listCabinet()
{
    cout<< " ID:" << theId << ",  Dimension" << theRows << "x" << theColumns << ", Empty slots:" <<numberOfEmptySlots();
}

/** adds new chemicals to the cabinet if it is convenient
*   then prints a message
*/
void  Cabinet::placeChemical( string location, string chemType, int chemID)
{
    int row = (int) (location.at(0)) -64; //convert char to int 

    int column = location.at(1) - 48; 

    // if location is invalid or full give warning message
    if( row <= 0 || row > getRow() || column <= 0  || column > getColumn() )
    {
        cout << "INVALID LOCATION ";
        cout << row << " X  " << column << endl;
    }

    else if( isChemicalExist(chemID)  )
    {
        //if chemical is already exist, do not place it
    }

    else if( (*table[row-1][ column-1]).getChemID() != 0) //null
    {
        cout<< "Chemical " << chemID << " cannot be placed. Since this slot " <<  location << " is not empty" << endl;
    }

    else if( chemType ==  "retardant")
    {
        delete table[row-1][column-1];
        table[row-1][column-1] = new Chemical( chemType, chemID);
        cout << chemType <<" Chemical with " << chemID << " ID, is placed to cabinet " 
                                << getID() << "  to location: " << location << endl;
    }
    else 
    {   
        if( checkLocation( row-1, column-1))
        { 
            delete table[row-1][column-1];
            table[row-1][column-1] = new Chemical( chemType, chemID);
            cout << chemType <<" Chemical with " << chemID << " ID, is placed to cabinet " 
                                << getID() << "  to location: " << location << endl;
        }

        else
        {
            cout << location << " is not appropriate place for" << chemID << " alternative places: " ;
            findAlternativeLocations( row-1, column-1);
        }
    }
}


string Cabinet::findChemicalLocation( int chemID)
{
    string s = "";
    for( int i = 0; i< theRows; i++)
    {
        for( int j = 0; j < theColumns; j++)
        {
            if( (*table[i][j]).getChemID() == chemID)
            {
                cout << char(i + 65)  << j+1 ;
                return s;
            }
        }
    }
    return "";
}

void Cabinet::removeChemical( int chemID)
{
    for( int i = 0; i< theRows; i++)
    {
        for( int j = 0; j < theColumns; j++)
        {
            if ((*table[i][j]).getChemID() == chemID) //null
            {
                delete table[i][j];
                table[i][j] = new Chemical(); //null
                cout << "Chemical " << chemID << " is deleted from " << theId << " successfully" << endl; 
                break;
            } 
        }
    }
}

/**
* @return the number of empty slots in Cabinet  
*/
int Cabinet::numberOfEmptySlots()
{
    int emptySlots = 0;
    for( int i = 0; i< theRows; i++)
    {
        for( int j = 0; j < theColumns; j++)
        {
            if ((*table[i][j]).getChemID() == 0) //null
            {
                emptySlots++;
            } 
        }
    }
    return emptySlots;
}

/** This method controls whether chemical with chemID in cabinet or not
 *  @param chemID is the ID of chemical searched in cabinet
*   @return true if chemical is found in cabinet 
*/
bool Cabinet:: isChemicalExist( int chemID)
{
    for( int i = 0; i< theRows; i++)
    {
        for( int j = 0; j < theColumns; j++)
        {
            if ((*table[i][j]).getChemID() == chemID) //null
            {
                return true;
            } 
        }
    }
    return false;
}

//return ID
int Cabinet:: getID()
{
    return theId;  //return the id of cabinet
}

int Cabinet:: getRow()
{
    return theRows + 1; //return row number ( I add 1 because index starts from 0)
}

int Cabinet:: getColumn()
{
    return theColumns + 1; //return column number
}

void Cabinet:: setID( int id)
{
    theId = id;  //set the id of cabinet
}

void Cabinet:: setRow( int row)
{
    theRows = row; //set the row number of cabinet
}

void Cabinet:: setColumn( int column)
{
    theColumns = column; //set the column number of cabinet
}

//it is used for deallocation
void Cabinet:: deleteCabinet()
{
    for( int i = 0; i< theRows; i++)
    {
        for( int j =0; j< theColumns; j++)
        {
            delete table[i][j];
        }
        delete[] table[i];
    }
    delete[] table;  
}

//delete all chemicals from table when cabinet was removed
void Cabinet:: deleteAllChemical()
{
    for( int i = 0; i < theRows; i++)
    {
        for( int j = 0; j < theColumns; j++)
        {
            if( (*table[i][j]).getChemID() != 0)
            {
                cout << "Chemical " << (*table[i][j]).getChemID() << " is deleted from cabinet " << theId << " successfully" << endl;
                //table[i][j] = new Chemical(); 
            }
        }
    } 
}

/*
* returns true if location is appropriate ( there must not be combustive chemical next to the combustive chemical)
*/
bool Cabinet::checkLocation( int row , int column)
{
    if( row+1 < getRow())
    {
        if(table[row+1][column]->getChemType() == "combustive")
        {
            return false;
        }
    }

    
    if( row + 1 < getRow() && column + 1 < getColumn() )
    {
        if(table[row+1][column+1]->getChemType() == "combustive")
        {
            return false;
        }
    } 

    if( row + 1 < getRow() && column - 1 >= 0 )
    {
        if(table[row+1][column-1]->getChemType() == "combustive")
        {
            return false;
        }
    }

    if( column - 1 >= 0 )
    {
        if(table[row][column-1]->getChemType() == "combustive")
        {
            return false;
        }
    }

    if( column + 1 < getColumn() )
    {
        if(table[row][column+1]->getChemType() == "combustive")
        {
            return false;
        }
    } 

    if( row -1 >= 0 )
    {
        if (table[row-1][column]->getChemType() == "combustive")
        {
            return false;
        }
    }

    if( row -1 >= 0  && column + 1 < getColumn())
    {
        if(table[row-1][column+1]->getChemType() == "combustive")
        {
            return false;
        }
    } 

    if( row -1 >= 0  && column - 1 >= 0 )
    {
        if(table[row-1][column-1]->getChemType() == "combustive")
        {
            return false;
        }
    }

    return true;
}

/*
* if place is not appropriate, print nearest alternative locations
*/
void Cabinet::findAlternativeLocations( int row , int column)
{
    int i = 1;
    bool isExistAlternativeLocation = false;
    while( i< 4 && !isExistAlternativeLocation)
    {
        //it look distances respectively first 1-slot distances 2-slot distances...
        for( int a = -i; a < i+1; a++ )
        {
            for( int b = -i; b< i+1; b++)
            {
                if(  row +a >= 0 && row + b < getRow() && column + b < getColumn()  && column + b >= 0 )
                {
                    if (checkLocation( row+a , column +b) && (*table[row+a][ column + b]).getChemID() == 0)
                    {
                        cout << char( row+a+ 65) << "."<< ( column +b+1) << ",  ";
                        isExistAlternativeLocation = true; 
                    }
                }
            }
        }
        i = i+1;
    }
    cout<< endl;
}
