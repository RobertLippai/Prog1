/*
	g++ modulo4.cpp -std=c++20 -o modulo4.out && ./modulo4.out
*/

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>


int main(){
	int m = 20; // mod 20

	std::ostream& os = std::cout;

	auto Greater_print = [&os, m]<typename K>(K x) { if ( x > m ) os << x << '\n'; };


	std::vector<int> v = { 10, 20, 30, 40, 50 };
	std::list<double> l = { 10, 20, 30, 40, 50 };

	std::for_each(v.begin(), v.end(), Greater_print);
	std::cout << std::endl;
	std::for_each(l.begin(), l.end(), Greater_print);

	return 0;
}