//
// Created by user on 3/29/2026.
//

#ifndef LABS1TO6_APPLICATION_H
#define LABS1TO6_APPLICATION_H
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "Classroom.h"
#include "Lecturer.h"
#include "MenuOption.h"

using namespace std;
using namespace std::filesystem;

constexpr auto adminPassword = "adminAdmin123";

class Application {
private:
    bool m_isAdmin = false;
    bool m_isRunning = false;

    vector<unique_ptr<Lecturer>> m_lecturers;
    vector<unique_ptr<Course>> m_courses;
    vector<unique_ptr<Classroom>> m_classrooms;

    vector<MenuOption> m_options;

    void run() {
        string userAccess = requireAccessLevel();
        cout << "You successfully logged in as " << userAccess<< "\n";
        while (m_isRunning) {
            drawMenu(userAccess);
            pollInput();
        }
    }

    void drawMenu(string& userAccess) {
        cout << "--" << userAccess << " Menu--\n";
        for (int i = 0; i < m_options.size(); i++) {
            try {
                auto& option = m_options.at(i);
                if (option.adminOnly && !m_isAdmin) continue;

                cout << i + 1 << ". " << option.label << "\n";
            }
            catch (std::out_of_range& e) {
                std::cout << e.what() << std::endl;
                continue;
            }
        }
    }

    void pollInput() {
        int commandInput;
        cin >> commandInput;

        try {
            auto& opt = m_options.at(commandInput-1);
            opt.funcPtr(this);
        }
        catch (std::out_of_range& e) {
            std::cout << e.what() << std::endl;
            cout << "Wrong input, try again\n";
        }
    }

    string requireAccessLevel() {
        string enteredPassword;
        char enteredAccess = ' ';

        do {
            cout << "Please enter the access level\n"
                    "1. User\n"
                    "2. Administrator\n";
            cin >> enteredAccess;
            if (enteredAccess == '2') {
                cout << "Please enter the password to receive admin access:\n";
                cin >> enteredPassword;
            }
        }
        while (enteredAccess == '2' && enteredPassword != adminPassword);

        if (enteredAccess == '1')
            return "User";
        else {
            m_isAdmin = true;
            return "Administrator";
        }
    }

    void loadData() {
        cout << "Loading data...\n";
        ifstream f("");
    }

    void opt_exit() {
        m_isRunning = false;
    }
public:
    Application() {
        cout << "University schedule app constructed\n";
        loadData();

        MenuOption exitOpt;
        exitOpt.label = "Exit";
        exitOpt.funcPtr = &Application::opt_exit;
        m_options.push_back(exitOpt);

    }
    ~Application() {
        cout << "Application finishes\n";
    }

    void start() {
        m_isRunning = true;
        run();
    }
};


#endif //LABS1TO6_APPLICATION_H