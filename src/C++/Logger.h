//
// Created by juanpr on 1/5/21.
//

#ifndef ITCR_DATOSII_PROYECTOI_SERVER_LOGGER_H
#define ITCR_DATOSII_PROYECTOI_SERVER_LOGGER_H
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include <string>
#include <fstream>

using namespace std;
using namespace spdlog;
class Logger {
public:
    shared_ptr<spdlog::logger>  my_logger;
    void clearLogger();
    string logger_msg;
    Logger(){
        try
        {
            my_logger = basic_logger_mt("Log_MSG", "logs/logger.txt");
            my_logger->flush_on(level::trace);
        }
        catch (const spdlog::spdlog_ex &ex)
        {
            cout << "Log init failed: " << ex.what() << endl;
        }
    }
    basic_string<char> readLog();
};


#endif //ITCR_DATOSII_PROYECTOI_SERVER_LOGGER_H
