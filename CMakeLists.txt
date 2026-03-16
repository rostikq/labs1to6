cmake_minimum_required(VERSION 4.1)
project(labs1to6)

set(CMAKE_CXX_STANDARD 20)

add_executable(labs1to6 main.cpp
        Course.h
        Classroom.h
        Lecturer.h
        LectureClassroom.h
        PracticeClassroom.h
        Person.h
)
