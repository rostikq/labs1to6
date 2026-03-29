//
// Created by user on 3/2/2026.
//
#ifndef LABS1TO6_LECTURER_H
#define LABS1TO6_LECTURER_H
#include <format>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

#include "Course.h"
#include "ISchedulable.h"
#include "Person.h"

class Lecturer final : public Person, public ISchedulable {
private:
    unsigned int m_experienceYears;
    std::string m_degree;
    std::string m_faculty;
    std::vector<std::string> m_courses;
    std::unordered_set<int> m_tookTimeSlots;

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

    void assignCourse(std::string& course) {
        m_courses.push_back(course);
    }

    std::vector<std::string> getCourses() const { return m_courses; }

    void deassignCourse(std::string& course) {
        for (auto it = m_courses.begin(); it != m_courses.end(); ++it) {
            if (*it == course) {
                m_courses.erase(it);
                return;
            }
        }
    }

    friend void getLecturerInfo(const Lecturer& lecturer);

    void writeInfo() override {
        std::cout
        << "--Lecturer--\n"
        << m_fullName << "\n"
        "Experience years: " << m_experienceYears
        << "\nDegree: " << m_degree
        << "\nFaculty: " << m_faculty;
    }

    void assign(int timeSlot) override {
        std::cout << std::format("Assigning lecturer {} to be occupated at {}", m_fullName, timeSlot);
    }

    bool isAvailable(int timeSlot) override {
        std::cout << std::format("Is available {}", timeSlot);
        return true;
    }
};

unsigned int Lecturer::m_lecturersCount = 0;

void getLecturerInfo(const Lecturer &lecturer) {
    std::cout << "--Lecturer info--\n"
    << "Full name: " << lecturer.m_fullName
    << "\nExperience years: " << lecturer.m_experienceYears
    << "\nDegree: " << lecturer.m_degree
    << "\nFaculty: " << lecturer.m_faculty;
}


std::ifstream& operator>>(std::ifstream& ifs, Lecturer& lect) {
    std::string fullName;
    unsigned int experienceYears;
    std::string degree;
    std::string faculty;
    size_t timeSlotsCount;
    ifs >> fullName;
    ifs >> experienceYears;
    ifs >> degree;
    ifs >> faculty;
    ifs >> timeSlotsCount;
    if (timeSlotsCount > 0) {
        std::string course;
        ifs >> course;
        lect.assignCourse(course);
    }

    return ifs;
}

inline std::ofstream& operator<<(std::ofstream& ofs, const Lecturer& lect) {
    ofs << lect.getFullName() << lect.getExperienceYears() << lect.getDegree() << lect.getFaculty()
    << lect.getCourses().size();
    if (lect.getCourses().size() > 0) {
        for (auto& course : lect.getCourses()) {
            ofs << course;
        }
    }
    return ofs;
}
#endif //LABS1TO6_LECTURER_H