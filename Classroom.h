//
// Created by user on 3/2/2026.
//

#ifndef LABS1TO6_CLASSROOM_H
#define LABS1TO6_CLASSROOM_H
#include <iostream>

#include "ISchedulable.h"

enum ClassroomType : unsigned int {
    LECTURE_CLASSROOM,
    PRACTICE_CLASSROOM
};

class Classroom: public ISchedulable{
protected:
    unsigned int m_number;
    unsigned int m_capacity;

    static unsigned int m_count;
    ClassroomType m_roomType;

public:
    Classroom(): Classroom(0, 30, LECTURE_CLASSROOM) {}

    Classroom(unsigned int number, unsigned int capacity, ClassroomType type):
    m_number(number), m_capacity(capacity), m_roomType(type){
        m_count++;
    }
    Classroom(const Classroom& other) : Classroom(other.m_number, other.m_capacity, other.m_roomType) {
    }
    Classroom(Classroom&& other) noexcept {
        this->m_number = other.m_number;
        this->m_capacity = other.m_capacity;
        m_count++;
    }
    virtual ~Classroom() {
        m_count--;
    }

    unsigned int getNumber() const {
        return m_number;
    }

    unsigned int getCapacity() const {
        return m_capacity;
    }
    ClassroomType getClassroomType() const {
        return m_roomType;
    }

    void setNumber(unsigned int number) {
        m_number = number;
    }
    void setCapacity(unsigned int capacity) {
        m_capacity = capacity;
    }

    void setClassroomType(ClassroomType classroomType) {
        m_roomType = classroomType;
    }

    Classroom& operator=(const Classroom& other) {
        if (this != &other) {
            this->m_number = other.m_number;
            this->m_capacity = other.m_capacity;
        }
        return *this;
    }

    void assign(int timeSlot) override {
        std::cout << "Assignment of Classroom timeSlot: " << timeSlot << std::endl;
    }

    bool isAvailable(int timeSlot) override {
        std::cout << "Check if classroom occupated at " << timeSlot << std::endl;
        return true;
    }

    void writeInfo() {
        getClassroomInfo(*this);
    }

    static unsigned int getCount() {return m_count;}

    friend void getClassroomInfo(const Classroom& classroom);
};

unsigned int Classroom::m_count = 0;

inline void getClassroomInfo(const Classroom& classroom) {
    std::cout << "--Classroom--\n"
    << "Number: " << classroom.m_number
    << "\nCapacity: " << classroom.m_capacity
    << "\nRoom Type: ";
    if (classroom.m_roomType == LECTURE_CLASSROOM) {
        std::cout << "LECTURE" << std::endl;
    }
    else if (classroom.m_roomType == PRACTICE_CLASSROOM) {
        std::cout << "PRACTICE" << std::endl;
    }
}

inline std::ifstream& operator>>(std::ifstream& ifs, Classroom& classroom) {
    unsigned int number;
    unsigned int capacity;
    unsigned int roomType;
    ifs >> number >> capacity >> roomType;
    classroom.setNumber(number);
    classroom.setCapacity(capacity);
    classroom.setClassroomType((ClassroomType)roomType);
    return ifs;
}

inline std::ofstream& operator<<(std::ofstream& ofs, const Classroom& classroom) {
    ofs << classroom.getNumber() << std::endl;
    ofs << classroom.getCapacity() << std::endl;
    ofs << classroom.getClassroomType() << std::endl;

    return ofs;
}

#endif //LABS1TO6_CLASSROOM_H