
#ifndef INPUT_H
#define INPUT_H

#include <string>
using namespace std;

class INPUT {
protected:
    int number_of_people;
    string affected_area_location;
    double windspeed;
    float severity;
    double distance_from_popul_area;
    int animals_affected;
    double nearby_water_resource;
    string fire_intensity;

public:
    void getInput();
    void displayInput();
};

#endif

