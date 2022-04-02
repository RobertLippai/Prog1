/*
	g++ find3.cpp -std=c++11 -o find3.out && ./find3.out
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

bool larger_than_42(int x){
	return x > 42;
}

int main(){

	std::vector<int> v;
	int a;
	
	while (std::cin >> a) v.push_back(a);
	
	auto p = my_find(v.begin(), v.end(), larger_than_42);
	
	if (p != v.end())
		std::cout << "We have found it!" << std::endl;
	else
		std::cout << "We can't find it!" << std::endl;

	/*for (auto e : v)
		std::cout << e << std::endl;
	
	*/
	
	return 0;
}