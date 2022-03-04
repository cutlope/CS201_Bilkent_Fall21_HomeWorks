//Abdullah Riaz
//22001296

using namespace std;
#include <string>
#include "Chemical.h"

class Cabinet
{
public:
    Cabinet();                              // default constructor
    Cabinet(int id, int rows, int columns); // constructor
    Cabinet(const Cabinet &);               // copy constructor
    ~Cabinet();                             // destructor
    Cabinet &operator=(const Cabinet &);    // assignment operator

    //getters
    int getId() const;
    int getRows() const;
    int getColumns() const;
    int getEmptySlots();                                        // returns the number of empty slots in the cabinet
    void getChemicals(bool withLocation);                       //Returns chemicals in a cabinet with an optional boolean to return the chemicals with their location
    void printSlots();                                          //prints the chemicals in the cabinet
    int findChemical(int id);                                   //returns the location of the chemical
    string getChemicalLocation(int id);                         // returns the location of the chemical with the given id
    string alternateCabinets(string location, string chemType); //returns the location of the alternate cabinet for the chemical
    string locationConverter(int i, int j);                     //converts the location index to a string
    bool canBePlaced(string location);                          // returns true if the location is suitable for combustive chemical
    bool canBePlaced(int a, int b);                             // overloaded function

    //setters
    void setId(int id);
    void setRows(int rows);
    void setColumns(int columns);
    void addChemical(string location, string chemType, int chemID);
    void removeChemical(int chemID);

private:
    int id;
    int rows;
    int columns;
    Chemical **slots;
};
