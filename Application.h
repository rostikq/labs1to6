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
#include "Logger.h"
#include "MenuOption.h"

using namespace std;
using namespace std::filesystem;

constexpr auto adminPassword = "adminAdmin123";

class Application {
private:
    bool m_isAdmin = false;
    bool m_isRunning = false;

    Logger m_logger;

    vector<unique_ptr<Lecturer>> m_lecturers;
    vector<unique_ptr<Course>> m_courses;
    vector<unique_ptr<Classroom>> m_classrooms;

    vector<MenuOption> m_options;

    ofstream m_lecturerFile;
    ofstream m_coursesFile;
    ofstream m_classroomsFile;
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
            cout << "Wrong input, there is no " << commandInput << " option\n";
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
        ifstream lecturersF("lecturers.txt");
        ifstream coursesF("courses.txt");
        ifstream classroomsF("classrooms.txt");
        if (lecturersF.is_open() == false) {
            cout << "There is no Lecturers.txt to load from\n";
        }
        if (coursesF.is_open() == false) {
            cout << "There is no courses.txt to load from\n";
        }
        if (classroomsF.is_open() == false) {
            cout << "There is no classrooms.txt to load from\n";
        }
        if (lecturersF.is_open()) {
            unsigned int amount;
            lecturersF >> amount;
            if (amount > 0) {
                for (int i = 0; i < amount; i++) {
                    auto lecturer = std::make_unique<Lecturer>();
                    lecturersF >> *lecturer;
                    m_lecturers.push_back(std::move(lecturer));
                }
            }
        }
        if (classroomsF.is_open()) {
            unsigned int amount = 0;
            classroomsF >> amount;
            if (amount > 0) {
                for (int i = 0; i < amount; i++) {
                    auto classroom = std::make_unique<Classroom>();
                    classroomsF >> *classroom;
                    m_classrooms.push_back(std::move(classroom));
                }
            }
        }
        if (coursesF.is_open()) {
            unsigned int amount = 0;
            coursesF >> amount;
            if (amount > 0) {
                for (int i = 0; i < amount; i++) {
                    auto course = std::make_unique<Course>();
                    coursesF >> *course;
                    m_courses.push_back(std::move(course));
                }
            }
        }
    }

    void opt_Addlecturer() {
        m_logger.Log(m_isAdmin, "Add new lecturer");

        auto lecturer = std::make_unique<Lecturer>();

        cout << "Please enter full name:\n";
        string name;
        unsigned int years;
        string faculty;
        string degree;
        getline(cin >> std::ws,name);
        lecturer->setFullName(name);
        cout << "Please enter experiences years\n";
        cin >> years;
        lecturer->setExperienceYears(years);
        cout << "Please enter degree\n";
        getline(cin >> std::ws, degree);
        lecturer->setDegree(degree);
        cout << "Please enter faculty\n";
        getline(cin >> std::ws,faculty);
        lecturer->setFaculty(faculty);
        m_lecturers.push_back(std::move(lecturer));
    }

    void opt_AddClassroom() {
        m_logger.Log(m_isAdmin, "Add new classroom");

        auto classroom = std::make_unique<Classroom>();
        cout << "Enter number of classroom:\n";
        unsigned int number;
        char classRoomType;
        cin >> number;
        classroom->setNumber(number);
        cout << "Enter capacity of classroom:\n";
        cin >> number;
        classroom->setCapacity(number);
        cout << "Enter classroom type (1 - lecture, 2 - practice):\n";
        cin >> classRoomType;
        if (classRoomType == '2')
        classroom->setClassroomType(ClassroomType::PRACTICE_CLASSROOM);
        m_classrooms.push_back(std::move(classroom));
    }

    void opt_AddCourse() {
        m_logger.Log(m_isAdmin, "Add new course");

        string name;
        unsigned int credits;
        unsigned int practicalHours;
        unsigned int lectureHours;

        cout << "Enter course name:\n";
        getline(cin >> ws, name);
        cout << "Enter credit amount:\n";
        cin >> credits;
        cout << "Enter practical hours:\n";
        cin >> practicalHours;
        cout << "Enter lecture hours:\n";
        cin >> lectureHours;
        auto course = make_unique<Course>(name, credits, lectureHours, practicalHours);
        m_courses.push_back(std::move(course));
    }

    void opt_editLecturer() {

        unsigned int id;
        cout << "Enter id of Lecturer";
        cin >> id;

        try {
            auto& lecturer = m_lecturers.at(id);
            m_logger.Log(m_isAdmin, std::format("Edit lecturer {}", id));
            cout << "Please enter full name:\n";
            string name;
            unsigned int years;
            string faculty;
            string degree;
            getline(cin >> std::ws,name);
            lecturer->setFullName(name);
            cout << "Please enter experiences years\n";
            cin >> years;
            lecturer->setExperienceYears(years);
            cout << "Please enter degree\n";
            getline(cin >> std::ws, degree);
            lecturer->setDegree(degree);
            cout << "Please enter faculty\n";
            getline(cin >> std::ws,faculty);
            lecturer->setFaculty(faculty);
        }
        catch (std::out_of_range& e) {
            std::cout << e.what() << std::endl;
        }
    }

    void opt_typeAllLecturers() {
        m_logger.Log(m_isAdmin, std::format("Print all lecturers"));
        unsigned int it = 0;
        for (auto& lecturer : m_lecturers) {
            std::cout << it;
            lecturer->writeInfo();
            it++;
        }
    }

    void opt_typeAllCourses() {
        m_logger.Log(m_isAdmin, std::format("Print all courses"));
        unsigned int it = 0;
        for (auto& courses : m_courses) {
            std::cout << it;
            courses->writeInfo();
            it++;
        }
    }

    void opt_typeAllClassrooms() {
        unsigned int it = 0;
        m_logger.Log(m_isAdmin, std::format("Print all classrooms"));
        for (auto& classroom : m_classrooms) {
            std::cout << it;
            classroom->writeInfo();
            it++;
        }
    }

    void opt_exit() {
        m_isRunning = false;
    }

    void opt_save() {
        std::remove("lecturers.txt");
        std::remove("classrooms.txt");
        std::remove("courses.txt");
        m_lecturerFile.open("lecturers.txt",  ios::app);
        m_lecturerFile << m_lecturers.size() << '\n';
        if (m_lecturers.size() > 0) {
            for (auto& lecturer : m_lecturers) {
                m_lecturerFile << *lecturer << '\n';
            }
        }
        m_lecturerFile.close();
        m_classroomsFile.open("classrooms.txt", ios::app);
        m_classroomsFile << m_classrooms.size() << '\n';
        if (m_classrooms.size() > 0) {
            for (auto& classroom : m_classrooms) {
                m_classroomsFile << *classroom << '\n';
            }
        }
        m_classroomsFile.close();
        m_coursesFile.open("courses.txt", ios::app);
        m_coursesFile << m_courses.size() << '\n';
        if (m_courses.size() > 0) {
            for (auto& course : m_courses) {
                m_coursesFile << *course << '\n';
            }
        }
        m_logger.Log(m_isAdmin, std::format("Save changes"));
        m_coursesFile.close();
    }

    void opt_appendCourseToLecturer() {
        unsigned int id;
        cout << "Enter lecturer id: ";
        cin >> id;
        try {
            string course;
            auto& lecturer =m_lecturers.at(id);
            m_logger.Log(m_isAdmin, std::format("Append course to lecturer {}", id));
            cout << "Please course name:\n";
            getline(cin >> std::ws, course);
        }
        catch (std::out_of_range& e) {
            std::cout << e.what() << std::endl;
        }
    }
public:
    Application() : m_logger("logs.txt") {
        cout << "University schedule app constructed\n";
        loadData();

        m_lecturerFile.open("lecturers.txt",  ios::app);
        m_coursesFile.open("courses.txt",  ios::app);
        m_classroomsFile.open("classrooms.txt",  ios::app);

        {
            m_options.emplace_back("Exit", &Application::opt_exit);
            m_options.emplace_back("Edit lecturer", &Application::opt_editLecturer);
            m_options.emplace_back("Print all lecturers info", &Application::opt_typeAllLecturers);
            m_options.emplace_back("Print all classrooms info", &Application::opt_typeAllClassrooms);
            m_options.emplace_back("Print all courses info", &Application::opt_typeAllCourses);
            //Always check for admin options to be farther than general
            m_options.emplace_back("Add Lecturer", &Application::opt_Addlecturer, true);
            m_options.emplace_back("Add Classroom", &Application::opt_AddClassroom, true);
            m_options.emplace_back("Add Course", &Application::opt_AddCourse, true);
            m_options.emplace_back("Append course to lecturer", &Application::opt_appendCourseToLecturer, true);
            m_options.emplace_back("Save changes", &Application::opt_save, true);
        }
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