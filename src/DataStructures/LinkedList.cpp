#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(){
    header = new Node;
    tail = new Node;
    header->next = tail;
    header->prev = NULL;
    tail->prev = header;
    tail->next = NULL;
}



void LinkedList::addFront(int datum) {
    Node *node = new Node;
    node->data = datum;
    node->prev = header;
    node->next = header->next;

    header->next->prev = node;
    header->next = node;
}

void LinkedList::addBack(int datum){
    Node *node = new Node;
    node->data = datum;
    node->prev = tail->prev;
    node->next = tail;

    tail->prev->next = node;
    tail->prev = node;
}

void LinkedList::removeFront(){
    Node *node = header->next->next;

    delete header->next;

    header->next = node;
    node->prev = header;
}

void LinkedList::removeBack(){
    Node *node = tail->prev->prev;

    delete tail->prev;

    tail->prev = node;
    node->next = tail;
}

void LinkedList::printForward(){
    Node *node = header->next;

    while(node != tail){
        cout << node->data << " ";
        node = node->next;
    }
}

void LinkedList::printReverse(){
    Node *node = tail->prev;

    while(node != header){
        cout << node->data << " ";
        node = node->prev;
    }
}

LinkedList::~LinkedList() {
    while(header->next!=tail){
        removeFront();
    }

    delete header;
    delete tail;
}