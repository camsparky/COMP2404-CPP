
#include "Store.h"

Store::Store(const string& name) : name(name), products(new List){}
Store::~Store(){delete products;}

void Store::findAvailableSLoc(StoreLocation** sloc){ //Finds the first empty store location (in storeLocations) and assigns it to the output parameter
    for(int i=0; i<SLOCS; i++){
        if (storeLocations[i].isAvailable()){
            *sloc = &storeLocations[i];
            break; //Making sure to exit the loop as we no longer need any of the other possible store locations
        }
    }
}

void Store::findAvailableWHLoc(WHLocation** wloc){ //Finds the first empty warehouse location (in whLocations) and assigns it to the output parameter
    for(int i=0; i<WHLOCS; i++){
        if(whLocations[i].isAvailable()){
            *wloc = &whLocations[i];
            break; //Making sure to exit the loop as we no longer need any of the other possible warehouse locations
        }
    }
}

void Store::findProduct(const string& name, Product** prod){products->findProduct(name,prod);}

void Store::printStoreStock() const{
    for(int i=0; i<SLOCS; i++){
        if(storeLocations[i].isAvailable()==false){
            storeLocations[i].print();
        }
    }
}

void Store::printWareHouseStock() const{
    for(int i=0; i<WHLOCS; i++){
        if(whLocations[i].isEmpty()==false){
            whLocations[i].print();
        }
    }
}

void Store::printProducts() const{
    products->print();
}

void Store::receiveProduct(const string& pname, int quantity){
    Product* prod = NULL;
    cout<<"Receiving..."<<endl;
    products->findProduct(pname, &prod);
    if (prod==NULL){
        cout<<"Making new product"<<endl;
        StoreLocation* sloc;
        findAvailableSLoc(&sloc);
        prod = new Product(pname, sloc);
        products->add(prod);
        
    }


    WHLocation* bloc;
    while(quantity > 0){
        findAvailableWHLoc(&bloc);
        if (quantity > bloc->getCapacity()){
            bloc->add(pname, bloc->getCapacity());
            prod->addWHLocation(bloc);
            quantity -= bloc->getCapacity();
        }else{
            bloc->add(pname, quantity);
            prod->addWHLocation(bloc);
            quantity = 0;
        }
    }

    cout<<"stocking store location..."<<endl;
    prod->stockStoreLocation();

}

void Store::fillOrder(const string& product, int& quantity){
    Product* prod;
    findProduct(product, &prod);
    if (prod == NULL){
        return;
    }
    prod->fillOrder(quantity);
}


void Store::print() const{
    cout<<"Store: "<<name<<endl;
}