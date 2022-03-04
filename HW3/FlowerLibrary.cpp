//Abdullah Riaz
//22001296
//Section: 01

using namespace std;
#include "FlowerLibrary.h"
#include <iostream>

FlowerLibrary::FlowerLibrary()
{
    //Nothing needed here since no dynamic variables are used and there arent any other variables needed to be initialized
}

FlowerLibrary::~FlowerLibrary()
{
    //Nothing needed to be manually destructed since no dynamic variables are used. Primitive types are handled by the compiler.
}

void FlowerLibrary::addFlower(string name)
{
    if (flowers.add(toLower(name)))
        cout << toLower(name) << " has been added to the library" << endl;
}

void FlowerLibrary::removeFlower(string name)
{
    if (flowers.remove(toLower(name)))
    {
        cout << toLower(name) << " has been removed from the library" << endl;
    };
}

void FlowerLibrary::listFlowers() const
{
    flowers.print();
}

void FlowerLibrary::listFeatures(string flowerName) const
{
    //Warning message in case the flower is not found
    if (!(flowers.print(flowerName)))
    {
        cout << flowerName << " not found in library" << endl;
    };
}

void FlowerLibrary::addFeature(string name, string feature)
{
    if (flowers.addFeature(toLower(name), toLower(feature)))
    {
        cout << toLower(feature) << " has been added to " << toLower(name) << endl;
    }
}

void FlowerLibrary::removeFeature(string name, string feature)
{
    if (flowers.removeFeature(toLower(name), toLower(feature)))
    {
        cout << feature << " has been removed from " << name << endl;
    }
}

void FlowerLibrary::findFlowers(string feature) const
{
    flowers.findFeature(feature);
}

string FlowerLibrary::toLower(string str)
{
    for (int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
    return str;
}
