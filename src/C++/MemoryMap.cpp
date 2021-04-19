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
void MemoryMap::setResults(void *memoryAddress, string label, string value, string references) {
    json resultsJson;
    resultsJson["memoryAddress"] = *static_cast<std::string*>(memoryAddress);
    resultsJson["label"] = label;
    resultsJson["value"] = value;
    resultsJson["references"] = references;

    ofstream writeResults("../results.json");
    writeResults<< std::setw(4) << resultsJson << std::endl;
}

string MemoryMap::getResults() {
    std::ifstream readResults("../results.json");
    json resultsJson;
    readResults >> resultsJson;

    return to_string(resultsJson);
}

void MemoryMap::placePetition(Request request) {
    if (request.getDataType() == "int"){
        stringstream toInt(request.getValue());
        if (this->getCounter() < 1){
            toInt >> *a_initializer;
            cout << "Address 1: " << &a_initializer << "  Value: " << *a_initializer << "\n"<< endl;
            setResults(&a_initializer, request.getLabel(), request.getValue(), "1");
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