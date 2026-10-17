
#ifndef INPUT_H
#define INPUT_H

#include <string>

class INPUT {
protected:
    int number_of_people{};
    std::string affected_area_location;
    double windspeed{};
    float severity{};
    double distance_from_popul_area{};
    int animals_affected{};
    double nearby_water_resource{};
    std::string fire_intensity;

public:
    void getInput();
    void displayInput();

    int getNumberOfPeople() const { return number_of_people; }
    std::string getAffectedAreaLocation() const { return affected_area_location; }
    double getWindspeed() const { return windspeed; }
    float getSeverity() const { return severity; }
    double getDistanceFromPopulatedArea() const { return distance_from_popul_area; }
    int getAnimalsAffected() const { return animals_affected; }
    double getNearbyWaterResource() const { return nearby_water_resource; }
    std::string getFireIntensity() const { return fire_intensity; }
};

#endif
