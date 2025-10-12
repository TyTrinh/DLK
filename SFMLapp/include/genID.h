#pragma once
#include <string>
using namespace std;
class genID{
    private:
        static int doctorCount;
        static int patientCount;
    public:
        genID(const string& type);
        std::string nextDoctorID();
        std::string nextPatientID();
};