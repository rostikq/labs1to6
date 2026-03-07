//
// Created by user on 3/2/2026.
//

#ifndef LABS1TO6_CLASSROOM_H
#define LABS1TO6_CLASSROOM_H
#include <iostream>

enum ClassroomType {
    Lecture,
    Practice
};

class Classroom {
private:
    unsigned int m_number;
    unsigned int m_capacity;
    ClassroomType m_roomType;

    static unsigned int m_count;

public:
    Classroom(): Classroom(0, 30, Lecture) {}

    Classroom(unsigned int number, unsigned int capacity, ClassroomType type):
    m_number(number), m_capacity(capacity), m_roomType(type){
        m_count++;
    }
    Classroom(const Classroom& other) : Classroom(other.m_number, other.m_capacity, other.m_roomType) {
    }
    Classroom(Classroom&& other) {
        this->m_number = other.m_number;
        this->m_capacity = other.m_capacity;
        this->m_roomType = other.m_roomType;
        m_count++;
    }
    ~Classroom() {
        m_count--;
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

    static unsigned int getCount() {return m_count;}

    friend void getClassroomInfo(const Classroom& classroom);
};

unsigned int Classroom::m_count = 0;

void getClassroomInfo(const Classroom& classroom) {
    std::cout << "--Classroom info--\n"
    << "Number: " << classroom.m_number
    << "\nCapacity: " << classroom.m_capacity
    << "\nRoom Type: " << classroom.m_roomType;
}

#endif //LABS1TO6_CLASSROOM_H