//
// Created by juanpr on 12/4/21.
//

#include "MemoryMap.h"

#include <fstream>

void* MemoryMap::getBlock(){
    return this->block;
}
void MemoryMap::updateCounter(){
    this->counter ++;
}
int MemoryMap::getCounter(){
    return this->counter;
}

void MemoryMap::placePetition(Request request) {
    if (request.getDataType() == "int"){
        stringstream toInt(request.getValue());
        toInt >> *(a_initializer + this->getCounter());

        cout << "Address ++: " << &(*(a_initializer + this->getCounter())) << "  Value: " << *(a_initializer + this->getCounter()) << "\n"<< endl;

        std::ostringstream mem;
        mem << &(*(a_initializer + this->getCounter()));
        std::string address = mem.str();

        jsonParser::writeJson(address, request.getLabel(), request.getValue(), "1");
        this->updateCounter();


    }
    /**
     * In this method the memory block must manage where is going to
     * place the petition made by the client and has to update the count so that
     * the next petitions is located right after the previous one
     */
}