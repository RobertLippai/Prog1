/*
	g++ drill24.cpp -o drill24.out -std=c++11 && ./drill24.out 
*/

#include <iostream>
#include "include/Matrix.h"
#include "include/MatrixIO.h"
#include <math.h>
#include <complex>
#include <errno.h>

using namespace Numeric_lib;

void task4(){
	// only works on linux
	errno = 0;
	
	std::cout << "Please enter numbers to calculate square root. " << std::endl;
	std::cout << "Enter any character to exit." << std::endl;

	for(double input; std::cin >> input;){
		auto result = sqrt(input);
		
		// errno doesn't seem to work on macos
		if(errno || input < 0){
			std::cout << "No Square Root!" << std::endl;
			//std::cout << "Errno info: " << errno << std::endl;
			errno = 0;
			continue;
		}

		std::cout << result << std::endl;
	}
	
	std::cin.clear();
	std::cin.ignore();
	
}

void task5(){
	std::cout << "Please enter 10 floating-point number: " << std::endl;

	Matrix<double> double_matrix(10);

	for (int i = 0; i < 10; ++i)
	{
		std::cin >> double_matrix[i];
	}

	std::cout << double_matrix << std::endl;

	std::cin.clear();
	std::cin.ignore();
}

void task6(){
	std::cout << "Enter 2 numbers to generate an n*m matrix. (Use spaces between the numbers.) " << std::endl;

	int n, m;

	std::cin >> n >> m;	
	std::cout << std::endl;

	Matrix<int, 2> multiplication_table(n, m);

	for (int i = 0; i < multiplication_table.dim1(); ++i)
	{
		for (int j = 0; j < multiplication_table.dim2(); ++j)
		{
			if(j == 0 && i == 0){
				multiplication_table(i, j) = 0;
				continue;
			}
			if(j == 0){
				multiplication_table(i, j) = (i) * (j+1);
				continue;
			}
			if(i == 0){
				multiplication_table(i, j) = (i+1) * (j);
				continue;
			}

			multiplication_table(i, j) = (i) * (j);
			
			//multiplication_table(i, j) = (i+1) * (j+1);
		}
	}

	std::cin.clear();
	std::cin.ignore();


	for (int i = 0; i < multiplication_table.dim1(); ++i){
	
		for (int j = 0; j < multiplication_table.dim2(); ++j){
			std::cout << multiplication_table(i,j) << '\t';
		}
		
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
}

void task7(){
	std::cout << "Enter 10 complex numbers\nFormat (real,imag): " << std::endl;

	Matrix<std::complex<double>> complex_matrix (10);

	for (int i = 0; i < 10; ++i)
	{
		std::cin >> complex_matrix[i];
	}
	
	std::cout << std::endl;
	
	std::complex<double> sum;

	for (int i = 0; i < complex_matrix.dim1(); ++i)
	{
		sum += complex_matrix[i];
	}
	
	std::cout << "Complex matrix sum\nReal part: " << sum.real() << "\tImaginary part: " << sum.imag() << std::endl;

	std::cout << std::endl;
	
	std::cin.clear();
	std::cin.ignore();
}

void task8(){
	std::cout << "Please enter 6 whole numbers: " << std::endl;

	Matrix<int, 2> int_matrix (2,3);

	for (int i = 0; i < int_matrix.dim1(); ++i)
	{
		for (int j = 0; j < int_matrix.dim2(); ++j)
		{
			std::cin >> int_matrix(i,j);
		}
	}

	std::cout << "Printing matrix: " << int_matrix << std::endl;
}


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
	std::cout << "Printing the size of double*: " << sizeof(double*) << std::endl;
	
	std::cout << std::endl << std::endl;

	// Task 2
	std::cout << "Task 2" << std::endl;

	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int,3> e(10,10,10);
	
	// sizeof in memory
	
	std::cout << "The size of Matrix a (sizeof): " << sizeof(a) << std::endl;
	std::cout << "The size of Matrix b (sizeof): " << sizeof(b) << std::endl;
	std::cout << "The size of Matrix c (sizeof): " << sizeof(c) << std::endl;
	std::cout << "The size of Matrix d (sizeof): " << sizeof(d) << std::endl;
	std::cout << "The size of Matrix e (sizeof): " << sizeof(e) << std::endl;	

	std::cout << std::endl << std::endl;

	// Task 3
	std::cout << "Task 3" << std::endl;
	
	std::cout << "The number of elements in Matrix a: " << a.size() << std::endl;
	std::cout << "The number of elements in Matrix b: " << b.size() << std::endl;
	std::cout << "The number of elements in Matrix c: " << c.size() << std::endl;
	std::cout << "The number of elements in Matrix d: " << d.size() << std::endl;
	std::cout << "The number of elements in Matrix e: " << e.size() << std::endl;	


	// Task 4
	std::cout << "Task 4" << std::endl;
	
	task4();

	// Task 5
	std::cout << "Task 5" << std::endl;
	
	task5();

	// Task 6

	std::cout << "Task 6" << std::endl;
	
	task6();

	// Task 7
	std::cout << "Task 7" << std::endl;
	
	task7();

	// Task 8

	std::cout << "Task 8 " << std::endl;
	
	task8();

	return 0;
}
