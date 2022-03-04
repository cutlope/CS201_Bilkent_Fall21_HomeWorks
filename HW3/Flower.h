//Abdullah Riaz
//22001296
//Section: 01

using namespace std;
#include <string>

class Flower
{
public:
    Flower();
    Flower(string flowerName);
    Flower(const Flower &aFlower);
    ~Flower();
    bool isEmpty() const;
    int getLength() const;
    bool add(string feature);
    bool remove(string feature);
    string printFlower() const;
    void setName(string flowerName);
    string getName() const;
    bool doesFeatureExist(string feature) const;
    void sort();

private:
    struct FeatureNode
    {
        string feature;
        FeatureNode *next;
    };

    int size;
    string flowerName;
    FeatureNode *head; //the features are stored in a sorted singly linear linked list
};
