#pragma once
#include <string>
using namespace std;

class Account {
private:
    string Username;
    string Password;
    string Role;   // thêm thuộc tính role: admin/doctor/patient/guest

public:
    // Constructors
    Account();
    Account(string username, string password, string role);
    Account(const Account& other);
    ~Account();
    Account(Account&& other) noexcept;

    // Getters
    string getUsername() const;
    string getPassword() const;
    string getRole() const;

    // Setters
    void setUsername(const string& username);
    void setPassword(const string& password);
    void setRole(const string& role);

    // Save account ra file
    void saveAccount(const string& basePath, int stt);

    // Tạo sẵn admin account
    static void initAdminAccounts();

    // Login
    static bool login(const string& username, const string& password, const string& role);
};
