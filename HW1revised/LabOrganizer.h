/** Ayse Kelleci 21902532
*   LabOrganizer.h
*/
#ifndef LABORGANIZER_H
#define LABORGANIZER_H
#include <iostream>
#include "Cabinet.h" // include definition of class Cabinet
using namespace std;

class LabOrganizer
{
private:
    Cabinet* cabinetArray;
    int arrSize;
public:
    LabOrganizer();
    ~LabOrganizer();
    void addCabinet(int id, int rows, int columns);
    void removeCabinet(int id);
    void listCabinets();
    void cabinetContents(int id);
    void placeChemical(int cabinetId, string location, string chemType, int chemID);
    void findChemical(int id);
    void removeChemical(int id);
    bool isCabinetExist( int id);
    
    // ...
    //you may define additional member functions and data members, if necessary
};

#endif // LABORGANIZER_H
