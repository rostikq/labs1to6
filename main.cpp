#include <iostream>
#include "Lecturer.h"


int main() {
    const Lecturer lecturer("Dextar Mogan", 10, "Master", "Iftkn");
    Lecturer lecturers[5] = {};
    std::cout << lecturer.getFullName() << ":\n"
    << lecturer.getExperienceYears() << " years of experience;\n"
    << lecturer.getDegree() << " degree;\n"
    << lecturer.getFaculty() << " faculty;\n";
    std::cout << "Count of lecturers:" << Lecturer::getCount() << std::endl;
    return 0;
}