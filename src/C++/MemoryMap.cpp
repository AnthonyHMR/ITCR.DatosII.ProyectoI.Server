//
// Created by juanpr on 12/4/21.
//

#include "MemoryMap.h"

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
        if (this->getCounter() < 1){

            toInt >> *a_initializer;
            cout << "Address 1: " << &a_initializer << "  Value: " << *a_initializer << "\n"<< endl;
            this->updateCounter();
        } else{

            int a;
            toInt >> a;
            *(a_initializer + this->getCounter()) = a;
            cout << "Address ++: " << &(*(a_initializer + this->getCounter())) << "  Value: " << *(a_initializer + this->getCounter()) << "\n"<< endl;
            this->updateCounter();
        }
    }
    /**
     * In this method the memory block must manage where is going to
     * place the petition made by the client and has to update the count so that
     * the next petitions is located right after the previous one
     */
}