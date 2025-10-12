#pragma once
#include "User.h"
#include <string>


class Doctor : public User {
public:
Doctor() = default;
Doctor(std::string id, std::string name, std::string speciality = "General") : User(std::move(id), std::move(name)), speciality(std::move(speciality)) {}


std::string getSpeciality() const { return speciality; }
void setSpeciality(const std::string& s) { speciality = s; }


private:
std::string speciality;
};