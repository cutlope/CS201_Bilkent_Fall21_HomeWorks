#include "Chemical.h"
#include <iostream>
#include <string>
using namespace std;

Chemical::Chemical()
{
    location = "";
    chemType = "+";
    chemID = -1;
}

string Chemical::getLocation()
{
    return location;
}

string Chemical::getChemType()
{
    return chemType;
}

int Chemical::getChemID()
{
    return chemID;
}

void Chemical::setLocation(string location)
{
    this->location = location;
}

void Chemical::setChemType(string chemType)
{
    this->chemType = chemType;
}

void Chemical::setChemID(int chemID)
{
    this->chemID = chemID;
}
