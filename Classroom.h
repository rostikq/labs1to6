//
// Created by user on 3/2/2026.
//

#ifndef LABS1TO6_CLASSROOM_H
#define LABS1TO6_CLASSROOM_H

enum ClassroomType {
    Lecture,
    Practice
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
    Classroom(const Classroom& other) : Classroom(other.m_number, other.m_capacity, other.m_roomType) {
    }
    Classroom(Classroom&& other) {
        this->m_number = other.m_number;
        this->m_capacity = other.m_capacity;
        this->m_roomType = other.m_roomType;
    }
    ~Classroom() = default;

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
#endif //LABS1TO6_CLASSROOM_H