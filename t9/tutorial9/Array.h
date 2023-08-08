
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T> //Templating the array class
class Array {
	template <class B>
	friend ostream& operator<<(ostream&, Array<B>&); //Essentially just the overloaded operator from the given examples just with the parameters replaced

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		void add(const T&);
		int getSize() const;
		bool isFull() const;
		T& operator[](int) const; //Essentially functions same as the get() function that was replaced just with the [] operator and works with a templated type
	
	private:
		int size;
		T* elements;
	
};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
}

template <class T>
void Array<T>::add(const T& t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

template <class T>
int Array<T>::getSize() const{
	return size;
}

template <class T>
bool Array<T>::isFull() const{
	return size >= MAX_ARR;
}

template <class T>
T& Array<T>::operator[](int index) const //Essentially functions same as the get() function that was replaced just with the [] operator and works with a templated type
{
  if (index < 0 || index >=size){
    cout<< "ERROR: invalid index"<<endl;
    exit(1);
  }
  return elements[index];
}

template <class T>
ostream& operator<<(ostream& output, Array<T>& arr) //Essentially just the overloaded operator from the given examples just with the parameters replaced
{
  output << endl;

  for (int i=0; i<arr.size; ++i)
    output << arr.elements[i];

  output << endl;
  return output;
  
}

#endif