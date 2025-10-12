#pragma once
#include <string>
#include "Account.h"

using namespace std;

class Guest {
private:
    Account acc;
public:
    void Dangkydnhaptaikhoan();
    void Xemthongtinbenhvien();
    void Xemthongtindoctor();
    void Xemdichvukhambenh();
    void Timkiemdoctor();
};