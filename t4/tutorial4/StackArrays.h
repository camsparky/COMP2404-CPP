#ifndef STACKARRAYS_H
#define STACKARRAYS_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Episode.h"

using namespace std;

class StackArrays {
    public:
        //Constructors / Destructors
        StackArrays();
        ~StackArrays();

        //Getters
        Episode* getObjectArray();
        Episode** getPointerArray();

    private:
        //Members
        Episode epObjs[ARR_SIZE];
        Episode* epPoin[ARR_SIZE];

};

#endif