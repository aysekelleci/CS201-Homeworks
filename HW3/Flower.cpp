/**
 * Author: Ayşe Kelleci
 * 21902532
 * CS201-3 HW3 
 * Flower class
 */

#include <iostream>
using namespace std;
#include "Flower.h"

//constructor
Flower::Flower( string flowerName)
{
    this->flowerName = flowerName;
    size = 0;
    head = NULL;
}

//default constructor
Flower:: Flower() :size(0), head(NULL)
{
    flowerName = "";
    size = 0;
    head = NULL;
}

//copy Constructor
Flower:: Flower(const Flower& aFlower)
{
    //TO DO
    if( aFlower.head == NULL)
    {
        head = NULL;
    }
    else
    {
        //copy first node
        head = new FeatureNode;
        head->feature = aFlower.head->feature;

        FeatureNode* newPtr = head;
        for( FeatureNode *origPtr = aFlower.head->next; origPtr != NULL; origPtr = origPtr->next)
        {
            newPtr->next = new FeatureNode;
            newPtr = newPtr->next;
            newPtr->feature = origPtr->feature;
        }
        newPtr->next = NULL;
    }
}

//destructor
Flower::~Flower()
{
     while (!isEmpty())
        remove(head ->feature); //?
}


bool Flower::isEmpty() const
{
    return size == 0; //return true if size equals 0
}

int Flower::getLength() const
{
    return size; //return the number of node in class
}

/** Add new feature to flower in alphabetic order if it does not exist yet
 *  @return true if it is added succesfully
 */
bool Flower::add( string feature)
{
    //1. check whether this feature exist in List or not
    if( find(feature))
    {
        cout<< feature <<" already exists in " << flowerName <<endl;
    }

    else
    {
        FeatureNode* newptr = new FeatureNode;
        newptr->feature = feature;

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
            FeatureNode* cur = head;
            if( cur->feature > feature)
            {
                newptr->next = head;
                head = newptr;
            }
            else
            {
                while( cur->next != NULL && cur->next->feature < feature )
                {
                    cur = cur-> next;
                }
                newptr->next = cur->next; 
                cur->next = newptr;
            }
        }
        cout << feature <<  " is added into " << flowerName << endl;
        size = getLength() +1 ; //increment the size of list
    }
    return true;

}

/** remove feature from flower in alphabetic order if it exists 
 *  @return true if it is removed succesfully
 */
bool Flower::remove(string feature)
{
    //check whether this feature exists or not
    if (!find(feature))
    {
        return false;
    }

    FeatureNode* cur;

    if( head->feature == feature) 
    {
        //if feature is at the head 
        cur = head;
        head = head->next;
    }

    else
    {
        FeatureNode* prev = head;
        while( prev->next->feature != feature )
        {
            prev = prev-> next;
        }

        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;
    size = size -1;  
    return true; 
}

string Flower::printFlower() const
{
    string printFlower = flowerName + " : ";
    FeatureNode* cur = head;
    for( int i = 0; i< getLength(); i++)
    {
        printFlower = printFlower  + cur->feature  + ",";
        cur = cur->next;
    }
    if( getLength() == 0)
    {
        printFlower = printFlower + "No feature";
    }
    return printFlower;
}

bool Flower::find( string feature)
{
    FeatureNode* cur = head;
    while( cur != NULL)
    {
        if( cur->feature == feature)
        {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

string Flower::getFlowerName()
{
    return flowerName;
}