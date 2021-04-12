#include <string>
#include <fstream>
#include "mServer.h"
#include "../DataStructures/LinkedList.h"

int main() {
    mServer *server = new mServer(54000, 12345);
    server->runServer();

    /*
    ofstream cout("filename.txt");
    string name = "Juan";
    cout << "What is your name? ";
    cout << "Hello, "<<name << " in->\n" << &name << endl;
    cout << name << "!" << endl;
    cout<<"testing files from terminal\n";
    cout << "Hello from terminal, " << name << "!" << endl;
    cout.close();
     */

    return 0;
}
