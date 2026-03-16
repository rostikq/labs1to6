//
// Created by user on 3/16/2026.
//

#ifndef LABS1TO6_PERSON_H
#define LABS1TO6_PERSON_H
#include <string>


class Person {
protected:
    std::string m_fullName;
public:

    Person(std::string name = "Ryan Smith") : m_fullName(name) {}

    virtual ~Person() = default;

    void setFullName(const std::string& fullName) {
        m_fullName = fullName;
    }
    std::string getFullName() const { return m_fullName;}
};


#endif //LABS1TO6_PERSON_H