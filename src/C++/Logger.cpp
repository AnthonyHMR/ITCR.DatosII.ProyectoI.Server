//
// Created by juanpr on 1/5/21.
//

#include <iostream>
#include "Logger.h"

void Logger::readLog(){
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

}