//Abdullah Riaz
//22001296

using namespace std;
#include <string>

class Chemical

{
public:
    Chemical();

    //getters
    string getLocation();
    string getChemType();
    int getChemID();

    //setters
    void setLocation(string location);
    void setChemType(string chemType);
    void setChemID(int chemID);

private:
    string location;
    string chemType;
    int chemID;
};
