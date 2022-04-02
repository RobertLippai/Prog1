/*
	g++ find.cpp -std=c++11 -o find.out && ./find.out
*/

#include <iostream>
#include <vector>

template<typename Iterator, typename T>
Iterator my_find (Iterator first, Iterator last, const T& val){

	while (first != last && *first != val) ++first;

	return first; 
}

int main(){

	std::vector<int> v;
	int a;
	int x = 10;
	
	while (std::cin >> a) v.push_back(a);
	
	auto p = my_find(v.begin(), v.end(), x);
	
	if (p != v.end())
		std::cout << "We have found it!" << std::endl;
	else
		std::cout << "We can't find it!" << std::endl;

	for (auto e : v)
		std::cout << e << std::endl;

	return 0;
}