#ifndef ITCR_DATOSII_PROYECTOI_SERVER_NODE_H
#define ITCR_DATOSII_PROYECTOI_SERVER_NODE_H

class Node {
private:
    int data;
    Node *next;
    Node *prev;

    friend class LinkedList;
};

#endif //ITCR_DATOSII_PROYECTOI_SERVER_NODE_H
