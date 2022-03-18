//Ayse Kelleci 21902532
#ifndef FLOWER_H
#define FLOWER_H
#include <iostream>
using namespace std;

class Flower
{
    public:
    Flower();
    Flower(string flowerName);
    Flower(const Flower& aFlower);
    ~Flower();
    bool isEmpty() const;
    int getLength() const ;
    bool add(string feature);
    bool remove(string feature);
    string printFlower() const; 
    bool find( string feature);
    string getFlowerName();

    private:
    struct FeatureNode{
        string feature;
        FeatureNode* next;
    };
    int size;
    string flowerName;
    FeatureNode *head; //the features are stored in a sorted singly linear linked list
    // ...
    //you may define additional member functions and data members, if necessary
};
#endif //FLOWER_H
