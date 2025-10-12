#pragma once
#include "User.h"
#include <vector>
#include <string>


class Patient : public User {
public:
Patient() = default;
Patient(std::string id, std::string name, std::string phone = "") : User(std::move(id), std::move(name)), phone(std::move(phone)) {}


void setPhone(const std::string& p) { phone = p; }
std::string getPhone() const { return phone; }


private:
std::string phone;
};