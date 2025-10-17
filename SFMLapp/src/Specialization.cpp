#include "E:\Trinh_KHDL\HockyIII\PBL2\Code\include\Specialization.h"
#include "E:\Trinh_KHDL\HockyIII\PBL2\Code\include\Doctor.h"
#include "E:\Trinh_KHDL\HockyIII\PBL2\Code\include\HashTable.h"
#include "E:\Trinh_KHDL\HockyIII\PBL2\Code\include\Load_Savefile.h"

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
//     cout << endl;
// }

bool Specialization::updateInforDoctor(Doctor& doctor){
    ifstream infile;
    infile.open("Doctor.txt");
    if (!infile.is_open()){
        cout << "Khong mo file de cap nhat duoc" << endl;
        return false;
    }

    vector<string> lines;
    string line,idSeparated;
    bool found = false;

    while (getline(infile,line)){
        idSeparated = line.substr(0,5);
        if (idSeparated.compare(doctor.getDoctorID()) == 0){
            ostringstream newLine;
            newLine << doctor;
            lines.push_back(newLine.str());
            found = true;
        }
        else{
            lines.push_back(line);
        }
    }

    infile.close();

    if (!found){
        cout << "Khong tim thay id phu hop de cap nhat!" << endl;
        return false;
    }

    ofstream outfile("Doctor.txt", ios::trunc);
    if (!outfile.is_open()){
        cout << "Khong the mo file ghi lai du lieu" << endl;
        return false;
    }
    for (const auto& l : lines){
        outfile << l << endl;
    }
    outfile.close();
    return true;
}
bool Specialization::listDoctor(){
    string line;
    ifstream outfile;
    outfile.open("Doctor.txt");
    
    if (outfile.is_open()){
        while (!outfile.eof()){
            getline(outfile,line);
            cout << line << endl;
        }
        outfile.close();
        return true;
    }
    return false;
}
