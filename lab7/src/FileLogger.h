#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "Logger.h"
#include <fstream>

class FileLogger : public Logger {
public:
    FileLogger(const std::string& filename);
    void log(const std::string& message) override;

private:
    std::ofstream logFile;
};

#endif 
