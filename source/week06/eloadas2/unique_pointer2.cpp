/*
	g++ unique_pointer2.cpp -o unique_pointer2.out -std=c++11 && ./unique_pointer2.out 
*/

#include "../../gui/std_lib_facilities.h"

vector<int>* suspicious(){
	vector<int>* si = new vector<int>;

	for (int i; std::cin>>i;)
	{
		if(i) si->push_back(i);
		else throw std::exception();
	}

	return si;
}

int main()
try	{

	vector<int>* vi = suspicious();

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