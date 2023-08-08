#include "StackArrays.h"

//Constructors / Destructors
StackArrays::StackArrays(){
    for(int x=0; x<ARR_SIZE; x++){
        epPoin[x] = new Episode;
    }
}

StackArrays::~StackArrays(){
    for(int x=0; x<ARR_SIZE; x++){
        delete epPoin[x];
    }
}

//Getters
Episode* StackArrays::getObjectArray(){return epObjs;}
Episode** StackArrays::getPointerArray(){return epPoin;}

