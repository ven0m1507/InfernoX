
#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <string>
using namespace std;

class Hospital {
private:
    int hospital_ID;
    string hospital_name;
    int location_ID;
    int general_bed_available;
    int total_general_bed;
    int total_ICU_bed;
    int ICU_available;

public:
    Hospital(int H_id, string H_name, int l_id, int i_bed, int g_bed);

    int getID() const;
    string getName() const;
    int getlocationid() const;
    int getTotalGeneralBed() const;
    int getAvailableGeneralBed() const;
    int getTotalICUBed() const;
    int getAvailableICU() const;

    void capacitycheckforgeneralbed();
    void capacitycheckforICU();
    void Admit_Patient(int ICU_patient, int general_patient);
    void Discharge_patient(int no_of_discharge_from_ICU,
                           int no_of_discharge_from_general_ward);
    void shift_from_ICU_to_General_ward(int no_of_patient_to_be_shifted);
    void display();
};

#endif
