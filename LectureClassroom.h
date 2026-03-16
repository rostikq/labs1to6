//
// Created by user on 3/16/2026.
//

#ifndef LABS1TO6_LECTURECLASSROOM_H
#define LABS1TO6_LECTURECLASSROOM_H
#include "Classroom.h"


class LectureClassroom : public Classroom {
public:
    LectureClassroom(unsigned int number, unsigned int capacity) : Classroom(number, capacity) {

    }

    ~LectureClassroom() override = default;
};


#endif //LABS1TO6_LECTURECLASSROOM_H