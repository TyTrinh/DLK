#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
using namespace std;

class Doctor{
    public:
        string doctorID;
        string specialization;
        string doctorRole;

        Doctor();
        Doctor(string doctorID, string specialization, string doctorRole);
        ~Doctor();

        void setDoctorID(string doctorID);
        string getDoctorID() const;
        void setSpecialization(string specialization);
        string getSpecialization()const;
        void setDoctorRole(string doctorRole);
        string getDoctorRole() const;

        friend ostream& operator<<(ostream&, const Doctor&);
        // friend istream& operator>>(istream&, Doctor&);

   
    private:
        void findPatient(); // xây dựng class find riêng & rating - bac si
        void viewAppointment(); // myTools.viewAppointment();
        void markAsBusy(); // tương tự
};

// chung mot ham find => hash (băm trong băm)
// 
