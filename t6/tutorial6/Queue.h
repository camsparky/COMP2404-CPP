#ifndef QUEUE_H
#define QUEUE_H

#include "Student.h"
using namespace std;

class Queue{

    public:
        //Constructor / Destructor
        Queue();
        ~Queue();

        //Other Functions
        bool isEmpty(); //returns true if the queue is empty, false otherwise.
        void peekFirst(Student** stu); //Stores the first element of the queue within the "stu" output parameter.
        void popFirst(Student** stu); //Stores the first element of the queue within the "stu" output parameter. However also removes and deletes the first element / node.
        void addLast(Student* stu); //Adds the input student to the queue (Creates a new node and appends it to the queue using the student pointer as data)
        void print(); // Prints every students info that is within the queue


    private:
        class Node { // Private Nested Node Class From the List Class
            public:
                Student* data;
                Node*    next;
        };
        Node* head; // Node pointer to the first node in the queue
        Node* tail; // Node pointer to the last node in the queue
};


#endif

