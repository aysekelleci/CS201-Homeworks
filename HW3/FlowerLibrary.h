//Ayse Kelleci 21902532
#ifndef FLOWERLIBRARY_H
#define FLOWERLIBRARY_H
#include "FlowerList.h"

class FlowerLibrary{
public:
FlowerLibrary();
~FlowerLibrary();
void addFlower(string name);
void removeFlower(string name);
void listFlowers() const;
void listFeatures(string name) const;
void addFeature(string name,string feature);
void removeFeature(string name, string feature);
void findFlowers(string feature) const;
string lowerLetters( string word ) const;

private:
FlowerList flowers;
// ...
//you may define additional member functions and data members, if necessary
};

#endif //FLOWERLIBRARY_H