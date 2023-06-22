#include "utils/Logger.h"

int main() {
    Logger::setLogLevel(Logger::LogLevel::DEBUG);
    Logger::log(Logger::LogLevel::INFO, "This is an information message.");
    Logger::log(Logger::LogLevel::DEBUG, "This is a debug message.");
    Logger::log(Logger::LogLevel::WARNING, "This is a warning message.");
    Logger::log(Logger::LogLevel::ERROR, "This is an error message.");
    
    return 0;
}