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
public:
    Lecturer() : Lecturer("John Doe", 0, "Master", "Unknown") {

    }

    Lecturer(const char* name, unsigned int experienceYears, const char* degree, const char* faculty):
    m_fullName(name), m_experienceYears(experienceYears),
    m_degree(degree), m_faculty(faculty)
    {}

    Lecturer(const Lecturer& other) : m_fullName(other.m_fullName),
    m_degree(other.m_degree), m_experienceYears(other.m_experienceYears),
    m_faculty(other.m_faculty){
    }
    Lecturer(Lecturer&& other) {
        this->m_fullName = other.m_fullName;
        this->m_experienceYears = other.m_experienceYears;
        this->m_faculty = other.m_faculty;
        this->m_degree = other.m_degree;
    }

    ~Lecturer() = default;

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
};

#endif //LABS1TO6_LECTURER_H