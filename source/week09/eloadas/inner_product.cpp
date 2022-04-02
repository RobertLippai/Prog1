/*
	g++ inner_product.cpp -std=c++11 -o inner_product.out && ./inner_product.out
*/

#include <vector>
#include <list>
#include <iostream>

template <typename Iterator1, typename Iterator2, typename T>
T inner_product (Iterator1 first, Iterator1 last, Iterator2 first2, T init){
	while( first != last){
		init = init + ((*first) * (*first2));
		++first;
		++first2;
	}

	return init;
}

int main(){

	// 2 vector
	// multiply their pairs and sum them

	std::vector<double> dow_price = { 81.86, 34.69, 54.45 };
	std::list<double> dow_weight = { 5.8549, 2.4808, 3.894 };

	double dji_index = inner_product(
		dow_price.begin(), dow_price.end(),
		dow_weight.begin(),
		0.0);

	std::cout << "DJI index: " << dji_index << std::endl;

	return 0;
}