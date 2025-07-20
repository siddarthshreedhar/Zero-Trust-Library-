#include "logger.h"

Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::app);
    if (logFile.tellp() == 0) {
        logFile << "[\n"; // Start JSON array if file is empty
    } else {
        logFile.seekp(-2, std::ios::end);
        logFile << ",\n"; // Ensure proper JSON formatting
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile << "\n]\n"; // Close JSON array
        logFile.close();
    }
}

void Logger::Log(LogLevel level, const std::string& message) {
    std::ostringstream logEntry;
    logEntry << "{\"timestamp\": \"" << GetTimestamp() << "\", ";
    logEntry << "\"level\": \"" << LogLevelToString(level) << "\", ";
    logEntry << "\"message\": \"" << message << "\"}";
    
    std::cout << logEntry.str() << std::endl; // Print to console
    
    if (logFile.is_open()) {
        logFile << logEntry.str() << "\n]";
    }
}

std::string Logger::GetTimestamp() const {
    std::time_t now = std::time(nullptr);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buf);
}

std::string Logger::LogLevelToString(LogLevel level) const {
    switch (level) {
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

/*
int main() {
    Logger logger("test_log.json");

    logger.Log(Logger::INFO, "This is an info message.");
    logger.Log(Logger::WARNING, "This is a warning message.");
    logger.Log(Logger::ERROR, "This is an error message.");

    return 0;
}
*/
