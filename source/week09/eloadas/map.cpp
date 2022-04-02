/*
	g++ map.cpp -std=c++20 -o map.out && ./map.out < text.txt
*/

#include <map>
#include <iostream>


int main(){

	std::map<std::string, int> words;

	for(std::string s; std::cin >> s;){
		++words[s];
	}

	for(const auto& element : words){
		std::cout << element.first << ": " << element.second << std::endl;
	}

	std::cout << words["the"] << std::endl;

	return 0;
}