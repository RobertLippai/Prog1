/*
	g++ array.cpp -o array.out -std=c++11 && ./array.out 
*/

#include "../../gui/std_lib_facilities.h"

//template function
template<typename C>
void printout(const C& c){
	cout << "Outputing: ";
	for (int i = 0; i < c.size(); ++i)
	{
		cout << c[i] << " ";
	}
	cout << endl;
}

template<typename T, int N> 
struct my_array {
	T elem[N];

	T& operator[](int n) { return elem[n]; }
	const T& operator[](int n) const { return elem[n]; }

	int size() const { return N; }
};

int main(){
	
	my_array<int, 2> int_array = {10, 100};
	my_array<double, 5> double_array = {0.1, 0.2, 0.3, 0.4, 0.5};

	cout << "Int array: ";
	for (int i = 0; i < int_array.size(); ++i)
	{
		cout << int_array[i] << " ";
	}
	cout << endl;

	cout << "Double array: ";
	for (int i = 0; i < double_array.size(); ++i)
	{
		cout << double_array[i] << " ";
	}
	cout << endl;

	printout(int_array);
	printout(double_array);

	vector<int> iv = {10,20,30,40,50,60};

	printout(iv);

	return 0;
}