/*
	g++ arrays.cpp -o arrays.out -std=c++11 && ./arrays.out 
*/
#include "../../gui/std_lib_facilities.h"

int main(){
	double lad[100];

	lad[7] = 100;

	cout << lad[7] << endl << endl;

	for (int i = 0; i < 100; ++i)
	{
		lad[i] = i;
	}
	for (int i = 0; i < 100; ++i)
	{
		cout << "Value: " << lad[i] << ' ';
	}
	cout << endl << endl;

	double* p = &lad[10];

	cout << "Pointer P: " << *p << endl;

	cout << "Pointer P: " << p[20] << endl;

	return 0;
}