/*
	g++ find4.cpp -std=c++11 -o find4.out && ./find4.out
*/

#include <iostream>
#include <vector>

template<typename Iterator, typename Predicate>
Iterator my_find (Iterator first, Iterator last, Predicate pred){

	while (first != last && !pred(*first)){
		++first;
	} 

	return first; 
}

class Larger_than {
	int v; // compare to this

public:
	Larger_than(int vv) : v {vv} {}
	bool operator()(int x) const { return x > v; } // function call operator, gets called in find
};

int main(){

	std::vector<int> v;
	int a, x = 42;
	
	while (std::cin >> a) v.push_back(a);
	
	auto p = my_find(v.begin(), v.end(), Larger_than(x));
	
	if (p != v.end())
		std::cout << "We have found it!" << std::endl;
	else
		std::cout << "We can't find it!" << std::endl;

	/*for (auto e : v)
		std::cout << e << std::endl;
	
	*/

	return 0;
}