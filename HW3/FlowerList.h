//Ayse Kelleci 21902532
#ifndef FLOWERLIST_H
#define FLOWERLIST_H
#include "Flower.h"
#include <iostream>
using namespace std;

class FlowerList{
    public:
    FlowerList();
    FlowerList(const FlowerList& aList);
    ~FlowerList();
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(string flowerName, Flower& flower) const;
    bool add(string flowerName);
    bool remove(string flowerName);
    bool findFlower( string flowerName) const;
    void findFlowers( string features) const;
    void listFlowers() const;
    void listFeatures( string name) const;
    void addFeature(string name,string feature);
    void removeFeature(string name,string feature);
    string lowerLetters( string word ) const;
    private:
    struct FlowerNode{
    Flower f;
    FlowerNode* next;
    };
    int size;
    FlowerNode* head; //the flowers are stored in a sorted singly linear linked list
    // ...
    //you may define additional member functions and data members, if necessary

    bool receiveFlower( string name, FlowerNode*& flower);
};
#endif //FLOWERLIST_H