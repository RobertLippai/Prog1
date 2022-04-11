/*
	g++ drill24.cpp -o drill24.out -std=c++11 && ./drill24.out 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list> 
#include <array> 
#include "include/Matrix.h"

using namespace Numeric_lib;

int main(){
	
	// Task 1
	std::cout << "Task 1" << std::endl;

	std::cout << "Printing the size of char: " << sizeof(char) << std::endl;
	std::cout << "Printing the size of short: " << sizeof(short) << std::endl;
	std::cout << "Printing the size of int: " << sizeof(int) << std::endl;
	std::cout << "Printing the size of long: " << sizeof(long) << std::endl;
	std::cout << "Printing the size of float: " << sizeof(float) << std::endl;
	std::cout << "Printing the size of double: " << sizeof(double) << std::endl;
	std::cout << "Printing the size of int*: " << sizeof(int*) << std::endl;
	
	std::cout << std::endl << std::endl;

	// Task 2
	std::cout << "Task 2" << std::endl;

	Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);


	std::cout << "Printing the size of Matrix a: " << sizeof(a) << std::endl;
	std::cout << "Printing the size of Matrix b: " << sizeof(b) << std::endl;
	std::cout << "Printing the size of Matrix c: " << sizeof(c) << std::endl;
	std::cout << "Printing the size of Matrix d: " << sizeof(d) << std::endl;
	std::cout << "Printing the size of Matrix e: " << sizeof(e) << std::endl;	

	std::cout << std::endl << std::endl;

	return 0;
}

/*

1. Print the size of a char, a short, an int, a long, a float, a double, an int*, 
and a double* (use sizeof, not <limits>).

2. Print out the size as reported by sizeof of Matrix<int> a(10), 
Matrix<int> b(100), Matrix<double> c(10), Matrix<int,2> d(10,10), Matrix<int,3> e(10,10,10).

*/
