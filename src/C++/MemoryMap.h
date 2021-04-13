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

using namespace std;

class MemoryMap {
private:
    void *block;
    int * a_initializer;
    int counter = 0;
public:
    MemoryMap(int memorySize){
        block = malloc(memorySize);
        a_initializer = (int *)block;
    }
    void * getBlock();
    void updateCounter();
    int getCounter();
    void placePetition(Request newRequest);

};


#endif //ITCR_DATOSII_PROYECTOI_SERVER_MEMORYMAP_H
