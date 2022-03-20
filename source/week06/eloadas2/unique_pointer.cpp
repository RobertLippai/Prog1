/*
	g++ unique_pointer.cpp -o unique_pointer.out -std=c++11 && ./unique_pointer.out 
*/
#include "../../gui/std_lib_facilities.h"

void suspicious(int s, int x){
	int* p = new int[s];

	delete[] p;
}

int main()
try	{

	suspicious(5, 1);

	return 0;
} catch (std::exception& e) {
	std::cerr << e.what() << std::endl;
	return -1;
}