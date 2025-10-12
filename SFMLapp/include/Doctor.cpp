#include "Doctor.h"

Doctor::Doctor(){}
Doctor::Doctor(string doctorID, string specialization, string doctorRole){
    this->doctorID = doctorID;
    this->specialization = specialization;
    this->doctorRole = doctorRole;
}
Doctor::~Doctor(){}
void Doctor::setDoctorID(string doctorID){
    this->doctorID= doctorID;
}
string Doctor::getDoctorID() const{
    return doctorID;
}
void Doctor::setSpecialization(string specialization){
    this->specialization = specialization;
}
string Doctor::getSpecialization() const{
    return specialization;
}
void Doctor::setDoctorRole(string doctorRole){
    this->doctorRole = doctorRole;
}
string Doctor::getDoctorRole() const{
    return doctorRole;
}
ostream& operator<<(ostream& o, const Doctor& doctor){
    o << doctor.getDoctorID() << "," << doctor.getSpecialization() << "," << doctor.getDoctorRole();
    return o;
}
