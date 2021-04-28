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
/**
 * @class MemoryMap class is implemented for the allocation of the following data types:
 * Int: integers with size of 4 bytes
 * Char: characters with size of 1 byte
 * Long: long numbers with size of 8 bytes
 * Double: double decimal numbers with size of 8 bytes size
 * Float: float numbers with size of 4 bytes
 * Short: short numbers with size of 2 bytes
 *
 */
class MemoryMap : public jsonParser{
private:
    void *block = nullptr;
    int * a_initializer = nullptr;
    char * char_init = nullptr;
    short * short_init = nullptr;
    float * float_init = nullptr;
    long * long_init = nullptr;
    double * double_init = nullptr;
    int maxSize = 0;
    int data_index[6][2] = {{1, 0},{2, 0},{4, 0},{4, 0},{8, 0},{8, 0}};
public:
    /**
     * @brief Constructor that initializes all the pointers in the memory block
     * @param memorySize is the amount of bytes that the memory block needs
     */
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
    /**
     * @brief this method selects the correct allocator based on the current
     * request object the server has received
     * @param newRequest is the object most recently parsed in the server
     */
    void placePetition(Request newRequest);
    /**
     * @brief In this method the memory block must manage where is going to
     * place the int request made by the client and has to update the count so that
     * the next request is located right after the previous one
     * @param request contains the data that has to be allocated in the memory block
     */
    void intAllocator(const Request &request);
    /**
     * @brief In this method the memory block must manage where is going to
     * place the char request made by the client and has to update the count so that
     * the next request is located right after the previous one
     * @param request contains the data that has to be allocated in the memory block
     */
    void charAllocator(const Request &request);
    /**
     * @brief In this method the memory block must manage where is going to
     * place the struct request made by the client and has to update the count so that
     * the next request is located right after the previous one
     * @param request contains the data that has to be allocated in the memory block
     */
    void structAllocator(const Request &request);
    void freeStorage();
    /**
     * @brief In this method the memory block must manage where is going to
     * place the long request made by the client and has to update the count so that
     * the next request is located right after the previous one
     * @param request contains the data that has to be allocated in the memory block
     */
    void longAllocator(const Request &request);
    /**
     * @brief In this method the memory block must manage where is going to
     * place the double request made by the client and has to update the count so that
     * the next request is located right after the previous one
     * @param request contains the data that has to be allocated in the memory block
     */
    void doubleAllocator(const Request &request);
    /**
     * @brief In this method the memory block must manage where is going to
     * place the short request made by the client and has to update the count so that
     * the next request is located right after the previous one
     * @param request contains the data that has to be allocated in the memory block
     */
    void shortAllocator(const Request &request);
    /**
     * @brief In this method the memory block must manage where is going to
     * place the float request made by the client and has to update the count so that
     * the next request is located right after the previous one
     * @param request contains the data that has to be allocated in the memory block
     */
    void floatAllocator(const Request &request);
};


#endif //ITCR_DATOSII_PROYECTOI_SERVER_MEMORYMAP_H
