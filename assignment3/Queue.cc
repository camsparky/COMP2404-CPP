#include "Queue.h"

Queue::Queue() : head(NULL), tail(NULL){}

Queue::~Queue(){
    Node* last = head;
    Node* next = head;
    while(next != NULL){ //Iterating through each node in the queue and deleting them
        next = next->next;
        delete last;
        last = next;
    }
}

bool Queue::isEmpty() const{ //returns true if the queue is empty, false otherwise.
    if(head == NULL){ // Queue is empty if the head points to nothing
        return true;
    }
    else{
        return false;
    }
}

void Queue::peekFirst(WHLocation** loc){ //Stores the first element of the queue within the "wLocation" output parameter.
    if(isEmpty()){ //Making sure the queue is not empty before storing the first element within the output parameter.
        *loc = NULL;
    }
    else{
        *loc = head->data;
    }
}

void Queue::popFirst(WHLocation** loc){ //Stores the first element of the queue within the "wLocation" output parameter. However also removes and deletes the first element / node.
    if(isEmpty()){ // Making sure the queue is not empty before popping
        *loc = NULL;
    }
    else{
        Node* temp;
        *loc = head->data;
        temp = head->next;
        delete head;
        head = temp;
        if(head == NULL){ // Just being extra careful and making sure to reset the tail pointer if the queue is empty.
            tail = NULL;
        }
    }
}

void Queue::addLast(WHLocation* loc){ //Adds the input WHLocation to the queue (Creates a new node and appends it to the queue using the wLocation pointer as data)
    Node* newNode = new Node();
    newNode->data = loc;
    newNode->next = NULL;

    if(head==NULL){ 
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void Queue::print() const{ // Prints every WHLocation info that is within the queue
    Node* temp = head;
    while(temp != NULL){ //Iterating through each node in the queue
        temp->data->print();
        temp = temp->next;
    }
}