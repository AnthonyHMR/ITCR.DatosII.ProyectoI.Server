//
// Created by juanpr on 12/4/21.
//

#include "MemoryMap.h"

#include <fstream>


void MemoryMap::placePetition(Request request) {
    ifstream structfile ("../structRequest.json");
    json structJson;
    structfile >> structJson;
    if (request.getDataType() == "int"){
        getLoggerManager()->my_logger->info("An int data type has been allocated");
        intAllocator(request);
    }
    else if (request.getDataType() == "char"){
        getLoggerManager()->my_logger->info("A char data type has been allocated");
        charAllocator(request);
    }
    else if (request.getDataType() == "long"){
        getLoggerManager()->my_logger->info("A long data type has been allocated");
        longAllocator(request);
    }
    else if (request.getDataType() == "short"){
        getLoggerManager()->my_logger->info("A short data type has been allocated");
        shortAllocator(request);
    }
    else if (request.getDataType() == "double"){
        getLoggerManager()->my_logger->info("A double data type has been allocated");
        doubleAllocator(request);
    }
    else if (request.getDataType() == "float"){
        getLoggerManager()->my_logger->info("A float data type has been allocated");
        floatAllocator(request);
    }
    else if (request.getDataType() == "struct"){
        getLoggerManager()->my_logger->info("A struct data type has been allocated");
        structAllocator(request);
    }
    else if (request.getDataType() == "print"){
        getLoggerManager()->my_logger->info("Print request");
        ifstream requestsFile("../requests.json");
        json allRequests;
        requestsFile >> allRequests;
        bool flag = true;
        for (int i=0; allRequests["Requests"].size()-1 != i; i++) {
            if (allRequests["Requests"][i]["label"] == request.getValue()) {
                writeJson("print",allRequests["Requests"][i]["value"], "", "", logger_manager->readLog());
                flag = false;
                break;
            }
        }
        if (flag) {
            writeJson("print", request.getValue(), "null", "-", logger_manager->readLog());
        }
    }
    else if (request.getDataType() == "reference"){
        getLoggerManager()->my_logger->info("A reference data type has been allocated");
        ifstream requestsFile("../backupResults.json");
        json allRequests;
        requestsFile >> allRequests;
        bool flag;

        for (int i=0; allRequests["Results"].size() != i; i++) {
            if (allRequests["Results"][i]["label"] == request.getValue()) {
                cout << "paso\n";
                string addrValue = allRequests["Results"][i]["memoryAddress"];
                referenceAllocator(request, addrValue);
                flag = false;
                break;
            }
        }
        if (flag) {
            writeJson("Error", "null", "", "-", logger_manager->readLog());
        }
    }
}

void MemoryMap::floatAllocator(const Request &request) {
    int index = data_index[2][1] + data_index[3][1] + 2 * data_index[4][1] + 2 * data_index[5][1];
    float f_value = boost::lexical_cast<float>(request.getValue());
    *(float_init + index) = f_value;
    cout << "Address ++: " << &(*(float_init + index)) << "  Value: " << *(float_init + index) << "\n" << endl;
    ostringstream mem;
    mem << &(*(float_init + index));
    string address = mem.str();
    writeJson(address, request.getLabel(), request.getValue(), "1", logger_manager->readLog());
    data_index[3][1]++;
}

void MemoryMap::shortAllocator(const Request &request) {
    int index = maxSize - (data_index[0][1] + data_index[1][1]);
    short s_value = boost::lexical_cast<short>(request.getValue());
    *(short_init + index) = s_value;
    cout << "Address ++: " << &(*(short_init + index)) << "  Value: " << *(short_init + index) << "\n" << endl;
    ostringstream mem;
    mem << &(*(short_init + index));
    string address = mem.str();
    writeJson(address, request.getLabel(), request.getValue(), "1", logger_manager->readLog());
    data_index[1][1]++;
}

void MemoryMap::doubleAllocator(const Request &request) {
    int index = data_index[2][1] + data_index[3][1] + data_index[4][1] + data_index[5][1];
    double d_value = boost::lexical_cast<double>(request.getValue());
    *(double_init + index) = d_value;
    cout << "Address ++: " << &(*(double_init + index)) << "  Value: " << *(double_init + index) << "\n" << endl;
    ostringstream mem;
    mem << &(*(double_init + index));
    string address = mem.str();
    writeJson(address, request.getLabel(), request.getValue(), "1", logger_manager->readLog());
    data_index[5][1]++;
}

void MemoryMap::longAllocator(const Request &request) {
    int index = data_index[2][1] + data_index[3][1] + data_index[4][1] + data_index[5][1];
    long l_value = boost::lexical_cast<long>(request.getValue());
    *(long_init + index) = l_value;
    cout << "Address ++: " << &(*(long_init + index)) << "  Value: " << *(long_init + index) << "\n" << endl;
    ostringstream mem;
    mem << &(*(long_init + index));
    string address = mem.str();
    writeJson(address, request.getLabel(), request.getValue(), "1", logger_manager->readLog());
    data_index[4][1]++;
}

void MemoryMap::charAllocator(const Request &request) {
    int index = maxSize - (data_index[0][1] + data_index[1][1])-1;
    stringstream toInt(request.getValue());
    toInt >> *(char_init + index);
    cout << "Address ++: " << (void*)&(*(char_init + index)) << "  Value: " << &(*(char_init + index)) << "\n" << endl;
    ostringstream mem;
    mem << (void*)&(*(char_init + index));
    string address = mem.str();
    writeJson(address, request.getLabel(), request.getValue(), "1", logger_manager->readLog());
    data_index[0][1]++;
}

void MemoryMap::intAllocator(const Request &request) {
    int index = data_index[2][1] + data_index[3][1] + 2*data_index[4][1] + 2*data_index[5][1];
    stringstream toInt(request.getValue());
    toInt >> *(a_initializer + index);
    cout << "Address ++: " << &(*(a_initializer + index)) << "  Value: " << *(a_initializer + index) << "\n" << endl;
    ostringstream mem;
    mem << &(*(a_initializer + index));
    string address = mem.str();
    writeJson(address, request.getLabel(), request.getValue(), "1", logger_manager->readLog());
    logger_manager->clearLogger();
    data_index[2][1]++;
}

void MemoryMap::structAllocator(const Request &request) {
    int ref_counter = 0;
    ostringstream mem;
    ifstream structfile("../structRequest.json");
    json structJson;
    structfile >> structJson;
    //iterate over struct json
    for (auto &el : structJson["value"].items()) {
        cout << el.value()["label"];
        ref_counter++;
    }
    if (ref_counter == 1){
        struct {
            int x;
        } claseA;
        mem << &claseA;
    }
    else if (ref_counter == 2){
        struct {
            int x;
            int y;
        } claseA;
        mem << &claseA;
    }
    else if (ref_counter == 3){
        struct {
            int x;
            int y;
            int z;
        } claseA;
        mem << &claseA;
    }
    string address = mem.str();
    string count = to_string(ref_counter);
    string label = structJson["label"];
    cout << "Struct address:" + address << endl;
    cout << "\n Struct label:" << label << endl;
    cout << "\n Struct ref count:" +  count << endl;
    getLoggerManager()->my_logger->warn("Struct data type allocated outside memory block");
    writeJson(address, label, "/", count, logger_manager->readLog());
}
/*    struct {
        int x;
        int y;
    } claseA;
    cout << "Struct address: "<< &claseA;*/
void MemoryMap::referenceAllocator(const Request &request, const string addrValue) {
    int index = data_index[2][1] + data_index[3][1] + 2*data_index[4][1] + 2*data_index[5][1];

    *(a_initializer + index) = 0;
    cout << "Address ++: " << &(*(a_initializer + index)) << "  Value: " << *(a_initializer + index) << "\n" << endl;
    ostringstream mem;
    mem << &(*(a_initializer + index));
    string address = mem.str();
    writeJson(address, request.getLabel(), addrValue, "1", logger_manager->readLog());
    logger_manager->clearLogger();
    data_index[2][1]++;
}
void MemoryMap::freeStorage() {
    free (this->block);
}

Logger *MemoryMap::getLoggerManager() const {
    return logger_manager;
}
