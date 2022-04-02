/*
	g++ drill20.cpp -o drill20.out -std=c++11 && ./drill20.out 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list> 
#include <array> 

using namespace std;

template<typename Iterator>
Iterator printout(Iterator first, Iterator last){
	while(first != last){
		cout << *first;
		++first;
		if(first != (last)){
			cout << ", ";
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
		cout << "Contains at position: " << position << endl;
	} else { cout << "Doesn't contain" << std::endl; }

}

int main(){

	//Task 1,2,3
	int s[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> int_vec;
	list<int> list_vec;

	for(auto& e : s){
		int_vec.push_back(e);
		list_vec.push_back(e);
	}
	
	cout << "Printing first array: ";
	printout(std::begin(s), std::end(s));
	cout << endl;
	
	
	cout << "Printing first vector: ";
	printout(std::begin(int_vec), std::end(int_vec));
	cout << endl;
	
	cout << "Printing first list: ";
	printout(std::begin(list_vec), std::end(list_vec));
	cout << endl;


	//Task 4	
	int second_array[10];
	vector<int> second_vector = int_vec;
	list<int> second_list = list_vec;
	
	std::copy(std::begin(s), std::end(s), std::begin(second_array));
	//std::copy(std::begin(s), std::end(s), std::begin(second_vector));
	//std::copy(std::begin(s), std::end(s), std::begin(second_list));
	

	//Task 5
	cout << endl << "Task 5" << endl << endl;
	
	for(auto& e : second_array){
		e = e + 2;
	}
	for(auto& e : second_vector){
		e = e + 3;
	}
	for(auto& e : second_list){
		e = e + 5;
	}
	
	cout << "Printing second array after increasing: ";
	for(auto& e : second_array){
		cout << e << " ";
	}
	cout << endl;
	
	cout << "Printing second vector afzer increasing: ";
	printout(std::begin(second_vector), std::end(second_vector));
	cout << endl;
	
	cout << "Printing second list afzer increasing: ";
	printout(std::begin(second_list), std::end(second_list));
	cout << endl;
	
	
	//Task 7
	cout << "Task 7" << endl;
	
	my_copy(std::begin(second_array), std::end(second_array), std::begin(second_vector));
	my_copy(std::begin(second_list), std::end(second_list), std::begin(second_array));
	
	cout << "Printing Copied Second Vector: ";
	printout(std::begin(second_vector), std::end(second_vector));
	cout << endl;
	
	cout << "Printing Copid Second Array: ";
	printout(std::begin(second_array), std::end(second_array));
	cout << endl;
	
	//Task 8

	cout << "Task 8" << endl << endl;

	contains(std::begin(int_vec), std::end(int_vec), 3);
	contains(std::begin(list_vec), std::end(list_vec), 27);

	return 0;
}

/*

1. Define an array of int s with the ten elements { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.
2. Define a vector<int> with those ten elements.
3. Define a list<int> with those ten elements.
4. Define a second array, vector, and list, each initialized as a copy of the first
array, vector, and list, respectively.

5. Increase the value of each element in the array by 2; 
increase the value of each element in the vector by 3; 
increase the value of each element in the list by 5.
6. copy operator
7. Use your copy() to copy the array into the vector and to copy the list into
the array.
8. 8. Use the standard library find() to see if the vector contains the value 3
and print out its position if it does; 
use find() to see if the list contains the
value 27 and print out its position if it does. The “position” of the first
element is 0, the position of the second element is 1, etc. Note that if find()
returns the end of the sequence, the value wasn’t found.
*/
