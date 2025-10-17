#include "genID.h"
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>

int genID::doctorCount = 0;
int genID::patientCount = 0;

// Đọc số thứ tự cuối cùng
genID::genID(const string& type){
    string filename;

    if (type == "doctor") filename = "Doctor.txt";
    else if (type == "patient") filename = "Patient.txt";
    else return;

    string line;
    string lastline;
    string lastID;
    string last3;

    ifstream infile(filename);
    if (infile.is_open()){
        while (getline(infile, line)){
            if (!line.empty()){
                lastline = line;
                lastID = lastline.substr(0,5);
                last3 = lastID.substr(2,3);
            }
        }
        if (type == "doctor"){
            doctorCount = stoi(last3);
        }
        else {
            patientCount = stoi(last3);
        }
        infile.close();
    }
    else{
        // Nếu chưa có file bắt đầu từ 0
        if (type == "doctor") doctorCount = 0;
        else patientCount = 0;
    }
}

string genID::nextDoctorID(){
    doctorCount++;
    ofstream outfile("Doctor.txt", ios::app); // app: ghi them chu khong ghi de
    // outfile << doctorCount;
    outfile.close();

    ostringstream oss;
    oss << "01" << setw(3) << setfill('0') << doctorCount;
    return oss.str();
}

string genID::nextPatientID(){
    patientCount++;
    ofstream outfile("Patient.txt", ios::app);
    // outfile << patientCount;
    outfile.close();
    
    ostringstream oss;
    oss << "02" << setw(3) << setfill('0') << patientCount;
    return oss.str();

}
