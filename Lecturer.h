//
// Created by user on 3/2/2026.
//
#ifndef LABS1TO6_LECTURER_H
#define LABS1TO6_LECTURER_H
#include <string>
#include <utility>
#include <vector>

#include "Course.h"
#include "Person.h"

class Lecturer : public Person {
private:
    unsigned int m_experienceYears;
    std::string m_degree;
    std::string m_faculty;
    std::vector<Course*> m_courses;

    static unsigned int m_lecturersCount;
public:
    Lecturer() : Lecturer("John Doe", 0, "Master", "Unknown") {

    }

    Lecturer(std::string  name, unsigned int experienceYears, std::string  degree, std::string  faculty): Person(name), m_experienceYears(experienceYears),
    m_degree(std::move(degree)), m_faculty(std::move(faculty))
    {m_lecturersCount++;}

    Lecturer(const Lecturer& other) : Lecturer(other.m_fullName ,other.m_experienceYears, other.m_degree, other.m_faculty){
    }
    Lecturer(Lecturer&& other) noexcept :Lecturer(std::move(other.m_fullName), other.m_experienceYears, std::move(other.m_degree), other.m_faculty) {
    }

    ~Lecturer() {
        m_lecturersCount--;
    }

    unsigned int getExperienceYears() const {
        return m_experienceYears;
    }
    std::string getDegree() const {
        return m_degree;
    }
    std::string getFaculty() const {
        return m_faculty;
    }

    void setFullName(std::string& name) {
        m_fullName = name;
    }
    void setExperienceYears(unsigned int experienceYears) {
        m_experienceYears = experienceYears;
    }
    void setDegree(std::string& degree) {
        m_degree = degree;
    }
    void setFaculty(std::string& faculty) {
        m_faculty = faculty;
    }

    static unsigned int getCount()  {
        return m_lecturersCount;
    }

    void assignCourse(Course* course) {
        m_courses.push_back(course);
    }

    void deassignCourse(Course* course) {
        for (auto it = m_courses.begin(); it != m_courses.end(); ++it) {
            if (*it == course) {
                m_courses.erase(it);
                return;
            }
        }
    }

    friend void getLecturerInfo(const Lecturer& lecturer);
};

unsigned int Lecturer::m_lecturersCount = 0;

void getLecturerInfo(const Lecturer &lecturer) {
    std::cout << "--Lecturer info--\n"
    << "Full name: " << lecturer.m_fullName
    << "\nExperience years: " << lecturer.m_experienceYears
    << "\nDegree: " << lecturer.m_degree
    << "\nFaculty: " << lecturer.m_faculty;
}

#endif //LABS1TO6_LECTURER_H