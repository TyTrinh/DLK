#pragma once
#include "User.h"


class Admin : public User {
public:
Admin() = default;
Admin(std::string id, std::string name) : User(std::move(id), std::move(name)) {}


// admin-specific methods can be added later
};