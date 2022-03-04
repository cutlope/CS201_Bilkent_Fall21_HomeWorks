//Abdullah Riaz
//22001296

#include <iostream>
#include "Cabinet.h"

using namespace std;

class LabOrganizer
{
public:
    LabOrganizer();
    ~LabOrganizer();
    void addCabinet(int id, int rows, int columns);
    void removeCabinet(int id);
    void listCabinets();
    void cabinetContents(int id);
    void placeChemical(int cabinetId, string location, string chemType, int chemID);
    void findChemical(int id);
    void removeChemical(int id);

    //Additonal Functions
    int findCabinet(int id);        //finds the index of the cabinet with the given id

private:
    int numCabinets;
    Cabinet *cabinets;
};
