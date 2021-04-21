//
// Created by juanpr on 12/4/21.
//

#ifndef ITCR_DATOSII_PROYECTOI_SERVER_MEMORYMAP_H
#define ITCR_DATOSII_PROYECTOI_SERVER_MEMORYMAP_H
#include <stdlib.h>
#include "Request.h"
#include <sstream>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <iomanip>
#include "jsonParser.h"

using namespace std;
using json = nlohmann::json;

class MemoryMap : public jsonParser{
private:
    void *block = nullptr;
    int * a_initializer = nullptr;
    char * char_init = nullptr;
    int counter = 0;
    int char_counter = 1;

public:
    MemoryMap(int memorySize) {
        block = malloc(memorySize);
        a_initializer = (int *)block;
        char_init = (char *)block;
    }
    void * getBlock();
    void updateCounter();
    void updateCharCounter();
    int getCounter();
    int getCharCounter();
    void placePetition(Request newRequest);
};


#endif //ITCR_DATOSII_PROYECTOI_SERVER_MEMORYMAP_H
