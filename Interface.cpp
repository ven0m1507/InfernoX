#include<iostream>
using namespace std;
/* INPUTS:
Number of people
Affected Area location
Windspeed
Severity
Distance from nearby populated areas
Animals affected
Nearby water resource
Fire intensity */
class INPUT{
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
INPUT(int peoplenum,string area_affect,double wind,
float severity,double nearbyres,int animalaffect,
string intensity,float dist_popul){

}
};

