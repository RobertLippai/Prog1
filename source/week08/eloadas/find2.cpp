/*
	g++ find2.cpp -std=c++11 -o find2.out && ./find2.out
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

bool odd(int x){
	return x % 2; //true if odd, false if even
}

int main(){

	std::vector<int> v;
	int a;
	
	while (std::cin >> a) v.push_back(a);
	
	auto p = my_find(v.begin(), v.end(), odd);
	
	if (p != v.end())
		std::cout << "We have found it!" << std::endl;
	else
		std::cout << "We can't find it!" << std::endl;

	for (auto e : v)
		std::cout << e << std::endl;

	return 0;
}