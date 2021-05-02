//
// Created by juanpr on 1/5/21.
//

#include <iostream>
#include "Logger.h"

void Logger::readLog(){
    std::ifstream in("logs/logger.txt");
    if (in) {
        in.seekg(0, std::ios::end);
        size_t len = in.tellg();
        in.seekg(0);
        std::string contents(len + 1, '\0');
        in.read(&contents[0], len);
        logger_msg = contents;
    }
    cout<<logger_msg;

}