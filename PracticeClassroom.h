//
// Created by user on 3/16/2026.
//

#ifndef LABS1TO6_PRACTICECLASSROOM_H
#define LABS1TO6_PRACTICECLASSROOM_H
#include "Classroom.h"


class PracticeClassroom : public Classroom {
public:
    PracticeClassroom(unsigned int number, unsigned int capacity) : Classroom(number, capacity) {}

    ~PracticeClassroom() = default;

    PracticeClassroom(const PracticeClassroom& other) : Classroom(other) {}
    PracticeClassroom(PracticeClassroom&& other) noexcept : Classroom(std::move(other)) {}

    PracticeClassroom& operator=(const PracticeClassroom& other) {
        if (this != &other) {
            Classroom::operator=(other);
        }
        return *this;
    }
};


#endif //LABS1TO6_PRACTICECLASSROOM_H