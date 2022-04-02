/*
	g++ set.cpp -std=c++20 -o set.out && ./set.out
*/

#include <set>
#include <iostream>

struct Fruit{
	std::string name;
	int count;
	double unit_price;
};

struct Fruit_order{
	bool operator()(const Fruit& a, const Fruit& b){
		return a.name > b.name;
	}
};

std::ostream& operator<<(std::ostream& os, const Fruit& f){
	os << f.name << " price: " << f.unit_price << " count: " << f.count;
	return os;
}

int main(){

	std::set<Fruit, Fruit_order> fruits;

	fruits.insert(Fruit{"apple", 5, 2.5});
	fruits.insert(Fruit{"watermelon", 2, 8.2});
	fruits.insert(Fruit{"peach", 10, 5.5});

	for(const auto& fruit : fruits){
		std::cout << fruit << std::endl;
	}

	return 0;
}