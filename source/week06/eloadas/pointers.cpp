/*
	g++ pointers.cpp -o pointers.out -std=c++11 && ./pointers.out 
*/

#include "../../gui/std_lib_facilities.h"

int main(){
	
	int var = 17;
	int* iptr = &var; //int pointer

	cout << "Pointer: " << iptr << endl;
	cout << "Pointer value: " << *iptr << endl;
	cout << endl;

	int x = 42;
	int* pi = &x;

	cout << "Pointer: " << pi << endl;
	cout << "Pointer value: " << *pi << endl;
	cout << endl;

	double e = 2.71828;
	double* dptr = &e;

	cout << "Pointer: " << dptr << endl;
	cout << "Pointer value: " << *dptr << endl;

	cout << endl;

	*pi = 44;

	cout << "Pointer: " << pi << endl;
	cout << "Pointer value: " << *pi << endl;
	cout << endl;

	cout << "Size of char: " << sizeof(char*) << " bytes." << endl;
	return 0;
}