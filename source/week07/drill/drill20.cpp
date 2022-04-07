/*
	g++ drill20.cpp -o drill20.out -std=c++11 && ./drill20.out 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list> 
#include <array> 

template<typename Iterator>
Iterator printout(Iterator first, Iterator last){
	while(first != last){
		std::cout << *first;
		++first;
		if(first != (last)){
			std::cout << ", ";
		}
	}
	return first;
}


// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 first, Iter1 last, Iter2 first2){

	while(first != last){
		*first2 = *first;

		++first;
		++first2;
	}

	return first2;
}

template<typename Iterator, typename Value>
void contains(Iterator first, Iterator last, Value x){

	auto result = std::find(first, last, x);

	if(result != last){
		auto position = std::distance(first, result);
		std::cout << "Contains at position: " << position << std::endl;
	} else { std::cout << "Doesn't contain" << std::endl; }

}

int main(){

	//Task 1,2,3
	int s[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> int_vec;
	std::list<int> list_vec;

	for(auto& e : s){
		int_vec.push_back(e);
		list_vec.push_back(e);
	}
	
	std::cout << "Printing first array: ";
	printout(std::begin(s), std::end(s));
	std::cout << std::endl;
	
	
	std::cout << "Printing first vector: ";
	printout(std::begin(int_vec), std::end(int_vec));
	std::cout << std::endl;
	
	std::cout << "Printing first list: ";
	printout(std::begin(list_vec), std::end(list_vec));
	std::cout << std::endl << std::endl;


	//Task 4	
	int second_array[10];
	std::vector<int> second_vector = int_vec;
	std::list<int> second_list = list_vec;
	
	std::copy(std::begin(s), std::end(s), std::begin(second_array));
	//std::copy(std::begin(s), std::end(s), std::begin(second_vector));
	//std::copy(std::begin(s), std::end(s), std::begin(second_list));
	

	//Task 5
	std::cout << "Task 5" << std::endl;
	
	for(auto& e : second_array){
		e = e + 2;
	}
	for(auto& e : second_vector){
		e = e + 3;
	}
	for(auto& e : second_list){
		e = e + 5;
	}
	
	std::cout << "Printing second array after increasing: ";
	for(auto& e : second_array){
		std::cout << e << " ";
	}
	std::cout << std::endl;
	
	std::cout << "Printing second vector afzer increasing: ";
	printout(std::begin(second_vector), std::end(second_vector));
	std::cout << std::endl;
	
	std::cout << "Printing second list afzer increasing: ";
	printout(std::begin(second_list), std::end(second_list));
	std::cout << std::endl << std::endl;
	
	
	//Task 7
	std::cout << "Task 7" << std::endl;
	
	my_copy(std::begin(second_array), std::end(second_array), std::begin(second_vector));
	my_copy(std::begin(second_list), std::end(second_list), std::begin(second_array));
	
	std::cout << "Printing Copied Second Vector: ";
	printout(std::begin(second_vector), std::end(second_vector));
	std::cout << std::endl;
	
	std::cout << "Printing Copid Second Array: ";
	printout(std::begin(second_array), std::end(second_array));
	std::cout << std::endl << std::endl;
	
	//Task 8

	std::cout << "Task 8" << std::endl;

	contains(std::begin(int_vec), std::end(int_vec), 3);
	contains(std::begin(list_vec), std::end(list_vec), 27);

	return 0;
}