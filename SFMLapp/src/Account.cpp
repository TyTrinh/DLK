#include "Account.h"
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

// ===== Constructor =====
Account::Account() {}
Account::Account(string username, string password, string role)
    : Username(username), Password(password), Role(role) {}
Account::Account(const Account &other)
    : Username(other.Username), Password(other.Password), Role(other.Role) {}
Account::~Account() {}
Account::Account(Account &&other) noexcept
    : Username(move(other.Username)), Password(move(other.Password)), Role(move(other.Role)) {}

// ===== Getters / Setters =====
string Account::getUsername() const { return Username; }
string Account::getPassword() const { return Password; }
string Account::getRole() const { return Role; }
void Account::setUsername(const string &username) { Username = username; }
void Account::setPassword(const string &password) { Password = password; }
void Account::setRole(const string &role) { Role = role; }

// ===== Save account =====
void Account::saveAccount(const string &basePath, int stt) {
    fs::create_directories(basePath);

    string filename = basePath + "/accounts.txt";
    ofstream fout(filename, ios::app);
    if (!fout) {
        cerr << "Khong the mo file " << filename << endl;
        return;
    }
    fout << stt << ". " << Username << " " << Password << " " << Role << "\n";
    fout.close();
}

// ===== Load admin account (tạo sẵn 2 admin) =====
void Account::initAdminAccounts() {
    string adminPath = "data/admin";
    fs::create_directories(adminPath);

    string filename = adminPath + "/accounts_admin.txt";
    ofstream fout(filename, ios::trunc);
    fout << "1. admin1 123456 admin\n";
    fout << "2. admin2 654321 admin\n";
    fout.close();
}

// ===== Check login =====
bool Account::login(const string &username, const string &password, const string &role) {
    string basePath;
    if (role == "admin")
        basePath = "data/admin/accounts_admin.txt";
    else if (role == "doctor")
        basePath = "data/doctor/accounts.txt";
    else if (role == "patient")
        basePath = "data/patient/accounts.txt";
    else
        basePath = "data/guest/accounts.txt";

    ifstream fin(basePath);
    if (!fin) {
        cerr << "Khong mo duoc file: " << basePath << endl;
        return false;
    }

    string line;
    while (getline(fin, line)) {
        // format: stt. user pass role
        size_t dotPos = line.find(". ");
        if (dotPos == string::npos) continue;
        string content = line.substr(dotPos + 2);

        string u, p, r;
        istringstream iss(content);
        iss >> u >> p >> r;

        if (u == username && p == password && r == role) {
            return true;
        }
    }
    return false;
}
