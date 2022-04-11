/*
	g++ chapter24.cpp -o chapter24.out -std=c++11 && ./chapter24.out 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list> 
#include <array> 
#include <iomanip>      // std::setprecision

using namespace std;
int main(){
	
/*	float x = 1.0/333;
	float sum = 0;
	for (int i = 0; i < 333; ++i)
	{
		sum += x;
	}

	cout << setprecision(15) << sum << "\n";
	
	//

	short int y = 40000;
	int i = 1000000;
	cout<<y<<" "<<i*i<<"\n";*/

	//
/*	cout << "sizes: " << sizeof(int) << ' ' << sizeof(float) << '\n'; int x = 2100000009; // large int
	float f = x;
	cout << x << ' ' << f << '\n';
	cout << setprecision(15) << x << ' ' << f << '\n';*/


/*	float f = 2.8;
	int x = f;
	cout << x << ' ' << f << '\n';*/


	cout << "number of bytes in an int: " << sizeof(int) << '\n';
	cout << "largest int: " << INT_MAX << '\n';
	cout << "smallest int value: " << numeric_limits<int>::min() << '\n';

	if (numeric_limits<char>::is_signed) cout << "char is signed\n";
	else
	cout << "char is unsigned\n";

	char ch = numeric_limits<char>::min(); // smallest positive value 
	cout << "the char with the smallest positive value: " << ch << '\n'; 
	cout << "the int value of the char with the smallest positive value: " << int(ch) << '\n';

	return 0;
}