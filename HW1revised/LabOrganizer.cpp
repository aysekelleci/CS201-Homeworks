/** Ayse Kelleci 21902532
*   LabOrganizer.cpp
*/
#include <iostream>
using namespace std;

#include "LabOrganizer.h" // include definition of class LabOrganizer
#include "Cabinet.h"

//constructor
LabOrganizer:: LabOrganizer(  ) {
    arrSize = 0;
    //cabinetArray;
}

//destructor
LabOrganizer:: ~LabOrganizer(  ) {

    for( int i = 0; i< arrSize; i++)
    {
       (cabinetArray[i]).deleteCabinet();
    }
    delete[] cabinetArray;
}

/**
 *  add cabinet with given ID to cabinetArray
 */
void LabOrganizer::addCabinet(int id, int rows, int columns)
{
    
    if( columns > 9 || rows > 9)
    {
        cout << "Invalid rows-columns input" <<endl;
        return;
    }


    else if( isCabinetExist(id)) //check whether ID is unique or not
    {
        //if id is not unique, print error message and exit this method
        cout<< "Cabinet id " << id << " is already exist" << endl;
        return;
    }

    // add cabinet to the  dynamic cabinet array
    else
    {
        if( arrSize == 0)
        {
            cabinetArray = new Cabinet[1];
            cabinetArray[0] = Cabinet( id, rows, columns);
            arrSize = arrSize+1;
            cout << "Cabinet " << id << "  " << rows << "x" << columns << " added successfully" << endl; 
        }
        
        else
        {
            Cabinet* newArray = new Cabinet[arrSize+1];
            for( int i = 0; i< arrSize; i++)
            {
                newArray[i] = cabinetArray[i];
            }

            newArray[ arrSize ] = Cabinet( id, rows, columns);
            
            delete[] cabinetArray;
            cabinetArray = newArray;
            arrSize = arrSize + 1;
            cout << "Cabinet " << id << "  " << rows << "x" << columns << " added successfully" << endl; 
        }
    }
}

/**
 *  remove cabinet with given ID from cabinetArray
 */
void LabOrganizer::removeCabinet( int id)
{

    if( !isCabinetExist( id))
    {
        cout << "The cabinet " << id << "cannot found in system" <<endl ;
    }

    else
    {
        Cabinet* tempArray = new Cabinet[ arrSize -1];
        int j = 0;
        for( int i = 0; i< arrSize; i++)
        {
            if( (cabinetArray[i]).getID() != id)
            {
                tempArray[j] = cabinetArray[i];
                j++;
            }
            else
            {
                cabinetArray[i].deleteAllChemical();
                (cabinetArray[i]).deleteCabinet();
            }

        }
        delete[] cabinetArray;

        cabinetArray = tempArray; 
        arrSize = arrSize -1; 
        cout << "Cabinet " << id << " was deleted successfully" << endl;
    }
    
}

void LabOrganizer:: listCabinets ()
{
    for( int i = 0; i< arrSize; i++)
    {
        (cabinetArray[i]).listCabinet(); // lists all cabinet in cabinet array
        cout<< endl;
    }
}

void LabOrganizer:: cabinetContents( int id)
{
    for( int i = 0; i< arrSize; i++)
    {
        if( (cabinetArray[i]).getID() == id )
        { 
            (cabinetArray[i]).cabinetContents(); //prints all cabinet contents in cabinet Array
            break;
        }
    }
}

/**
 *  place chemical with given ID to the cabinet in given location
 */
void LabOrganizer:: placeChemical(int id, string location, string chemType, int chemID)
{

    for( int i = 0; i< arrSize; i++)
    {
        if( cabinetArray[i].isChemicalExist(chemID))
        {
            cout <<  "This chemical is already exist" << endl ;
            return;
        }
    }

    if( !isCabinetExist(id))
    {
        cout<< "The cabinet ID cannot be found" << endl;
    }
    else
    {
        for( int i = 0; i< arrSize; i++)
        {
            if( (cabinetArray[i]).getID() == id )
            {
                (cabinetArray[i]).placeChemical( location, chemType, chemID);
            }
        }
    }
}

/**
 *  find chemical with given ID from cabinetArray and print its location if it is exist
 */
void LabOrganizer:: findChemical(int id )
{
    bool controller = false;
    for( int i = 0; i< arrSize; i++)
    {
        if ( (cabinetArray[i]).isChemicalExist( id))
        {
            cout<< id << ". Chemical is found in" <<  (cabinetArray[i]).getID() << ".  Cabinet location: ";
            cout << cabinetArray[i].findChemicalLocation( id) << endl;
            controller = true;
        }
    }
    if( !controller )
    {
        cout << "this chemical cannot be found" << endl;
    }

}

/**
 *  remove chemical with given ID from cabinetArray if it is exist
 */
void  LabOrganizer::removeChemical(int id)
{
    for( int i = 0; i< arrSize; i++)
    {
        if ( (cabinetArray[i]).isChemicalExist( id))
        {
            (cabinetArray[i]).removeChemical(id);
            return;
        }
    }
    cout << "This chemical " << id << " cannot be found in the system!" << endl;
}

/** Checks whether cabinet with given Id is exist or not
 *  @return true if exist, else returns false
 */
bool LabOrganizer:: isCabinetExist( int id)
{
    for( int i = 0; i< arrSize; i++)
    {
        if( (cabinetArray[i]).getID() == id )
        {
            return true;
        }
    }
    return false;
}

