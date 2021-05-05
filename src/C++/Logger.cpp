//
// Created by juanpr on 1/5/21.
//

#include <iostream>
#include "Logger.h"

basic_string<char> Logger::readLog(){
    std::ifstream currentLog("logs/logger.txt");
    if (currentLog) {
        currentLog.seekg(0, std::ios::end);
        size_t len = currentLog.tellg();
        currentLog.seekg(0);
        std::string contents(len + 1, '\0');
        currentLog.read(&contents[0], len);
        logger_msg = contents;
    }

    cout<<logger_msg;
    return logger_msg;
}

void Logger::clearLogger() {
    std::ifstream currentLog("logs/logger.txt");
    currentLog.clear();
}