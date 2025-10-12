#include "../include/Patient.h"
#include "../include/Doctor.h"
#include "../include/Admin.h"
#include "../include/Appointment.h"
#include <vector>
#include <algorithm>
#include <memory>


class DataStore {
public:
std::vector<Patient> patients;
std::vector<Doctor> doctors;
std::vector<Admin> admins;
std::vector<Appointment> appointments;


void addPatient(const Patient& p) { patients.push_back(p); }
void addDoctor(const Doctor& d) { doctors.push_back(d); }
void addAdmin(const Admin& a) { admins.push_back(a); }
void addAppointment(const Appointment& ap) { appointments.push_back(ap); }


// find helpers (simple linear search for demo)
Patient* findPatientById(const std::string& id) {
for (auto &p : patients) if (p.getId() == id) return &p;
return nullptr;
}
Doctor* findDoctorById(const std::string& id) {
for (auto &d : doctors) if (d.getId() == id) return &d;
return nullptr;
}
};