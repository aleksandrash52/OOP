#ifndef SCREENLOGGER_H
#define SCREENLOGGER_H

#include "Logger.h"
#include <iostream>

class ScreenLogger : public Logger {
public:
    void log(const std::string& message) override;
};

#endif 
