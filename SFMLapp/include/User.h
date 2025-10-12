#pragma once
#include <string>


class User {
public:
User() = default;
User(std::string id, std::string name): id(std::move(id)), name(std::move(name)) {}
virtual ~User() = default;


std::string getId() const { return id; }
std::string getName() const { return name; }


protected:
std::string id;
std::string name;

};