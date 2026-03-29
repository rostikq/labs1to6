//
// Created by user on 3/29/2026.
//

#ifndef LABS1TO6_APPLICATION_H
#define LABS1TO6_APPLICATION_H
#include <filesystem>
#include <iostream>
#include <vector>

#include "Classroom.h"
#include "Lecturer.h"

using namespace std;
using namespace std::filesystem;

constexpr auto adminPassword = "adminAdmin123";

class Application {
private:
    bool m_isAdmin = false;

    vector<unique_ptr<Lecturer>> m_lecturers;
    vector<unique_ptr<Course>> m_courses;
    vector<unique_ptr<Classroom>> m_classrooms;
public:
    Application() {
        cout << "University schedule app constructed";
    }
    ~Application();
};


#endif //LABS1TO6_APPLICATION_H