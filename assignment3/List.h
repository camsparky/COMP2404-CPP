#ifndef LIST_H
#define LIST_H

#include "Product.h"

class List{ //Essentially just the List class from the notes 

    //private by default
    class Node {

        public:
            Product* data;
            Node*    next;
    };

    public:
        List();
        
        // Any data left in the List gets destroyed
        ~List();
        //we have unlimited size, so add always succeeds
        void add(Product*);
        //return false if name not found
        void findProduct(const string& name, Product** prod); //Just replaced the name of the base List "get" function with "findProduct" as they do the same thing
        //double pointer for a return parameter of a pointer
        void remove(const string& name, Product**);
        void removeUpTo(const string& name);
        bool isEmpty() const;
        void print() const;

    private:
        Node* head;

};

#endif

