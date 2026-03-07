//
// Created by user on 3/1/2026.
//

#ifndef LABS1TO6_COURSE_H
#define LABS1TO6_COURSE_H

#include <string>
#include <vector>
class Course {
private:
    std::string m_name;
    unsigned int m_credits;
    unsigned int m_lectureCount;
    unsigned int m_practiceCount;
public:
    Course() : Course("Unknown", 0, 0, 0)  {
    }

    Course(const std::string name, unsigned int credits, unsigned int lectureCount, unsigned int practiceCount):
    m_name(name), m_credits(credits), m_lectureCount(lectureCount),
    m_practiceCount(practiceCount){
    }

    Course(const Course& other): Course(other.m_name, other.m_credits, other.m_lectureCount, other.m_practiceCount) {

    }
    Course(Course&& other) {
        this->m_name = other.m_name;
        this->m_credits = other.m_credits;
        this->m_lectureCount = other.m_lectureCount;
        this->m_practiceCount = other.m_practiceCount;
    }
    ~Course() = default;

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
#endif //LABS1TO6_COURSE_H