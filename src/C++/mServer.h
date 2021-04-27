#ifndef ITCR_DATOSII_PROYECTOI_SERVER_MSERVER_H
#define ITCR_DATOSII_PROYECTOI_SERVER_MSERVER_H

#include <string>
#include <nlohmann/json.hpp>
#include <iomanip>
#include "MemoryMap.h"
#include "Request.h"
using json = nlohmann::json;
using namespace std;
/**
 * @class server that manages the memory block reserved for the IDE client requests. It can receive requests
 * for the allocation of different data types and can send the information generated after the allocation
 *
 */
class mServer {
public:
    /**
     * @brief Constructor that has a port where the server is listening requests and a memory size
     * for the allocation of data
     * @param port integer that opens the server connection for a client
     * @param size integer that has the amount of bytes the server will ask for the memory block
     */
    mServer(int port, int size);
    /**
     * @brief object destructor
     */
    ~mServer();
    /**
     * @brief this method implements a IP/TCP protocol in the server so that a required client can
     * send and receive data if needed
     */
    int runServer();
    /**
     * @brief this method takes the bytesRecv attribute and stores a given chain of bytes received
     * from a client and casts them into a human readable format (string)
     */
    void getMessage();
    /**
     * @brief this method receives a string-json format that contains various attributes of an object
     * called request, takes the json string and parse it into a json object, sets all the
     * attributes to the current request object and finally, updates the json file history of requests
     * @param message string that contains the object info to be parsed
     */
    void requestWriter(string message);

    /**
     * @brief this methods sends a stream message to the client with a given response for its request
     * @param message
     */
    void sendMessage(string message);

private:
    void endRun();
    int port;
    int size;
    char buf[4096];
    int clientSocket;
    int bytesRecv;
    MemoryMap *memoryMap = new MemoryMap(size);
    Request *currentRequest = new Request();

    void updateJsonFIle(const json &jsonReader) const;
};

#endif //ITCR_DATOSII_PROYECTOI_SERVER_MSERVER_H
