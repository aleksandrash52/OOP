#include "FileLogger.h"

FileLogger::FileLogger(const std::string& filename) : logFile(filename) {}

void FileLogger::log(const std::string& message) {
    logFile << message << std::endl;
}
