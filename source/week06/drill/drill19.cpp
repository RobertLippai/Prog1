/*
	g++ drill19.cpp -o drill19.out -std=c++14 && ./drill19.out
*/

#include "../../gui/std_lib_facilities.h"

template<typename T> struct S { 
	explicit S(T value) : val{value} {}

	T& get();
	const T& get() const;

	//Task 9
	
	void set(T new_value) {
		val = new_value;
	}
	
	//Task 10
	S<T> operator=(const T& new_value){
		val = new_value;
		return *this;
	}

private:
	T val;
};

template<typename T>
T& S<T>::get() {
	return val;
}

template<typename T>
const T& S<T>::get() const {
	return val;
}

template<typename T>
void read_val(T& v) {
	T input;
	cin >> input;

	if(cin.fail()){
		error("Unsupported input!");
	}

	v = input;
}

template<typename T>
ostream& operator<<( ostream& os, vector<T>& vec){
	os << '{';

	for(int i = 0; i < vec.size(); ++i){
		if(i != 0){
			os << "," ;
		}
		os << " " << vec.at(i);
		i++;
	}

	os << " }\n";

	return os;
}
 
template<typename T>
istream& operator>>(istream& in, vector<T>& vec){
	cout << "Input values in the following format {value, value, value}" << endl;

	if(!in){
		return in;
	}

	char ch = -1;

	in >> ch;

	if(ch != '{'){
		error("Invalid format!");
		return in;
	}

	for (T input; in >> input;)
	{
		vec.push_back(input);

		in >> ch;

		if(ch != ','){
			break;
		}
	}

	return in;
}

int main()
try {

	//Task 3
	S<int> int_S(10);
	S<char> char_S('R');
	S<double> double_S(1.3);
	S<string> string_S("Hello World!");
	S<vector<int>> vector_S(vector<int>{10,20,30,40,50});

	//Task 4
	/*
	cout << "Task 4: " << endl;
	cout << "int_S: " << int_S.val << endl;
	cout << "char_S: " << char_S.val << endl;
	cout << "double_S: " << double_S.val << endl;
	cout << "string_S: " << string_S.val << endl;

	cout << "vector_S: ";

	for(auto& element : vector_S.val){
		cout << element << " ";
	}
	cout << endl;
	*/

	//Task 9 Test
	/*
	int_S.set(99);
	char_S.set('D');
	double_S.set(2.9);
	string_S.set("Goodbye!");
	vector_S.set(vector<int>{90,80,70,60});
	*/

	//Task 10 Test
	/*
	int_S = 77;
	char_S = 'C';
	double_S = 9.9;
	string_S = "HI!";
	vector_S = vector<int>{45,90,180,360};
	*/

	//Task 8

	cout << "Task 8: " << endl;
	cout << "int_S: " << int_S.get() << endl;
	cout << "char_S: " << char_S.get() << endl;
	cout << "double_S: " << double_S.get() << endl;
	cout << "string_S: " << string_S.get() << endl;

	cout << "vector_S: ";

	for(auto& element : vector_S.get()){
		cout << element << " ";
	}
	cout << endl;

	//Task 13

	cout << "Task 13: " << endl;

	int int_val;
	char char_val;
	double double_val;
	string string_val;

	cout << "Please enter a whole number: ";
	read_val(int_val);
	int_S = int_val;
	cout << "Good, you have entered: " << int_S.get() << endl;

	cout << "Please enter a single letter: ";
	read_val(char_val);
	char_S = char_val;
	cout << "Good, you have entered: " << char_S.get() << endl;

	cout << "Please enter a decimal number: ";
	read_val(double_val);
	double_S = double_val;
	cout << "Good, you have entered: " << double_S.get() << endl;

	cout << "Please enter any text: ";
	read_val(string_val);
	string_S = string_val;
	cout << "Good, you have entered: " << string_S.get() << endl;

	//Task 14
	vector<int> vector_val;

	read_val(vector_val);
	vector_S = vector_val;

	cout << "Good, you have entered: ";
	for(auto& element : vector_val){
		cout << element << " ";
	}
	cout << endl;

	return 0;

} catch (runtime_error& e) {
	cerr << "Error: " << e.what() << '\n';
	return 1;
} catch (...){
	cerr << "Something went wrong.\n";
	return 2;
}