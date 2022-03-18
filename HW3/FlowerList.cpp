/**
 * Author: Ayşe Kelleci
 * 21902532
 * CS201-3 HW3 
 * FlowerList class
 */
#include "FlowerList.h"
#include <iostream>
#include <string>
using namespace std;

//constructor
FlowerList::FlowerList()
{
    size = 0;
    head = NULL;
}

//copy constructor
FlowerList::FlowerList(const FlowerList& aList)
{
    if( aList.head == NULL)
    {
        head = NULL;
    }
    else
    {
        head = new FlowerNode;
        head->f = aList.head->f;

        FlowerNode* newPtr = head;
        for( FlowerNode *origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next)
        {
            newPtr->next = new FlowerNode;
            newPtr = newPtr->next;
            newPtr->f = origPtr->f;
        }
        newPtr->next = NULL;
    }
}

//destructor
FlowerList::~FlowerList()
{
    while( !isEmpty())
    {
        remove( head->f.getFlowerName());
    }
}

bool FlowerList::isEmpty() const
{
    return size == 0; //return true if size equals 0
}

int FlowerList::getLength() const
{
    return size;
}

bool FlowerList::retrieve(string flowerName, Flower& flower) const
{
    if( !findFlower(flowerName))
    {
        return false;
    }
    
    FlowerNode* cur = head;
    while( cur != NULL)
    {
        if( cur-> f.getFlowerName() ==flowerName)
        {
            flower = cur->f;
            return true;
        }
        cur = cur->next;
    }
    return true;

}

/** Add new flower in alphabetic order if it does not exist yet
 *  @return true if it is added succesfully
 */
bool FlowerList::add(string flowerName)
{
    flowerName = lowerLetters(flowerName);

    if( findFlower(flowerName))
    {
        cout << flowerName <<" cannot be added into the library because it already exists." << endl;
        return false;
    }

    FlowerNode* newptr = new FlowerNode;
    newptr->f = flowerName;

    //2. add it to head if size == 0
    if( size == 0)
    {
        newptr->next = head;
        head = newptr;
    }

    //
    // Change the alphabetic order later
    //
    else
    {
        FlowerNode* cur = head;
        if( cur->f.getFlowerName() > flowerName)
        {
            newptr->next = head;
            head = newptr;
        }
        else
        {
            while( cur->next != NULL  && cur->next->f.getFlowerName() < flowerName)
            {
                cur = cur-> next;
            }

            newptr->next = cur->next; 
            cur->next = newptr;
        }
    }
    cout << flowerName << " has been added into the library." << endl;
    size = getLength() +1 ; //increment the size of list
    return true;
}
    
/** remove feature from flower in alphabetic order if it exists 
 *  @return true if it is removed succesfully
 */    
bool FlowerList::remove(string flowerName)
{
    flowerName = lowerLetters(flowerName);

    if( !findFlower(flowerName))
    {
        return false;
    }

    FlowerNode* cur;
    if( head-> f.getFlowerName() == flowerName )
    {
        cur = head;
        head = head-> next;
    }

    else
    {
       FlowerNode* prev = head;
       while( prev->next->f.getFlowerName() != flowerName)
       {
           prev = prev->next;
       }
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur; //avoid memory leak
    cur = NULL;
    size = size -1; 
    return true;
}

/**
 * Check whether flower is exist in flower list by using its name 
 */   
bool FlowerList::findFlower( string flowerName) const
{
    flowerName = lowerLetters( flowerName);

    FlowerNode* cur = head;
    while( cur != NULL)
    {
        if( cur-> f.getFlowerName() ==flowerName)
        {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

/**
 * 
 */
void FlowerList::findFlowers( string feature) const
{
    feature = lowerLetters( feature);

    string flowersWithGivenFeature = feature + " flowers: " ;
    FlowerNode* cur = head;
    bool controller = false;
    while( cur != NULL)
    {
        if( cur-> f.find(feature))
        {
            flowersWithGivenFeature = flowersWithGivenFeature + cur->f.getFlowerName() + ", ";
            controller = true;
        }
        cur = cur->next;
    }

    if( !controller)
    {
        flowersWithGivenFeature = flowersWithGivenFeature + " there is no such flower";
    }
    cout << flowersWithGivenFeature << endl;
}


void FlowerList::listFlowers() const
{
    FlowerNode* cur = head;
    while( cur != NULL)
    {
        cout << cur->f.printFlower();
        cout << endl;
        cur = cur->next;
    }
}

void FlowerList::listFeatures( string name) const
{
    name = lowerLetters(name);

    FlowerNode* cur = head;
    while( cur != NULL)
    {
        if( cur-> f.getFlowerName() == name)
        {
            cout << cur->f.printFlower() <<endl;
            return;
        }
        cur = cur->next;
    }
    cout << name << " isn't found in the library" <<endl;
}


bool FlowerList::receiveFlower( string name, FlowerNode*& flower)
{
    name = lowerLetters( name);

    if( !findFlower(name))
    {
        return false;
    }
    
    FlowerNode* cur = head;
    while( cur != NULL)
    {
        if( cur->f.getFlowerName() == name)
        {
            flower = cur; //???????????
            return true;
        }
        cur = cur->next;
    }
    return true;
}

void FlowerList::addFeature(string name,string feature)
{
    feature = lowerLetters( feature);

    name = lowerLetters( name);

    FlowerNode* flower;
    if( receiveFlower( name, flower))
    {
        flower->f.add(feature);
    }

    else
    {
        cout << name << " cannot be found in the library" << endl;
    }

}


/*
* remove feature from the flower's feature by using flowerlist methods
*/
void FlowerList::removeFeature(string name,string feature)
{
    name = lowerLetters(name);

    feature = lowerLetters( feature);

    FlowerNode* flower;
    if( receiveFlower( name, flower))
    {
        if(flower->f.remove(feature))
        {
            cout << feature << " is removed from flower " << name << endl; 
        }
        
        else
            cout << feature << " doesn't exist in " << name << endl;
    }

    else
    {
        cout << name << "cannot be found in the library" << endl;
    }

}


string FlowerList::lowerLetters( string word ) const
{
    string newWord;
    for( unsigned int i = 0; i< word.length(); i++)
    {
        newWord += tolower(word[i]);
    }

    return newWord;
}
