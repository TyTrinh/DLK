#include "Admin.h"

// void Admin::adjustSchedule(){

// }
// void Admin::quantityOfBookedManager(){

// }
// void Admin::cancelSchedule(){

// }
// void Admin::patientManager(){

// }
void Admin::doctorManager(Specialization& spe, Doctor& doctor){
    if (spe.addDoctor(doctor)) 
        cout << "Them bac si thanh cong" << endl;
    else 
        cout << "Them bac si khong thanh cong" << endl;
}
// void Admin::exportManager(){
    
// }

        // Move constructor
// Specialization::Specialization(Specialization&& other) noexcept{

// }

