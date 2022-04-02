/*
	g++ modulo3.cpp -std=c++11 -o modulo3.out && ./modulo3.out
*/

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

template<typename T, typename K>
void print_modulo(const T& v, std::ostream& os, const K& m){

	auto Modulo_print = [&os, m] (int x) { if ( x % m == 0) os << x << '\n'; };

	std::for_each(v.begin(), v.end(), Modulo_print);
}

int main(){
	int m = 20; // mod 20

	std::vector<int> v = { 10, 20, 30, 40, 50 };
	print_modulo(v, std::cout, m);
	std::cout << std::endl;

	std::list<int> l = { 10, 20, 30, 40, 50 };
	print_modulo(l, std::cout, m);
	std::cout << std::endl;
	return 0;
}