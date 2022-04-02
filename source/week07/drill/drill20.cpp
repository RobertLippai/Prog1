/*
	g++ drill20.cpp -o drill20.out -std=c++11 && ./drill20.out 
*/

//#include "../../gui/std_lib_facilities.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include<list> 
#include<array> 

using namespace std;

template<typename T>
void printout(T& data){
	for(auto& e : data){
		cout << e << " ";
	}
}

// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
template<typename Iter1, typename Iter2>
Iter2 copy_own(Iter1 f1, Iter1 e1, Iter2 f2){
/*
that copies [f1,e1) to [f2,f2+(e1–f1)) and returns f2+(e1–f1) just like the
standard library copy function. Note that if f1==e1 the sequence is empty,
so that there is nothing to copy.
*/
	if(f1==e1){
		//if empty
		return f2;
	}

	
	for (Iter1 p = f1; p != e1; ++p)
	{
		*f2 = *p;
		f2++;
		//f2.begin()+(e1-f1) = p;
		//cout << *p << " ";
	}
	return f2;
}

int main(){

	//Task 1,2,3
	
	//int s[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	array<int, 10> s = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> int_vec;
	list<int> list_vec;

	
	for(auto& e : s){
		int_vec.push_back(e);
		list_vec.push_back(e);
	}
	
	cout << "Printing: s ";
	printout(s);
	cout << endl;
	
	
	cout << "Printing: int_vec ";
	printout(int_vec);
	cout << endl;
	
	cout << "Printing: list_vec ";
	printout(list_vec);
	cout << endl;
	//Task 4
	int size_of_s = sizeof(s)/sizeof(s[0]);
	
	//int second_array[size_of_s];
	array<int, 10> second_array;
	
	std::copy(s.begin(), s.end(), second_array.begin());
	
	vector<int> second_vector = int_vec;
	list<int> second_list = list_vec;
	
	//Task 5
	cout << "Task 5" << endl << endl;
	
	for(auto& e : second_array){
		e = e + 2;
	}
	for(auto& e : second_vector){
		e = e + 3;
	}
	for(auto& e : second_list){
		e = e + 5;
	}
	
	cout << "Printing: s ";
	for(auto& e : second_array){
		cout << e << " ";
	}
	cout << endl;
	
	cout << "Printing: int_vec ";
	printout(second_vector);
	cout << endl;
	
	cout << "Printing: list_vec ";
	printout(second_list);
	cout << endl;
	
	
	//Task 7
	cout << "Task 7" << endl;
	
	copy_own(second_array.begin(), second_array.end(), second_vector.begin());
	copy_own(second_list.begin(), second_list.end(), second_array.begin());
	
	cout << "Printing Copied Second Array: ";
	printout(second_array);
	cout << endl;
	
	cout << "Printing Copid Second List: ";
	printout(second_list);
	cout << endl;
	
	//Task 8
	
	/*auto result = find(int_vec.begin(), int_vec.end(), 3);
	
	if( result ==  std::end(int_vec)){
		cout << "Can't find it" << endl;
	}	else { cout << " Result: " << result; }*/
	
	int n2 = 2;
	
	auto result3 = std::find(begin(int_vec), end(int_vec), n2);
 
    	(result3 != std::end(int_vec))
        ? std::cout << "v contains " << n2 << '\n'
        : std::cout << "v does not contain " << n2 << '\n';
 
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
