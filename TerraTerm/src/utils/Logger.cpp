#include "Logger.h"
#include <iostream>

Logger::LogLevel Logger::s_loglevel = LogLevel::INFO;

void Logger::setLogLevel(LogLevel level) {
    s_loglevel = level;
}

void Logger::log(LogLevel level, const std::string& message) {
    if (level >= s_loglevel) {
        std::string prefix;
        switch (level) {
            case LogLevel::DEBUG:
                prefix = "[DEBUG]: ";
                break;
            case LogLevel::INFO:
                prefix = "[INFO]: ";
                break;
            case LogLevel::WARNING:
                prefix = "[WARNING]: ";
                break;
            case LogLevel::ERROR:
                prefix = "[ERROR]: ";
                break;
        }
        std::cout << prefix << message << std::endl;
    }
}
