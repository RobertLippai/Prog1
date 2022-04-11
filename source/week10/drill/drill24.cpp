/*
	g++ drill24.cpp -o drill24.out -std=c++11 && ./drill24.out 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list> 
#include <array> 
#include "include/Matrix.h"
#include "include/MatrixIO.h"
#include <math.h>
#include <complex>
#include <errno.h>

using namespace Numeric_lib;
using Numeric_lib::Index;

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


	std::cout << "Printing the size of Matrix a (sizeof): " << sizeof(a) << std::endl;
	std::cout << "Printing the size of Matrix b (sizeof): " << sizeof(b) << std::endl;
	std::cout << "Printing the size of Matrix c (sizeof): " << sizeof(c) << std::endl;
	std::cout << "Printing the size of Matrix d (sizeof): " << sizeof(d) << std::endl;
	std::cout << "Printing the size of Matrix e (sizeof): " << sizeof(e) << std::endl;	

	std::cout << std::endl << std::endl;

	// Task 3

	std::cout << "Printing the size of Matrix a: " << a.size() << std::endl;
	std::cout << "Printing the size of Matrix b: " << b.size() << std::endl;
	std::cout << "Printing the size of Matrix c: " << c.size() << std::endl;
	std::cout << "Printing the size of Matrix d: " << d.size() << std::endl;
	std::cout << "Printing the size of Matrix e: " << e.size() << std::endl;	

	// Task 4
	std::cout << "Task 4: " << std::endl;
	std::cout << "Please enter ints." << std::endl;

	for(double input; std::cin >> input;){

		if(input < 0){
			std::cout << "No Square Root!" << std::endl;
		} else {
			std::cout << sqrt(input) << std::endl;
		}
	}


	std::cin.clear();
	std::cin.ignore();

	// Task 5
	std::cout << "Task 5: " << std::endl;
	std::cout << "Please enter 10 non-whole numbers." << std::endl;

	Matrix<double> task5_m(10);

	for (int i = 0; i < 10; ++i)
	{
		std::cin >> task5_m[i];
	}

	std::cout << task5_m << std::endl;

	std::cin.clear();
	std::cin.ignore();

	// Task 6

	std::cout << "Task 6: " << std::endl;
	std::cout << "Please enter 2 numbers to represent an n*m matrix. (Use spcaes to separet them.)" << std::endl;

	int n, m;

	std::cin >> n >> m;

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
			

			//multiplication_table(i,j) = i == 0 || j == 0 ? i + j : i * j;
		}
	}

	std::cin.clear();
	std::cin.ignore();


	for(int i = 0; i < multiplication_table.dim1(); ++i){
		for(int j = 0; j < multiplication_table.dim2(); ++j)
			std::cout << multiplication_table(i,j) << '\t';
		std::cout << '\n';
	}

	// Task 7
	std::cout << "Task 7: " << std::endl;
	std::cout << "Please enter 10 complex numbers " << std::endl;

	Matrix<std::complex<double>> complex_matrix (10);

	std::complex<double> temp_c;

	for (int i = 0; i < 10; ++i)
	{
		std::cin >> temp_c;
		complex_matrix[i] = temp_c;
	}

	std::complex<double> sum;

	for (Index i = 0; i < complex_matrix.dim1(); ++i)
	{
		sum += complex_matrix[i];
	}
	std::cout << "Sum of the complex matrix: " << sum << std::endl;


	std::cin.clear();
	std::cin.ignore();

	// Task 8

	std::cout << "Task 8: " << std::endl;
	std::cout << "Please enter 6 ints " << std::endl;

	Matrix<int, 2> task8_matrix (2,3);

	for (int i = 0; i < task8_matrix.dim1(); ++i)
	{
		for (int j = 0; j < task8_matrix.dim2(); ++j)
		{
			int temp;
			std::cin >> temp;
			task8_matrix(i,j) = temp;
		}
	}

	std::cout << "Outputing matrix: " << task8_matrix << std::endl;

	return 0;
}