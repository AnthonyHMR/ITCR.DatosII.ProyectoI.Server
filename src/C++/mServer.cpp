#include "mServer.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

mServer::mServer(int listenPort, int memSize) : port(listenPort), size(memSize) {}

int mServer::runServer() {
    // Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1) {
        cerr << "can't create a socket!";
        return -1;
    }

    // Bind the socket to IP / port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    if (bind(listening, (sockaddr *) &hint, sizeof(hint)) == -1) {
        cerr << "Can't bind to IP/port";
        return -2;
    }

    // Mark to socket for listening in
    if (listen(listening, SOMAXCONN) == -1) {
        cerr << "Can't listen!";
        return -3;
    }

    // Accept a call
    sockaddr_in client;
    char host[NI_MAXHOST];
    char svc[NI_MAXSERV];

    socklen_t clientSize = sizeof(client);

    clientSocket = accept(listening, (sockaddr *) &client, &clientSize);

    if (clientSocket == -1) {
        cerr << "Problem with client connecting!";
        return -4;
    }

    // Close the listening socket
    close(listening);

    memset(host, 0, NI_MAXHOST);
    memset(svc, 0, NI_MAXSERV);

    int result = getnameinfo((sockaddr *) &client, clientSize, host, NI_MAXHOST, svc, NI_MAXSERV, 0);

    if (result) {
        cout << host << "connected on" << svc << endl;
    } else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << "connected on" << ntohs(client.sin_port) << endl;
    }

    // While receiving display message, echo message

    while (true) {
        // Clear the buffer
        memset(buf, 0, 4096);

        // Wait for a message
        bytesRecv = recv(clientSocket, buf, 4096, 0);

        if (bytesRecv == -1) {
            cerr << "There was a connection issue" << endl;
            break;
        }

        if (bytesRecv == 0) {
            cout << "The client disconnected" << endl;
            break;
        }

        // Display message
        getMessage();

        // Send message
        sendMessage("Recibido");
    }

    endRun();
}

void mServer::getMessage() {
    string received = string(buf, 0, bytesRecv);
    requestWriter(received);
    //cout << "Received: \n" << received << endl;
}

void mServer::sendMessage(string message) {

    int sendRes = send(clientSocket, message.c_str(), message.size() + 1, 0);
    if (sendRes == -1) {
        cout << "Could not send to client!\r\n";
    }
}

void mServer::requestWriter(string message) {
    json jsonReader = json::parse(message);
    ofstream writeJson("../petitions.json");
    writeJson << std::setw(4) << jsonReader << std::endl;
    jsonReader.at("dataType").get_to(this->currentRequest->dataType);
    jsonReader.at("label").get_to(this->currentRequest->label);
    jsonReader.at("expression").get_to(this->currentRequest->expression);
    jsonReader.at("value").get_to(this->currentRequest->value);
    //ifstream i("../petitions.json");
    //requestReader(i);
    this->memoryMap->placePetition(*currentRequest);
}

void mServer::requestReader(ifstream JsonRequest) {
    json jsonReader;
    JsonRequest >> jsonReader;
    jsonReader.at("dataType").get_to(this->currentRequest->dataType);
    jsonReader.at("label").get_to(this->currentRequest->label);
    jsonReader.at("expression").get_to(this->currentRequest->expression);
    jsonReader.at("value").get_to(this->currentRequest->value);

}
void mServer::endRun() {
    // Close socket
    close(clientSocket);
}

mServer::~mServer() {

}
