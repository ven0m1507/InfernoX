
#ifndef EMERGENCY_RESOURCE_H
#define EMERGENCY_RESOURCE_H

#include <string>
using namespace std;

class Emergency_res {
private:
    int resource_id;
    string resource_type;
    int location;
    bool available;
    int capacity;

public:
    Emergency_res(int id, string type, int locate, int cap);

    int getid() const;
    string getType() const;
    int getlocation();
    int getCapacity() const;
    bool isavaailable();

    void dispatch();
    void makeavailable();
    void display() const;
};

#endif
