
#include "Hospital.h"

using namespace std;

Hospital::Hospital(int H_id, string H_name, int l_id, int i_bed, int g_bed)
    : hospital_ID(H_id),
      hospital_name(H_name),
      location_ID(l_id),
      general_bed_available(g_bed),
      total_general_bed(g_bed),
      total_ICU_bed(i_bed),
      ICU_available(i_bed) {}

int Hospital::getID() const { return hospital_ID; }

string Hospital::getName() const { return hospital_name; }

int Hospital::getlocationid() const { return location_ID; }

int Hospital::getTotalGeneralBed() const { return total_general_bed; }

int Hospital::getAvailableGeneralBed() const { return general_bed_available; }

int Hospital::getTotalICUBed() const { return total_ICU_bed; }

int Hospital::getAvailableICU() const { return ICU_available; }

void Hospital::capacitycheckforgeneralbed() {
    if (general_bed_available > 0 && general_bed_available <= total_general_bed) {
        cout << "General bed available = " << general_bed_available << endl;
    } else {
        cout << "General bed not available" << endl;
    }
}

void Hospital::capacitycheckforICU() {
    if (ICU_available > 0 && ICU_available <= total_ICU_bed) {
        cout << "Available ICU bed = " << ICU_available << endl;
    } else {
        cout << "ICU bed not available" << endl;
    }
}

void Hospital::Admit_Patient(int ICU_patient, int general_patient) {
    if (ICU_patient > 0 && ICU_patient <= ICU_available) {
        ICU_available -= ICU_patient;
        cout << "No. of ICU patient admitted = " << ICU_patient << endl;
    } else {
        cout << "ICU bed not available" << endl;
    }

    if (general_patient > 0 && general_patient <= general_bed_available) {
        general_bed_available -= general_patient;
        cout << "No. of General patient admitted = " << general_patient << endl;
    } else {
        cout << "General bed not available" << endl;
    }
}

void Hospital::Discharge_patient(
    int no_of_discharge_from_ICU,
    int no_of_discharge_from_general_ward) {
    general_bed_available += no_of_discharge_from_general_ward;
    ICU_available += no_of_discharge_from_ICU;
}

void Hospital::shift_from_ICU_to_General_ward(int no_of_patient_to_be_shifted) {
    if (no_of_patient_to_be_shifted > 0 &&
        no_of_patient_to_be_shifted <= general_bed_available) {
        ICU_available += no_of_patient_to_be_shifted;
        general_bed_available -= no_of_patient_to_be_shifted;
    } else {
        cout << "Patient can't be shifted as general bed available " << endl;
    }
}

void Hospital::display() {
    cout << "Hospital Name : " << hospital_name << endl;
    cout << "Hospital ID : " << hospital_ID << endl;
    cout << "Location ID : " << location_ID << endl;
    cout << "No. of General Bed Available : " << general_bed_available << endl;
    cout << "No. of ICU Bed Availabel : " << ICU_available << endl;
}
