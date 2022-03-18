/** Ayse Kelleci 21902532
*   Chemical header file
*/
#ifndef CHEMICAL_H
#define CHEMICAL_H
#include <iostream>
using namespace std;

class Chemical
{
    private:
    string theChemType;
    int theChemID;

    public:
    Chemical( string chemType, int chemID);
    Chemical();
    ~Chemical();
    int getChemID();
    string getChemType();
    
};

#endif //CHEMICAL_H