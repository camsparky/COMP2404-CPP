
#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Product.h"
#include "List.h"
#include "defs.h"


using namespace std;

class Store {
		
	public:
		//constructor
		Store(const string& name);
		
		//destructor
		~Store();

		//other
		void findAvailableSLoc(StoreLocation**); //Finds the first empty store location (in storeLocations) and assigns it to the output parameter
		void findAvailableWHLoc(WHLocation**); //Finds the first empty warehouse location (in whLocations) and assigns it to the output parameter

		void printStoreStock() const; 
		void printWareHouseStock() const;
		void printProducts() const;

		//these are done for you
		void findProduct(const string&, Product**); //Calls the List class findProduct function
		void receiveProduct(const string&, int quantity);
		void fillOrder(const string&, int &quantity);
		void print() const;
	
	private:
		string name;
		StoreLocation storeLocations[SLOCS];
		WHLocation whLocations[WHLOCS];
		List* products;
	
};
#endif