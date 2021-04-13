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
void MemoryMap::placePetition() {
    /**
     * In this method the memory block must manage where is going to
     * place the petition made by the client and has to update the count so that
     * the next petitions is located right after the previous one
     */
}