/*
	g++ comp.cpp -std=c++11 -o comp.out && ./comp.out
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

struct Record
{
	std::string name;
	std::string address;
};

struct Compare_by_name{
	bool operator()(const Record& a, const Record& b) const {
		return a.name < b.name; //std::string operator < 
	}
};

struct Compare_by_adress{
	bool operator()(const Record& a, const Record& b) const {
		return a.address < b.address; //std::string operator < 
	}
};

int main(){

	std::vector<Record> vr;

	for(std::string a,b; std::cin >> a >> b && (a != "q" || b != "q");){
		Record first;
		first.name = a;
		first.address = b;

		vr.push_back(first);
	}

	std::cout << "Before sort:" << std::endl;
	for(const auto& element : vr){
		std::cout << element.name << " " << element.address << std::endl;
	}
	std::cout << std::endl;

	std::sort(vr.begin(), vr.end(), Compare_by_name());

	std::cout << "After sort by name:" << std::endl;
	for(const auto& element : vr){
		std::cout << element.name << " " << element.address << std::endl;
	}
	std::cout << std::endl;

	std::sort(vr.begin(), vr.end(), Compare_by_adress());

	std::cout << "After sort by address:" << std::endl;
	for(const auto& element : vr){
		std::cout << element.name << " " << element.address << std::endl;
	}
	std::cout << std::endl;

	return 0;
}