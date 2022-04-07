/*
		g++ drill21_vector.cpp -o drill21_vector.out -std=c++11 && ./drill21_vector.out 
*/
		
#include <iostream>
#include <vector>
#include <algorithm>
#include <list> 
#include <array> 
#include <fstream>

struct Item {
	std::string name;
	int id;
	double value;

	Item(std::string n, int i, double v) : name{n}, id{i}, value{v} {}

	
};

bool compare_by_name(const Item& a, const Item& b) {
	return a.name < b.name;
}

bool compare_by_id(const Item& a, const Item& b) {
	return a.id < b.id;
}

bool compare_by_value(const Item& a, const Item& b) {
	return a.value < b.value;
}

bool compare_by_value_decreasing(const Item& a, const Item& b) {
	return a.value > b.value;
}


struct Compare_by_name{
	std::string name;

	Compare_by_name(std::string n) : name{n} {}
	bool operator()(const Item& x) const {
		return x.name == name;
	}
};

struct Compare_by_id{
	int id;

	Compare_by_id(int i) : id{i} {}

	bool operator()(const Item& x) const {
		return x.id == id;
	}
};

template<typename Iterator>
void printout(Iterator first, Iterator last){
	while(first != last){
		auto element = *first;

		std::cout << element.name << " " << element.id << " " << element.value << std::endl;
		first++;
	}
	std::cout << std::endl;
}

int main(){
	
	// Task 1
	std::vector<Item> vi;
	std::list<Item> li;

	std::fstream fs("./text.txt");
	
	if(!fs){
		std::cout << "File not found" << std::endl;
		return 1;
	}
	
	//std::string temp;
	std::vector<std::string> temp{"","",""};
	//Item temp_item;
	int element_counter = 0;

	for(char ch; fs.get(ch);){ 
		if(ch == '\t' || ch == '\n'){
			element_counter++;

			if(element_counter == 3){
				element_counter = 0;
				vi.push_back(Item{temp[0], stoi(temp[1]), stod(temp[2])});
				li.push_back(Item{temp[0], stoi(temp[1]), stod(temp[2])});
				//std::cout << temp << std::endl;
				/*for(const auto& element : temp){
					std::cout << element;
				}*/
				//std::cout << std::endl;
				temp[0] = "";
				temp[1] = "";
				temp[2] = "";
				//break;
			}
			/*for(const auto& element : temp){
				std::cout << element;
			}*/
			//std::cout << temp << std::endl;
			if(ch=='\n'){continue;}
		}

		temp[element_counter] += ch;
	}


	fs.close();

	std::cout << "Vector after file read: " << std::endl << std::endl;
	printout(std::begin(vi), std::end(vi));

	// Task 2
	std::cout << "Vector after sorted by name: " << std::endl << std::endl;

	std::sort(std::begin(vi), std::end(vi), compare_by_name);

	printout(std::begin(vi), std::end(vi));

	// Task 3
	std::cout << "Vector after sorted by id: " << std::endl << std::endl;

	std::sort(std::begin(vi), std::end(vi), compare_by_id);

	printout(std::begin(vi), std::end(vi));


	// Task 4
	std::cout << "Vector after sorted by value (decreasing): " << std::endl << std::endl;

	std::sort(std::begin(vi), std::end(vi), compare_by_value_decreasing);

	printout(std::begin(vi), std::end(vi));


	// Task 5
	std::cout << "Printing out after added two new items " << std::endl << std::endl;

	vi.push_back(Item("horse shoe", 99, 12.34));
	vi.push_back(Item("Canon S400", 9988, 499.95));

	printout(std::begin(vi), std::end(vi));


	// Task 6-7

	/*
		list_name_delete1
	*/

	std::string vector_string_to_find_1 = "vase";
	std::string vector_string_to_find_2 = "rock";

	int vector_id_to_find_1 = 2032;
	int vector_id_to_find_2 = 534;

	auto vector_name_delete1 = std::find_if(std::begin(vi), std::end(vi), Compare_by_name(vector_string_to_find_1));
	auto vector_name_delete2 = std::find_if(std::begin(vi), std::end(vi), Compare_by_name(vector_string_to_find_2));
	auto vector_name_delete3 = std::find_if(std::begin(vi), std::end(vi), Compare_by_id(vector_id_to_find_1));
	auto vector_name_delete4 = std::find_if(std::begin(vi), std::end(vi), Compare_by_id(vector_id_to_find_2));

	auto vector_end = std::end(vi);

	if(vector_name_delete1 == vector_end || vector_name_delete2 == vector_end || 
		vector_name_delete3 == vector_end || vector_name_delete4 == vector_end){
		
		std::cerr << "Error" << std::endl;
		return -1; // error
	}

	vi.erase(vector_name_delete1);
	vi.erase(vector_name_delete2);
	vi.erase(vector_name_delete3);
	vi.erase(vector_name_delete4);

	std::cout << "Printing out after removing items " << std::endl << std::endl;
	printout(std::begin(vi), std::end(vi));

	// Repeating with list

	std::cout << "List after sorted by name: " << std::endl << std::endl;

	li.sort(compare_by_name);

	printout(std::begin(li), std::end(li));

	// Task 3
	std::cout << "List after sorted by id: " << std::endl << std::endl;

	li.sort(compare_by_id);

	printout(std::begin(vi), std::end(vi));


	// Task 4
	std::cout << "List after sorted by value (decreasing): " << std::endl << std::endl;

	li.sort(compare_by_value_decreasing);

	printout(std::begin(vi), std::end(vi));


	// Task 5
	std::cout << "List after added two new items: " << std::endl << std::endl;

	vi.push_back(Item("horse shoe", 99, 12.34));
	vi.push_back(Item("Canon S400", 9988, 499.95));

	printout(std::begin(vi), std::end(vi));

	// Task 6-7

	std::string list_string_to_find_1 = "chicken";
	std::string list_string_to_find_2 = "cup";

	int list_id_to_find_1 = 598;
	int list_id_to_find_2 = 457;

	auto list_name_delete1 = std::find_if(std::begin(li), std::end(li), Compare_by_name(list_string_to_find_1));
	auto list_name_delete2 = std::find_if(std::begin(li), std::end(li), Compare_by_name(list_string_to_find_2));
	auto list_id_delete1 = std::find_if(std::begin(li), std::end(li), Compare_by_id(list_id_to_find_1));
	auto list_id_delete2 = std::find_if(std::begin(li), std::end(li), Compare_by_id(list_id_to_find_2));

	auto list_end = std::end(li);

	if(list_name_delete1 == list_end || list_name_delete2 == list_end || 
		list_id_delete1 == list_end || list_id_delete2 == list_end){

		std::cerr << "Error" << std::endl;
		return -1; // error
	}

	li.erase(list_name_delete1);
	li.erase(list_name_delete2);
	li.erase(list_id_delete1);
	li.erase(list_id_delete2);

	std::cout << "Printing out after removing items " << std::endl << std::endl;
	printout(std::begin(li), std::end(li));

	return 0;
}
