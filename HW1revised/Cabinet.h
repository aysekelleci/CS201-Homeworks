/** Ayse Kelleci 21902532
*   Cabinet.h
*/
#ifndef CABINET_H
#define CABINET_H

#include "Chemical.h" //include definition of class Chemical

class Cabinet
{
private:
    int theId, theColumns, theRows;
    Chemical*** table;
    

public:
    Cabinet( int id, int rows, int columns);
    Cabinet();
    ~Cabinet();
    void listCabinet();
    void cabinetContents();
    void placeChemical( string location, string chemType, int chemID);
    void removeChemical( int chemID);
    void deleteCabinet();
    int numberOfEmptySlots();
    string findChemicalLocation( int chemID);
    int getID();
    int getRow();
    int getColumn();
    void setID( int id);
    void setRow( int rows);
    void setColumn( int columns);
    void deleteAllChemical();
    bool isChemicalExist( int chemID);
    bool checkLocation( int row , int column);
    void findAlternativeLocations( int row, int column);
};

#endif // CABINET_H