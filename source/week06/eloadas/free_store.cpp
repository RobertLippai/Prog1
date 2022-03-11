/*
	g++ free_store.cpp -o free_store.out -std=c++11 && ./free_store.out 
*/


#include "../../gui/std_lib_facilities.h"

int main(){
	
	double* a = new double(0); //initialization
	//new operator = free store

	cout << a << " " << *a << endl;

	int size = 0;

	cin >> size;

	double* b = new double[size];

	for (int i = 0; i < 10; ++i)
	{
		b[i] = i*i;
	}

	cout << b[5] << endl;

	//delete a;
	//delete[] b; // ha new-al foglalunk deletel felkell szabatítani
	
	return 0;
}