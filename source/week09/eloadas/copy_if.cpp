/*
	g++ copy_if.cpp -std=c++11 -o copy_if.out && ./copy_if.out
*/

#include <vector>
#include <list>
#include <iostream>

template<typename Iterator, typename Out, typename Pred>
// convention: return by the output iterator
Out my_copy(Iterator first, Iterator last, Out res, Pred pred){
	while(first != last){

		if(pred(*first)){
			*res = *first;
			res++;	
		}

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

	// intervalum + destination
	my_copy(l.begin(), l.end(), v.begin(), [](int x) -> bool { return x > 3; });
	// lamdba expression -> bool we only need to use it if we can't tell the return type by looking
	// at it

	for(const auto& elem : v){
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	return 0;
}