/*
	g++ find5.cpp -std=c++11 -o find5.out && ./find5.out
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
/*
class Larger_than {
	int v; // compare to this

public:
	Larger_than(int vv) : v {vv} {}
	bool operator()(int x) const { return x > v; } // function call operator, gets called in find
};
*/

int main(){

	std::vector<int> v;
	int a;
	int x = 42;
	
	while (std::cin >> a) v.push_back(a);
	
	auto p = my_find(v.begin(), v.end(), 
		[&](int e) { return e > x; }); //[&] sensitivity list 
		//& means every local variable will be given to the lambda function by reference.
	
	if (p != v.end())
		std::cout << "We have found it!" << std::endl;
	else
		std::cout << "We can't find it!" << std::endl;

	/*for (auto e : v)
		std::cout << e << std::endl;
	
	*/

	return 0;
}