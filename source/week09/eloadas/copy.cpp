/*
	g++ copy.cpp -std=c++11 -o copy.out && ./copy.out
*/

#include <vector>
#include <list>
#include <iostream>

template<typename Iterator, typename Out>
// convention: return by the output iterator
Out my_copy(Iterator first, Iterator last, Out res){
	while(first != last){
		*res = *first;
		res++;
		first++;
	}
	return res;
}

int main(){

	std::vector<double> v(10);

	std::list<int> l = { 1, 2, 3, 4, 5};


	if(v.size() < l.size()){
		std::cout << "v is smaller than l" << std::endl;
		return 1;
	}

	//intervalum + destination
	my_copy(l.begin(), l.end(), v.begin());

	for(const auto& elem : v){
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	return 0;
}