/*
	g++ acc2.cpp -std=c++11 -o acc2.out && ./acc2.out
*/

#include <iostream>
#include <vector>


template<typename Iterator, typename T, typename BinOp>
T accumlate(Iterator first, Iterator last, T init, BinOp op){
	while(first != last){
		init = op(init, *first);
		++first;
	}

	return init;
}

//it doesn't matter if its typename or class
template<class T>
struct my_multiplies
{
	T operator()(const T& a, const T& v) const { return a * v; }
};

double multiply(double a, double v){
	return a * v;
}

int main(){

	std::vector<double> v { 1, 2, 3, 4, 5};

	std::cout << accumlate(v.begin(), v.end(), 1.0, multiply) << std::endl;
	std::cout << accumlate(v.begin(), v.end(), 1.0, my_multiplies<double>()) << std::endl;

	return 0;
}