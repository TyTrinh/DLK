#pragma once
#include <fstream>
#include <sstream>
#include <filesystem>
// #include <map>
#include "Doctor.h"
using namespace std;


class Specialization{
    public:
        string speID;
        string speName;
        map<string,Doctor> doctorList;

        Specialization();
        Specialization(string speID, string speName);
        ~Specialization();

        // Move constructor
        //Specialization(Specialization&& other) noexcept;

        void setSpecialization(string speID);
        string getSpecializationID();
        void setSpecializationName(string speName);
        string getSpecializationName();

        
        bool addDoctor(Doctor& doctor);
        bool removeDoctor(Doctor& doctor);
        bool updateInforDoctor(Doctor& doctor);
        bool listDoctor();
};
