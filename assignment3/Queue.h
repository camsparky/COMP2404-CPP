#ifndef QUEUE_H
#define QUEUE_H

#include "WHLocation.h"
using namespace std;

class Queue{

    public:
        //Constructor / Destructor
        Queue();
        ~Queue();

        //Other Functions
        bool isEmpty() const; //returns true if the queue is empty, false otherwise.
        void peekFirst(WHLocation** loc); //Stores the first element of the queue within the "wLocation" output parameter.
        void popFirst(WHLocation** loc); //Stores the first element of the queue within the "wLocation" output parameter. However also removes and deletes the first element / node.
        void addLast(WHLocation* loc); //Adds the input WHLocation to the queue (Creates a new node and appends it to the queue using the WHLocation pointer as data)
        void print() const; // Prints every WHLocation info that is within the queue


    private:
        class Node { // Private Nested Node Class From the List Class
            public:
                WHLocation* data;
                Node*    next;
        };
        Node* head; // Node pointer to the first node in the queue
        Node* tail; // Node pointer to the last node in the queue
};


#endif

