#ifndef HEAPARRAYS_H
#define HEAPARRAYS_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Episode.h"

using namespace std;

class HeapArrays {
    public:
        //Constructors / Destructors
        HeapArrays();
        ~HeapArrays();

        //Getters
        Episode* getObjectArray();
        Episode** getPointerArray();

    private:
        //Members
        Episode* epObjs;
        Episode** epPoin;

};

#endif