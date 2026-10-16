#include <iostream>
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
    void getInput() {
        cout << "Enter number of people at risk: ";
        cin >> number_of_people;

        cout << "Enter affected area location: ";
        cin.ignore();
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

    void displayInput() {
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
};

int main() {
    INPUT fire;

    fire.getInput();
    fire.displayInput();

    return 0;
}