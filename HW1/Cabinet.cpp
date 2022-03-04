//Abdullah Riaz
//22001296

#include "Cabinet.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

//Default Constructor
Cabinet::Cabinet()
{
    id = 0;
    rows = 0;
    columns = 0;
    slots = NULL;
}

//Constructor
Cabinet::Cabinet(int id, int rows, int columns)
{
    this->id = id;
    this->rows = rows;
    this->columns = columns;

    slots = new Chemical *[rows];
    for (int i = 0; i < rows; i++)
    {
        slots[i] = new Chemical[columns];
    }
    cout << "Added a cabinet: ID " << id << " and dimensions " << rows << " to " << columns << endl;
}

//Copy Constructor
Cabinet::Cabinet(const Cabinet &orig)
{
    this->id = orig.id;
    this->rows = orig.rows;
    this->columns = orig.columns;

    slots = new Chemical *[rows];
    for (int i = 0; i < rows; i++)
    {
        slots[i] = new Chemical[columns];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            slots[i][j] = orig.slots[i][j];
        }
    }
}

//overload assignment operator
Cabinet &Cabinet::operator=(const Cabinet &rhs)
{
    if (this != &rhs)
    {
        this->id = rhs.id;
        this->rows = rhs.rows;
        this->columns = rhs.columns;

        slots = new Chemical *[rows];
        for (int i = 0; i < rows; i++)
        {
            slots[i] = new Chemical[columns];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                slots[i][j] = rhs.slots[i][j];
            }
        }
    }
    return *this;
}

//Destructor
Cabinet::~Cabinet()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] slots[i];
    }
    delete[] slots;
}

//Check if a combustive chemical can be placed in a slot
//by finding all combustive and checking if they are withing the immediate surrounding. i.e distance of 1
bool Cabinet::canBePlaced(string location)
{
    string origLocation = location;

    location[0] -= 'A';
    location[1] -= '1';

    if (slots[location[0]][location[1]].getChemID() != -1)
    {
        return false;
    }

    for (int i = 0; i < getRows(); i++)
    {
        for (int j = 0; j < getColumns(); j++)
        {
            if (slots[i][j].getChemType() == "combustive")
            {
                //checking rows distance from combustive to this location
                if ((location[0] - i) > -2 && (location[0] - i) < 2)
                {
                    //checking columns distance from combustive to this location
                    if ((location[1] - j) > -2 && (location[1] - j) < 2)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

//Overload canBePlaced function that takes index locations rather than location string
bool Cabinet::canBePlaced(int a, int b)
{
    if (slots[a][b].getChemID() != -1)
    {
        return false;
    }

    for (int i = 0; i < getRows(); i++)
    {
        for (int j = 0; j < getColumns(); j++)
        {
            if (slots[i][j].getChemType() == "combustive")
            {
                //checking x axis distance from combustive to this location
                if ((a - i) > -2 && (a - i) < 2)
                {
                    if ((b - j) > -2 && (b - j) < 2)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

//Finds alternate cabinets that chemical can be placed in
string Cabinet::alternateCabinets(string location, string chemType)
{
    int distance = 0;
    string origLocation = location;
    string alternates = "";

    location[0] -= 'A';
    location[1] -= '1';

    while (alternates == "" && distance < rows)
    {
        for (int i = 0; i < getRows(); i++)
        {
            for (int j = 0; j < getColumns(); j++)
            {
                if (slots[i][j].getChemType() == "+")
                {
                    if ((location[0] - i) > (-2 - distance) && (location[0] - i) < (2 + distance))
                    {
                        if ((location[1] - j) > (-2 - distance) && (location[1] - j) < (2 + distance))
                        {
                            if (chemType == "combustive")
                            {
                                if (canBePlaced(i, j))
                                {
                                    alternates += locationConverter(i, j) + " ";
                                }
                            }

                            else
                            {
                                alternates += locationConverter(i, j) + " ";
                            }
                        }
                    }
                }
            }
        }
        distance++;
    }

    return alternates;
}

//Coverters from index to location string
string Cabinet::locationConverter(int i, int j)
{
    string location = "";
    location += i + 'A';
    location += j + '1';
    return location;
}

//getters

int Cabinet::getId() const
{
    return id;
}

int Cabinet::getRows() const
{
    return rows;
}

int Cabinet::getColumns() const
{
    return columns;
}

//Returns chemicals in a cabinet with an optional boolean to return the chemicals with their location
void Cabinet::getChemicals(bool withLocation)
{
    string chemicals = "";
    int chemicalCount = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (slots[i][j].getChemID() != -1)
            {
                chemicalCount++;
                if (!withLocation)
                {
                    cout << "Chemical " << slots[i][j].getChemID() << " has been removed from cabinet " << id << endl;
                }

                else
                {
                    cout << slots[i][j].getLocation() << ": " << slots[i][j].getChemID() << " ";
                }
            }
        }
    }
    if (chemicalCount == 0)
    {
        cout << "No chemicals in cabinet " << id << endl;
        return;
    }
}

int Cabinet::getEmptySlots()
{
    int emptySlots = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (slots[i][j].getChemID() == -1)
            {
                emptySlots++;
            }
        }
    }
    return emptySlots;
}

void Cabinet::printSlots()
{
    cout << "ID: " << id << ", dim: " << getRows() << "x" << getColumns() << ", empty: " << getEmptySlots() << ", Chemicals: ";
    getChemicals(true);
    cout << endl;
    printf("  ");
    for (int i = 0; i < columns; i++)
    {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < columns; j++)
        {
            printf("%c ", slots[i][j].getChemType()[0]);
        }
        printf("\n");
    }
}

int Cabinet::findChemical(int id)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (slots[i][j].getChemID() == id)
            {
                return i;
            }
        }
    }
    return -1;
}

string Cabinet::getChemicalLocation(int id)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (slots[i][j].getChemID() == id)
            {
                return slots[i][j].getLocation();
            }
        }
    }
}

//Setters

void Cabinet::setId(int newid)
{
    newid = id;
}

void Cabinet::setRows(int newrows)
{
    newrows = rows;
}

void Cabinet::setColumns(int newcolumns)
{
    newcolumns = columns;
}

void Cabinet::addChemical(string location, string chemType, int chemID)
{
    string notModifiedLocation = location;
    location[0] -= 'A';
    location[1] -= '1';

    //Checking if location is valid
    if (location[0] > rows || location[1] > columns)
    {
        cout << "Invalid location" << endl;
        return;
    }

    //Checking if location is empty and recommend alternate if it is
    if (slots[location[0]][location[1]].getChemID() != -1)
    {
        cout << "Location " << notModifiedLocation << " in cabinet " << id << " is already occupied. ";
        cout << "Nearest Possible locations for this chemical: " << alternateCabinets(notModifiedLocation, chemType) << endl;

        return;
    }

    //Adding Chemical
    slots[location[0]][location[1]].setLocation(notModifiedLocation);
    slots[location[0]][location[1]].setChemType(chemType);
    slots[location[0]][location[1]].setChemID(chemID);

    cout << chemType << " chemical with ID " << chemID << " has been placed at location " << notModifiedLocation << " in cabinet " << this->id << endl;
}

//Removes chemical from cabinet
void Cabinet::removeChemical(int chemID)
{
    string location = getChemicalLocation(chemID);
    location[0] -= 'A';
    location[1] -= '1';

    if (location[0] > rows || location[1] > columns)
    {
        cout << "Invalid location" << endl;
        return;
    }

    if (slots[location[0]][location[1]].getChemID() == -1)
    {
        cout << "Slot is already empty" << endl;
        return;
    }

    slots[location[0]][location[1]].setChemID(-1);
    slots[location[0]][location[1]].setChemType("");
    slots[location[0]][location[1]].setLocation("");

    cout << "Chemical " << chemID << " removed from cabinet " << id << endl;
}
