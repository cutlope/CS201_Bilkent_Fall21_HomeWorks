//Abdullah Riaz
//22001296
//Section: 01

#include "Flower.h"

class FlowerList
{
public:
    FlowerList();
    FlowerList(const FlowerList &aList);
    ~FlowerList();
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(string flowerName, Flower &flower) const;
    bool add(string flowerName);
    bool addFeature(string flowerName, string feature);
    bool remove(string flowerName);
    bool removeFeature(string flowerName, string feature);
    void findFeature(string feature) const;
    void print() const;
    bool print(string flowerName) const;

private:
    struct FlowerNode
    {
        Flower f;
        FlowerNode *next;
    };
    int size;
    FlowerNode *head; //the flowers are stored in a sorted singly linear linked list
    // ...
    //you may define additional member functions and data members, if necessary
};
