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

using namespace std;
using json = nlohmann::json;

class MemoryMap {
private:
    void *block;
    int * a_initializer;
    int counter = 0;
    void setResults(void*, string, string, string);
public:
    MemoryMap(int memorySize){
        block = malloc(memorySize);
        a_initializer = (int *)block;
    }
    void * getBlock();
    void updateCounter();
    int getCounter();
    void placePetition(Request newRequest);
    string getResults();
};


#endif //ITCR_DATOSII_PROYECTOI_SERVER_MEMORYMAP_H
