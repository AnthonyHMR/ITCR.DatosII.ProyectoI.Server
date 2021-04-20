#ifndef ITCR_DATOSII_PROYECTOI_SERVER_MSERVER_H
#define ITCR_DATOSII_PROYECTOI_SERVER_MSERVER_H

#include <string>
#include <nlohmann/json.hpp>
#include <iomanip>
#include "MemoryMap.h"
#include "Request.h"
using json = nlohmann::json;
using namespace std;

class mServer {
public:
    mServer(int port, int size);
    ~mServer();
    int runServer();
    void getMessage();
    void requestWriter(string message);
    void sendMessage(string message);
    void requestReader(ifstream JsonRequest);
    MemoryMap *memoryMap = new MemoryMap(size);
    int cont = 0;
private:
    void endRun();
    int port;
    int size;
    char buf[4096];
    int clientSocket;
    int bytesRecv;
    Request *currentRequest = new Request();

    void updateJsonFIle(const json &jsonReader) const;
};

#endif //ITCR_DATOSII_PROYECTOI_SERVER_MSERVER_H
