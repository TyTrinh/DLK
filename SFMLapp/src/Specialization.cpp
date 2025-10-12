#include "Specialization.h"

Specialization::Specialization(){}
Specialization::Specialization(string speID, string speName){
    this->speID = speID;
    this->speName = speName;
}
Specialization::~Specialization(){}
        // Move constructor
// Specialization::Specialization(Specialization&& other) noexcept{

// }
void Specialization::setSpecialization(string speID){
    this->speID = speID;
}
string Specialization::getSpecializationID(){
    return speID;
}
void Specialization::setSpecializationName(string speName){
    this->speName = speName;
}
string Specialization::getSpecializationName(){
    return speName;
}
bool Specialization::addDoctor(Doctor& doctor){
    ofstream outfile;
    outfile.open("Doctor.txt", ios::app); // app: tiếp tục ghi vào không bị đè
    if (outfile.is_open()){
        outfile << doctor << endl;
        outfile.close();
        return true;
    }
    return false;
}
// bool Specialization::removeDoctor(Doctor& doctor){

// }
// bool Specialization::listDoctor(){

// }