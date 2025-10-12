#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

#include "../include/Patient.h"
#include "../include/Doctor.h"
#include "../include/Admin.h"
#include "../include/Appointment.h"
#include "UIHelpers.cpp"

// forward declare DataStore from src/DataStore.cpp
class DataStore;

// We'll include a very small, in-file DataStore instance for simplicity
#include "DataStore.cpp" // NOTE: for a small demo we compile this way; in a real project compile separately

int main() {
    DataStore ds;
    // seed some doctors
    ds.addDoctor(Doctor("D001", "Dr. Nguyễn A", "Cardiology"));
    ds.addDoctor(Doctor("D002", "Dr. Trần B", "Pediatrics"));

    // Create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Đăng ký lịch khám");
    sf::Font font;
    if (!font.loadFromFile("./resources/Roboto-Regular.ttf")) {
        std::cerr << "Please put a TTF font at ./resources/Roboto-Regular.ttf\n";
    }

    // Simple UI state
    enum Mode { VIEW_HOME, REGISTER_PATIENT, BOOK_APPOINTMENT } mode = VIEW_HOME;

    std::string inputName;
    std::string inputPhone;
    std::string chosenDoctorId = "D001";

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) mode = VIEW_HOME;
            }
            // very small text input handling
            if (event.type == sf::Event::TextEntered) {
                if (mode == REGISTER_PATIENT) {
                    if (event.text.unicode == '\b') { if (!inputName.empty()) inputName.pop_back(); }
                    else if (event.text.unicode < 128) inputName.push_back(static_cast<char>(event.text.unicode));
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                auto pos = sf::Mouse::getPosition(window);
                // Basic button hit tests (hard-coded areas)
                if (mode == VIEW_HOME) {
                    // Register patient button area
                    if (pos.x >= 50 && pos.x <= 250 && pos.y >= 100 && pos.y <= 150) {
                        mode = REGISTER_PATIENT; inputName.clear(); inputPhone.clear();
                    }
                    // Book appointment
                    if (pos.x >= 50 && pos.x <= 250 && pos.y >= 170 && pos.y <= 220) {
                        mode = BOOK_APPOINTMENT;
                    }
                } else if (mode == REGISTER_PATIENT) {
                    // Save button
                    if (pos.x >= 50 && pos.x <= 150 && pos.y >= 400 && pos.y <= 440) {
                        // create patient id simple
                        std::ostringstream oid; oid << "P" << std::setw(3) << std::setfill('0') << (ds.patients.size()+1);
                        ds.addPatient(Patient(oid.str(), inputName, inputPhone));
                        mode = VIEW_HOME;
                    }
                } else if (mode == BOOK_APPOINTMENT) {
                    // Quick demo: book appointment with chosenDoctorId
                    if (pos.x >= 50 && pos.x <= 200 && pos.y >= 500 && pos.y <= 540) {
                        if (!ds.patients.empty()) {
                            Appointment ap; ap.id = "A" + std::to_string(ds.appointments.size()+1);
                            ap.patientId = ds.patients.back().getId();
                            ap.doctorId = chosenDoctorId;
                            ap.time = "2025-10-01 09:00"; // hard-coded for demo
                            ds.addAppointment(ap);
                            mode = VIEW_HOME;
                        }
                    }
                }
            }
        }

        window.clear(sf::Color(220, 240, 255)); // light bluish background

        if (mode == VIEW_HOME) {
            sf::Text title = makeText("Hệ thống đăng ký lịch khám", font, 28);
            title.setPosition(50, 20);
            window.draw(title);

            // buttons
            sf::RectangleShape btn1(sf::Vector2f(200, 50)); btn1.setPosition(50, 100);
            btn1.setFillColor(sf::Color(100, 180, 255));
            window.draw(btn1);
            sf::Text t1 = makeText("Đăng ký bệnh nhân", font, 18); t1.setPosition(70, 115);
            window.draw(t1);

            sf::RectangleShape btn2(sf::Vector2f(200, 50)); btn2.setPosition(50, 170);
            btn2.setFillColor(sf::Color(100, 180, 255));
            window.draw(btn2);
            sf::Text t2 = makeText("Đặt lịch khám nhanh", font, 18); t2.setPosition(70, 185);
            window.draw(t2);

            // show last patient and last appointment
            sf::Text info = makeText("Bệnh nhân: ", font, 16); info.setPosition(300, 100);
            if (!ds.patients.empty()) info.setString(std::string("Bệnh nhân gần nhất: ") + ds.patients.back().getName());
            window.draw(info);

            sf::Text apinfo = makeText("Lịch: ", font, 16); apinfo.setPosition(300, 140);
            if (!ds.appointments.empty()) apinfo.setString(std::string("Lịch gần nhất: ") + ds.appointments.back().time);
            window.draw(apinfo);

        } else if (mode == REGISTER_PATIENT) {
            sf::Text heading = makeText("Đăng ký bệnh nhân mới", font, 24); heading.setPosition(50, 50);
            window.draw(heading);
            sf::Text hint = makeText(std::string("Tên: ") + inputName, font, 20); hint.setPosition(50, 120);
            window.draw(hint);
            sf::Text hint2 = makeText(std::string("SĐT: ") + inputPhone, font, 20); hint2.setPosition(50, 160);
            window.draw(hint2);

            sf::RectangleShape saveBtn(sf::Vector2f(100, 40)); saveBtn.setPosition(50, 400); saveBtn.setFillColor(sf::Color(120,200,140));
            window.draw(saveBtn);
            sf::Text saveTxt = makeText("Lưu", font, 18); saveTxt.setPosition(80, 410);
            window.draw(saveTxt);

            sf::Text note = makeText("(Gõ tên để nhập, Esc để quay lại)", font, 14); note.setPosition(50, 460);
            window.draw(note);

        } else if (mode == BOOK_APPOINTMENT) {
            sf::Text heading = makeText("Đặt lịch khám", font, 24); heading.setPosition(50, 50);
            window.draw(heading);

            // list doctors
            int y = 120;
            for (auto &d : ds.doctors) {
                sf::Text doctorText = makeText(d.getId() + " - " + d.getName() + " (" + d.getSpeciality() + ")", font, 18);
                doctorText.setPosition(50, y);
                window.draw(doctorText);
                y += 30;
            }

            sf::RectangleShape bookBtn(sf::Vector2f(150, 40)); bookBtn.setPosition(50, 500);
            bookBtn.setFillColor(sf::Color(120,180,255));
            window.draw(bookBtn);
            sf::Text bookTxt = makeText("Đặt lịch cho bệnh nhân gần nhất", font, 14); bookTxt.setPosition(60, 510);
            window.draw(bookTxt);

            sf::Text note = makeText("(Chỉ demo: sẽ đặt cho bệnh nhân đã đăng ký cuối cùng)", font, 12); note.setPosition(50, 460);
            window.draw(note);
        }

        window.display();
    }

    return 0;
}