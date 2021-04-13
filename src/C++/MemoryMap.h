//
// Created by juanpr on 12/4/21.
//

#ifndef ITCR_DATOSII_PROYECTOI_SERVER_MEMORYMAP_H
#define ITCR_DATOSII_PROYECTOI_SERVER_MEMORYMAP_H
#include <stdlib.h>


class MemoryMap {
private:
    void *block;
    int counter = 0;
public:
    MemoryMap(int memorySize){
        block = malloc(memorySize);
    }
    void * getBlock();
    void updateCounter();
    int getCounter();
    void placePetition();

};


#endif //ITCR_DATOSII_PROYECTOI_SERVER_MEMORYMAP_H
