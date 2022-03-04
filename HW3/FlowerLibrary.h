//Abdullah Riaz
//22001296
//Section: 01

#include "FlowerList.h"
class FlowerLibrary
{
public:
    FlowerLibrary();
    ~FlowerLibrary();
    void addFlower(string name);
    void removeFlower(string name);
    void listFlowers() const;
    void listFeatures(string name) const;
    void addFeature(string name, string feature);
    void removeFeature(string name, string feature);
    void findFlowers(string feature) const;
    string toLower(string str);

private:
    FlowerList flowers;
};
