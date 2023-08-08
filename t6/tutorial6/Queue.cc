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

bool Queue::isEmpty(){ //returns true if the queue is empty, false otherwise.
    if(head == NULL){ // Queue is empty if the head points to nothing
        return true;
    }
    else{
        return false;
    }
}

void Queue::peekFirst(Student** stu){ //Stores the first element of the queue within the "stu" output parameter.
    if(isEmpty()){ //Making sure the queue is not empty before storing the first element within the output parameter.
        *stu = NULL;
    }
    else{
        *stu = head->data;
    }
}

void Queue::popFirst(Student** stu){ //Stores the first element of the queue within the "stu" output parameter. However also removes and deletes the first element / node.
    if(isEmpty()){ // Making sure the queue is not empty before popping
        *stu = NULL;
    }
    else{
        Node* temp;
        *stu = head->data;
        temp = head->next;
        delete head;
        head = temp;
        if(head == NULL){ // Just being extra careful and making sure to reset the tail pointer if the queue is empty.
            tail = NULL;
        }
    }
}

void Queue::addLast(Student* stu){ //Adds the input student to the queue (Creates a new node and appends it to the queue using the student pointer as data)
    Node* newNode = new Node();
    newNode->data = stu;
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

void Queue::print(){ // Prints every students info that is within the queue
    Node* temp = head;
    while(temp != NULL){ //Iterating through each node in the queue
        temp->data->print();
        temp = temp->next;
    }
}