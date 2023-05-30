#include <iostream>
#include <fstream>
#include <string>

class Logger {
    public:
        static std::ofstream depurador;
        static void report(std::string debugText);
        ~Logger();
};

std::ofstream Logger::depurador("DEPURACAO", std::ios::out);

void Logger::report(std::string debugText) {
    Logger::depurador << debugText;
}

Logger::~Logger() {
    depurador.close();
}