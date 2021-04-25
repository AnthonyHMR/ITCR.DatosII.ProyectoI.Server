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
#include "../DataStructures/LinkedList.h"
#include <boost/lexical_cast.hpp>// for lexical_cast()
using namespace std;
using json = nlohmann::json;

class MemoryMap : public jsonParser{
private:
    void *block = nullptr;
    int * a_initializer = nullptr;
    char * char_init = nullptr;
    short * short_init = nullptr;
    float * float_init = nullptr;
    long * long_init = nullptr;
    double * double_init = nullptr;
    int counter = 0;
    int char_counter = 0;
    int maxSize = 0;
    int data_index[6][2] = {{1, 0},{2, 0},{4, 0},{4, 0},{8, 0},{8, 0}};
public:
    MemoryMap(int memorySize) {
        maxSize = memorySize;
        block = malloc(memorySize);
        a_initializer = (int *)block;
        char_init = (char *)block;
        short_init = (short *)block;
        float_init = (float *)block;
        long_init = (long *)block;
        double_init = (double *)block;


    }
    void * getBlock();
    void updateCounter();
    void updateCharCounter();
    int getCounter();
    int getCharCounter();
    void placePetition(Request newRequest);

    void intAllocator(const Request &request);

    void charAllocator(const Request &request);
    void structAllocator(const Request &request);
    void freeStorage();

    void longAllocator(const Request &request);

    void doubleAllocator(const Request &request);

    void shortAllocator(const Request &request);

    void floatAllocator(const Request &request);
};


#endif //ITCR_DATOSII_PROYECTOI_SERVER_MEMORYMAP_H
