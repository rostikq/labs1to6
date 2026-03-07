//
// Created by user on 3/2/2026.
//
#ifndef LABS1TO6_LECTURER_H
#define LABS1TO6_LECTURER_H
#include <string>

class Lecturer {
private:
    std::string m_fullName;
    unsigned int m_experienceYears;
    std::string m_degree;
    std::string m_faculty;

    static unsigned int m_lecturersCount;
public:
    Lecturer() : Lecturer("John Doe", 0, "Master", "Unknown") {

    }

    Lecturer(const std::string& name, unsigned int experienceYears, const std::string& degree, const std::string& faculty):
    m_fullName(name), m_experienceYears(experienceYears),
    m_degree(degree), m_faculty(faculty)
    {m_lecturersCount++;}

    Lecturer(const Lecturer& other) : Lecturer(other.m_fullName, other.m_experienceYears, other.m_degree, other.m_faculty){
    }
    Lecturer(Lecturer&& other) :Lecturer(other.m_fullName, other.m_experienceYears, other.m_degree, other.m_faculty) {
    }

    ~Lecturer() {
        m_lecturersCount--;
    }

    std::string getFullName() const {
        return m_fullName;
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

    static unsigned int getLecturersCount()  {
        return m_lecturersCount;
    }
};

unsigned int Lecturer::m_lecturersCount = 0;

#endif //LABS1TO6_LECTURER_H