#pragma once
#include "Specialization.h"
// #include "Doctor.h"
// #include "Patient.h"
using namespace std;

class Admin{
    private:
        string adminID;
        int adminPass;

    public:
        void adjustSchedule(); // Điều chỉnh lịch khám
        void quantityOfBookedManager(); // Quản lý số lượng đặt khám
        void cancelSchedule(); // Hủy lịch khám trong các trường hợp: bệnh nhân đk nhiều lần trên tuần, đk bị lặp
        void patientManager();
        void doctorManager(Specialization& spe, Doctor& doctor);
        void exportManager(); // Thống kê, báo cáo
    // ----------Các hàm có trong doctorManager()-------------- (và tương tự đối với patientManager())
        // Copy constructor
        // Doctor(const Doctor& other);
        // // Toán tử gán sao chép
        // Doctor& operator=(const Doctor& other); // đổi từ bác sĩ này sang bác sĩ khác
        // // Move constructor
        // Doctor (Doctor&& other) noexcept; // Chuyển giao quyền sở hữu tài nguyên
        // // Toán tử gán di chuyển
        // Doctor& operator=(Doctor&& other) noexcept;
};

// tạo sẵn acc cho admin
// từng file dữ liệu 0-100; 101-200
