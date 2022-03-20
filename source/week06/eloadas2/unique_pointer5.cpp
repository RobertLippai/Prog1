/*
	g++ unique_pointer5.cpp -o unique_pointer5.out -std=c++14 && ./unique_pointer5.out 
*/

#include <vector>
#include <iostream>
#include <memory>

std::vector<int> suspicious(){

	//std::unique_ptr<std::vector<int>> v { new std::vector<int>};
	//std::unique_ptr<std::vector<int>> v = std::make_unique<std::vector<int>>();
	std::vector<int> v;

	for (int i; std::cin>>i;)
	{
		if(i) v.push_back(i);
		else throw std::exception(); //calls the local object desctructor
	}

	return v; // release, az unique pointerből átadjuk a jogot. Az birtokolja aki akarja.
}

int main()
try	{

	//std::unique_ptr<std::vector<int>> vi = suspicious();
	auto vi = suspicious();

	for (int i = 0; i < vi.size(); ++i)
	{
		std::cout << vi.at(i) << std::endl;
	}

	return 0;
} catch (std::exception& e) {
	std::cerr << "Error" << std::endl;
	return -1;
}