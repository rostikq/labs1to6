//
// Created by user on 3/2/2026.
//

#ifndef LABS1TO6_CLASSROOM_H
#define LABS1TO6_CLASSROOM_H
#include <iostream>


class Classroom {
protected:
    unsigned int m_number;
    unsigned int m_capacity;

    static unsigned int m_count;

public:
    Classroom(): Classroom(0, 30) {}

    Classroom(unsigned int number, unsigned int capacity):
    m_number(number), m_capacity(capacity){
        m_count++;
    }
    Classroom(const Classroom& other) : Classroom(other.m_number, other.m_capacity) {
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

    void setNumber(unsigned int number) {
        m_number = number;
    }
    void setCapacity(unsigned int capacity) {
        m_capacity = capacity;
    }

    Classroom& operator=(const Classroom& other) {
        if (this != &other) {
            this->m_number = other.m_number;
            this->m_capacity = other.m_capacity;
        }
        return *this;
    }

    static unsigned int getCount() {return m_count;}

    friend void getClassroomInfo(const Classroom& classroom);
};

unsigned int Classroom::m_count = 0;

inline void getClassroomInfo(const Classroom& classroom) {
    std::cout << "--Classroom info--\n"
    << "Number: " << classroom.m_number
    << "\nCapacity: " << classroom.m_capacity
    << "\nRoom Type: " << classroom.m_roomType;
}

#endif //LABS1TO6_CLASSROOM_H