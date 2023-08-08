#include "HeapArrays.h"

//Constructors / Destructors
HeapArrays::HeapArrays(){
    epObjs = new Episode[ARR_SIZE];
    epPoin = new Episode*[ARR_SIZE];
    for(int x=0; x<ARR_SIZE; x++){
        epPoin[x] = new Episode;
    }
}

HeapArrays::~HeapArrays(){
    delete [] epObjs;
    for(int x=0; x<ARR_SIZE; x++){
        delete epPoin[x];
    }
    delete [] epPoin;
}

//Getters
Episode* HeapArrays::getObjectArray(){return epObjs;}
Episode** HeapArrays::getPointerArray(){return epPoin;}

