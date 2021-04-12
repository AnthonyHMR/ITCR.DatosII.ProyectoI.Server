#ifndef ITCR_DATOSII_PROYECTOI_SERVER_LINKEDLIST_H
#define ITCR_DATOSII_PROYECTOI_SERVER_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    bool isEmpty() const;
    void addFront(int datum);
    void addBack(int datum);
    void removeFront();
    void removeBack();
    void printReverse();
    void printForward();
private:
    Node *header;
    Node *tail;
};

#endif //ITCR_DATOSII_PROYECTOI_SERVER_LINKEDLIST_H
