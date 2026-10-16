
#include "Emergencyresource.h"

#include <iostream>

using namespace std;

Emergency_res::Emergency_res(int id, string type, int locate, int cap)
    : resource_id(id),
      resource_type(type),
      location(locate),
      available(true),
      capacity(cap) {}

int Emergency_res::getid() const {
    return resource_id;
}

string Emergency_res::getType() const {
    return resource_type;
}

int Emergency_res::getlocation() {
    return location;
}

int Emergency_res::getCapacity() const {
    return capacity;
}

bool Emergency_res::isavaailable() {
    return available;
}

void Emergency_res::dispatch() {
    if (available) {
        available = false;
        cout << resource_type << " #" << resource_id
     << " has been dispatched and is now busy." << endl;
    } else {
        cout << resource_type << " #" << resource_id
             << " is currently busy.";
    }
}

void Emergency_res::makeavailable() {
    available = true;
    cout << resource_type << " #" << resource_id
         << " is now available." << endl;
    cout << "-----------------------------------------------------------"
         << endl;
}

void Emergency_res::display() const {
    cout << "Resource ID-> " << resource_id << endl;
    cout << "Resource Type-> " << resource_type << endl;
    cout << "Location ID-> " << location << endl;
    cout << "Capacity-> " << capacity << endl;
    cout << "Status " << (available ? "Available" : "Dispatched") << endl;
}
