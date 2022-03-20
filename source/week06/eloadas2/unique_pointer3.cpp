/*
	g++ unique_pointer3.cpp -o unique_pointer3.out -std=c++14 && ./unique_pointer3.out 
*/

#include <vector>
#include <iostream>
#include <memory>

std::vector<int>* suspicious(){

	//std::unique_ptr<std::vector<int>> v { new std::vector<int>};
	//std::unique_ptr<std::vector<int>> v = std::make_unique<std::vector<int>>();
	auto v = std::make_unique<std::vector<int>>();

	for (int i; std::cin>>i;)
	{
		if(i) v->push_back(i);
		else throw std::exception(); //calls the local object desctructor
	}

	return v.release(); // release, az unique pointerből átadjuk a jogot. Az birtokolja aki akarja.
}

int main()
try	{

	std::vector<int>* vi = suspicious();

	for (int i = 0; i < vi->size(); ++i)
	{
		std::cout << vi->at(i) << std::endl;
	}

	delete vi;

	return 0;
} catch (std::exception& e) {
	std::cerr << "Error" << std::endl;
	return -1;
}