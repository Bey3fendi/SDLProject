#include "Logger.h"

#ifdef _WIN32
#include <Windows.h>
#endif

Logger& Logger::GetInstance() {
    static Logger instance;
    return instance;
}

Logger::Logger()
#ifdef _WIN32
    : h(GetStdHandle(STD_OUTPUT_HANDLE))
#endif
{}

Logger::~Logger() = default;

std::ostream& Logger::operator()(const LogLevel& level) {
    std::lock_guard<std::mutex> lock(mtx);

#ifdef _WIN32
    SetColor(level);
    switch (level) {
    case INFO:
        std::cout << "\n[INFO] ";
        break;
    case WARNING:
        std::cout << "\n[WARNING] ";
        break;
    case ERROR:
        std::cout << "\n[ERROR] ";
        break;
    default:
        std::cout << "\n[UNKNOWN] ";
        break;
    }
#else
    switch (level) {
    case INFO:
        std::cout << "\n[INFO] ";
        break;
    case WARNING:
        std::cout << "\n[WARNING] ";
        break;
    case ERROR:
        std::cout << "\n[ERROR] ";
        break;
    default:
        std::cout << "\n[UNKNOWN] ";
        break;
    }
#endif

    return std::cout;
}

#ifdef _WIN32
void Logger::SetColor(LogLevel level) {
    switch (level) {
    case LogLevel::INFO:
        SetConsoleTextAttribute(h, 7);   // Light gray
        break;
    case LogLevel::WARNING:
        SetConsoleTextAttribute(h, 14);  // Yellow
        break;
    case LogLevel::ERROR:
        SetConsoleTextAttribute(h, 12);  // Red
        break;
    default:
        SetConsoleTextAttribute(h, 15);  // White
        break;
    }
}
#endif
