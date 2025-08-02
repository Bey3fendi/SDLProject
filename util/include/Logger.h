#pragma once

#include <iostream>
#include <string>
#include <mutex>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>

enum LogLevel {
    INFO,
    WARNING,
    ERROR
};

#define LOG Logger::GetInstance()
#define INFO LogLevel::INFO
#define WARNING LogLevel::WARNING
#define ERROR LogLevel::ERROR


class Logger {
public:
    static Logger& GetInstance();

    std::ostream& operator()(const LogLevel& level);

    ~Logger();

private:
    std::string GetCurrentTimestamp();
    Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

#ifdef _WIN32
    void SetColor(LogLevel level);
    HANDLE h;
#endif

    std::mutex mtx;
};
