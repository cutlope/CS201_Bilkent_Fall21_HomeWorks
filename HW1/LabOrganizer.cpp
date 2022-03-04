//Abdullah Riaz
//22001296

#include "LabOrganizer.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
LabOrganizer::LabOrganizer()
{
    cabinets = NULL;
    numCabinets = 0;
}

//Destructor
LabOrganizer::~LabOrganizer()
{
    if (cabinets != NULL)
    {
        delete[] cabinets;
    };
}

//Add a cabinet to the array of cabinets
void LabOrganizer::addCabinet(int id, int rows, int columns)
{
    if (rows < 1 || rows > 9 || columns < 1 || columns > 9)
    {
        cout << "Cannot Add Cabinet " << id << " due to invalid dimensions" << endl;
        return;
    }

    else if (numCabinets == 0)
    {
        numCabinets = 1;
        cabinets = new Cabinet[numCabinets];
        cabinets[0] = Cabinet(id, rows, columns);
    }

    else
    {
        if (findCabinet(id) != -1)
        {
            cout << "Cannot Add Cabinet ID: " << id << " as it already exists" << endl;
            return;
        }

        else
        {
            Cabinet *temp = new Cabinet[numCabinets + 1];
            for (int i = 0; i < numCabinets; i++)
            {
                temp[i] = cabinets[i];
            }
            temp[numCabinets] = Cabinet(id, rows, columns);
            delete[] cabinets;
            cabinets = temp;
            numCabinets++;
        }
    }
}

//Remove a cabinet from the array of cabinets by copying old array to new array except the cabinet that has to be deleted
void LabOrganizer::removeCabinet(int id)
{
    if (cabinets == NULL)
    {
        cout << "No cabinets to remove" << endl;
        return;
    }

    else
    {
        int index = findCabinet(id);
        if (index == -1)
        {
            cout << "Cabinet ID: " << id << " does not exist" << endl;
            return;
        }

        else
        {
            Cabinet *temp = new Cabinet[numCabinets - 1];
            for (int i = 0; i < index; i++)
            {
                temp[i] = cabinets[i];
            }
            for (int i = index; i < numCabinets - 1; i++)
            {
                temp[i] = cabinets[i + 1];
            }

            cabinets[index].getChemicals(false);
            delete[] cabinets;
            cabinets = temp;
            numCabinets--;
            cout << "Cabinet " << id << " has been removed" << endl;
        }
    }
}

//Print all cabinets in the array
void LabOrganizer::listCabinets()
{
    if (cabinets == NULL)
    {
        cout << "No cabinets to list" << endl;
        return;
    }

    else
    {
        for (int i = 0; i < numCabinets; i++)
        {
            cout << "ID : " << cabinets[i].getId() << ", Dim: " << cabinets[i].getRows() << "x" << cabinets[i].getColumns() << ", Number of empty slots: " << cabinets[i].getEmptySlots() << endl;
        }
    }
}

//list all chemicals in a cabinet
void LabOrganizer::cabinetContents(int id)
{

    int index = findCabinet(id);
    if (index == -1)
    {
        cout << "Cabinet " << id << " does not exist" << endl;
        return;
    }

    else
    {
        cabinets[index].printSlots();
    }
}

//Place a chemical in a cabinet
void LabOrganizer::placeChemical(int cabinetId, string location, string chemType, int chemID)
{
    if (cabinets == NULL)
    {
        cout << "No cabinets to list" << endl;
        return;
    }

    else
    {
        //Check if cabinet exists
        int index = findCabinet(cabinetId);
        if (index == -1)
        {
            cout << "Cabinet " << cabinetId << " does not exist" << endl;
            return;
        }

        //Check if chemicalID is unique
        for (int i = 0; i < numCabinets; i++)
        {
            if (cabinets[i].findChemical(chemID) != -1)
            {
                cout << "Chemical ID " << chemID << " already exists" << endl;
                return;
            }
        }

        //Check if location suitable for combustive chemical
        if (chemType == "combustive")
        {
            if (cabinets[index].canBePlaced(location) == true)
            {
                cabinets[index].addChemical(location, chemType, chemID);
            }
            else
            {
                cout << "Location " << location << " in cabinet " << cabinetId << " is not suitable for a combustive chemical" << endl;
                if (cabinets[index].alternateCabinets(location, chemType) == "")
                {
                    cout << "No alternate location found" << endl;
                    return;
                }
                else
                {
                    cout << "Nearest Possible locations for this chemical: " << cabinets[index].alternateCabinets(location, chemType) << endl;
                }
                return;
            }
        }

        //Adding non-combustive element
        else
        {

            cabinets[index].addChemical(location, chemType, chemID);
        }
    }
}

//Finding chemical given its ID
void LabOrganizer::findChemical(int id)
{
    if (cabinets == NULL)
    {
        cout << "No cabinets to list" << endl;
        return;
    }

    else
    {
        for (int i = 0; i < numCabinets; i++)
        {
            if (cabinets[i].findChemical(id) != -1)

            {
                cout << "Chemical " << id << " found in cabinet: " << cabinets[i].getId() << " at location: " << cabinets[i].getChemicalLocation(id) << endl;
                return;
            }
        }
        cout << "Chemical " << id << " not found in the system" << endl;
    }
}

//Remove a chemical from a cabinet
void LabOrganizer::removeChemical(int id)
{
    if (cabinets == NULL)
    {
        cout << "No cabinets to list" << endl;
        return;
    }

    else
    {
        for (int i = 0; i < numCabinets; i++)
        {
            if (cabinets[i].findChemical(id) != -1)
            {
                cabinets[i].removeChemical(id);
                return;
            }
        }
        cout << "Chemical " << id << " not found" << endl;
    }
}

//Find if cabinet exists in the system
int LabOrganizer::findCabinet(const int cid)
{
    if (cabinets == NULL)
    {
        return -1;
    }

    else
    {
        for (int i = 0; i < numCabinets; i++)
        {
            if (cabinets[i].getId() == cid)
            {
                return i;
            }
        }
        return -1;
    }
}
