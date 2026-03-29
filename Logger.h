//
// Created by user on 3/29/2026.
//

#ifndef LABS1TO6_LOGGER_H
#define LABS1TO6_LOGGER_H
#include <filesystem>
#include <fstream>

using namespace std;
using namespace std::filesystem;

class Logger {
private:
    ofstream m_file;

public:
    Logger(string logFileName) : m_file(logFileName) {

    }
    ~Logger() {
        m_file.close();
    }

    void Log(bool isAdmin ,const string& message) {
        if (isAdmin)
            m_file << "Administrator: ";
        else {
            m_file << "User: ";
        }
        m_file << message << '\n';
    }
};


#endif //LABS1TO6_LOGGER_H