/*
	g++ drill21_map.cpp -o drill21_map.out -std=c++11 && ./drill21_map.out 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list> 
#include <array> 
#include <map>
#include <numeric>

template<typename T, typename T2>
void print(const std::map<T,T2>& m){
	for(const auto& element : m){
		std::cout << "Key: " << element.first << "\tValue: " << element.second << std::endl;
	}
	std::cout << std::endl;
}

// Task 5
template<typename T, typename T2>
void readin(std::map<T, T2>& m, int n){
	int read = 0;
	T temp1;
	T2 temp2;

	while(read < n){
		std::cin >> temp1 >> temp2;
		auto pair = std::make_pair(temp1, temp2);
		m.insert(pair);
		read++;
	}

}

int calculate(int sum, const std::pair<std::string,int>& a){
	return sum += a.second;
}

int main(){
	
	// Task 1

	std::map<std::string,int> msi;

	// Task 2

	msi["lecture"]= 21;
	msi["day"]= 30;
	msi["month"]= 3;
	msi["price"]= 25;
	msi["quantity"]= 11;
	msi["sun"]= 10;
	msi["moon"]= 98;
	msi["easter"]= 2;
	msi["car"]= 32;
	msi["bike"]= 2122;
	
	// Task 3

	std::cout << "Task 3" << std::endl;
	std::cout << "MSI elements: " << std::endl;
	print(msi);

	// Task 4

	std::cout << "Task 4" << std::endl;
	msi.erase(std::begin(msi), std::end(msi));

	std::cout << "Map Size: " << msi.size() << std::endl;

	// Task 6-7
	readin(msi, 10);

	std::cout << "Map after readin(): " << std::endl;

	print(msi);

	// Task 8

	auto sum = std::accumulate(std::begin(msi), std::end(msi), 0, calculate);

	std::cout << "Sum of the ints in MSI: " << sum << std::endl;

	// Task 9-10-11

	std::map<int, std::string> mis;

	for(const auto& element : msi){
		mis.insert(std::make_pair(element.second, element.first));
	}

	std::cout << "MIS elements: " << std::endl;
	print(mis);

	return 0;
}