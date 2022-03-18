/**
 * Author: Ayşe Kelleci
 * 21902532
 * CS201-3 HW3 
 * FlowerList class
 */
#include "FlowerLibrary.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//constructor
FlowerLibrary::FlowerLibrary()
{

}

//destructor
FlowerLibrary::~FlowerLibrary()
{

}

void FlowerLibrary::addFlower(string name)
{
    flowers.add(name);
}

void FlowerLibrary::removeFlower(string name)
{
    name = lowerLetters( name);
    if(flowers.remove(name))
    {
        cout << name << " has been removed from flower library" << endl; 
    }
        
    else
    {
        cout << name << " cannot be removed because it's not in the library." << endl;
    }
}

void FlowerLibrary::listFlowers() const
{
    flowers.listFlowers();
}

void FlowerLibrary::listFeatures(string name) const
{
    flowers.listFeatures(name);
}

void FlowerLibrary::addFeature(string name,string feature)
{
    flowers.addFeature( name, feature);
}
/*
* remove feature from the flower's feature by using flowerlist methods
*/
void FlowerLibrary::removeFeature(string name,string feature)
{
    flowers.removeFeature( name, feature);
}

void FlowerLibrary::findFlowers(string feature) const
{
    flowers.findFlowers( feature);
}


string FlowerLibrary::lowerLetters( string word ) const
{
    string newWord;
    for( unsigned int i = 0; i< word.length(); i++)
    {
        newWord += tolower(word[i]);
    }

    return newWord;
}