
#include "Input.h"

#include <iostream>
#include <limits>

using namespace std;

void INPUT::getInput() {
    cout << "Enter number of people at risk: ";
    cin >> number_of_people;

    cout << "Enter affected area location: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, affected_area_location);

    cout << "Enter wind speed (km/h): ";
    cin >> windspeed;

    cout << "Enter fire severity (1-10): ";
    cin >> severity;

    cout << "Enter distance from populated area (km): ";
    cin >> distance_from_popul_area;

    cout << "Enter number of animals affected: ";
    cin >> animals_affected;

    cout << "Enter distance to nearby water resource (km): ";
    cin >> nearby_water_resource;

    cout << "Enter fire intensity (Low/Medium/High): ";
    cin >> fire_intensity;
}

void INPUT::displayInput() {
    cout << "\n===== WILDFIRE DETAILS =====\n";
    cout << "People at risk: " << number_of_people << endl;
    cout << "Affected area: " << affected_area_location << endl;
    cout << "Wind speed: " << windspeed << " km/h" << endl;
    cout << "Fire severity: " << severity << endl;
    cout << "Distance from populated area: "
         << distance_from_popul_area << " km" << endl;
    cout << "Animals affected: " << animals_affected << endl;
    cout << "Distance to nearby water resource: "
         << nearby_water_resource << " km" << endl;
    cout << "Fire intensity: " << fire_intensity << endl;
}
