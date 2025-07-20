#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>

class Logger {
public:
    enum LogLevel { INFO, WARNING, ERROR };
    
    explicit Logger(const std::string& filename = "log.json");
    ~Logger();
    
    void Log(LogLevel level, const std::string& message);

private:
    std::ofstream logFile;
    
    std::string GetTimestamp() const;
    std::string LogLevelToString(LogLevel level) const;
};

#endif 

