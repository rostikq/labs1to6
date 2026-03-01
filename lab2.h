//
// Created by user on 3/1/2026.
//

#ifndef LABS1TO6_LAB2_H
#define LABS1TO6_LAB2_H

#include <string>
#include <vector>

enum ClassroomType {
    Lecture,
    Practice
};

class Course {
private:
    std::string m_name;
    unsigned int m_credits;
    unsigned int m_lectureCount;
    unsigned int m_practiceCount;
public:
    Course() : Course("Unknown", 0, 0, 0)  {
    }

    Course(std::string name, unsigned int credits, unsigned int lectureCount, unsigned int practiceCount):
    m_name(name), m_credits(credits), m_lectureCount(lectureCount),
    m_practiceCount(practiceCount){
    }

    unsigned int getCredits() const {
        return m_credits;
    }
    unsigned int getLectureCount() const {
        return m_lectureCount;
    }

    unsigned int getPracticeCount() const {
        return m_practiceCount;
    }

    void setCredits(unsigned int credits) {
        m_credits = credits;
    }
    void setLectureCount(unsigned int lectureCount) {
        m_lectureCount = lectureCount;
    }
    void setPracticeCount(unsigned int practiceCount) {
        m_practiceCount = practiceCount;
    }
};

class Classroom {
private:
    unsigned int m_number;
    unsigned int m_capacity;
    ClassroomType m_roomType;

public:
    Classroom(): Classroom(0, 30, Lecture) {}

    Classroom(unsigned int number, unsigned int capacity, ClassroomType type):
    m_number(number), m_capacity(capacity), m_roomType(type){
    }

    unsigned int getNumber() const {
        return m_number;
    }

    unsigned int getCapacity() const {
        return m_capacity;
    }

    ClassroomType getRoomType() const {
        return m_roomType;
    }

    void setNumber(unsigned int number) {
        m_number = number;
    }
    void setCapacity(unsigned int capacity) {
        m_capacity = capacity;
    }
    void setRoomType(ClassroomType type) {
        m_roomType = type;
    }
};

class Lecturer {
private:
    std::string m_fullName;
    unsigned int m_experienceYears;
    std::string m_degree;
    std::string m_faculty;
public:
    Lecturer() : Lecturer("John Doe", 0, "Master", "Unknown") {

    }

    Lecturer(std::string& name, unsigned int experienceYears, std::string& degree, std::string& faculty):
    m_fullName(name), m_experienceYears(experienceYears),
    m_degree(degree), m_faculty(faculty)
    {}

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

#endif //LABS1TO6_LAB2_H