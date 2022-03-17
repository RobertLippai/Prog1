/*
	g++ drill15_class.cpp -o drill15_class.out -std=c++11 && ./drill15_class.out

*/

#include "../../gui/std_lib_facilities.h"

bool has_only_digits(const string s){
  return s.find_first_not_of( "0123456789" ) == string::npos;
}

struct Person {
public:
	//Default
	Person() : first_name{"Guest"}, second_name{"Human"}, age{1} {};

	Person(string f_name, string s_name, int age) : first_name{f_name}, second_name{s_name}, age{age} {
		if(first_name.empty() || second_name.empty()){
			error("You must provide a first and a last name too!\n");
		}
		if(age == -1){
			error("You must provide an age too!");
		}

		const string illegal_chars = ";:\"'[]*&^%$#@!";
		
		string names = first_name + second_name;
		
		for (int i = 0; i < names.size(); ++i)
		{
			if(string(illegal_chars).find(names[i]) != string::npos){
				error("The name can not contain any of the following characters:\n" + illegal_chars + "\n");
			}
	    }

	    if (age <= 0 || age >= 150){
			error("The age has to be between 0 and 150!");
		}

	};

	int get_age() const { return age; }

	string get_name() const { return first_name + " " + second_name; }

private:
	string first_name;
	string second_name;
	int age;
};

//Task 3
ostream& operator<<( ostream& os, Person& person){
	return os << "Full name: " << person.get_name() << "\tAge: " << person.get_age() << endl;
}
 
//Task 3
istream& operator>>(istream& in, Person& p){
	string first_name, second_name;
	int age;

	in >> first_name >> second_name >> age;

	if(!in){
		return in;
	}

	p = Person(first_name, second_name, age);
	return in;
}

Person& operator>>(string& s, Person& p){
	istringstream stream_string(s);

	string input;

	string first_name, second_name;
	int age = -1;

	int arg_counter = 0;

	while(getline(stream_string, input, ' ')){
		/*
		0 -> First Name
		1 -> Second Name
		2 -> Age
		Anything else -> Gets dropped
		
		*/

		if(has_only_digits(input)) { age = stoi(input); } 
		else {
			switch(arg_counter){
				case 0:
					first_name = input;
					break;
				case 1:
					second_name = input;
					break;
				/*case 2:
					age = stoi(input);
					break;*/
				default:
					//Drop unecessary info instead of error
					break;
					//error("Too many details given!");
				}
				arg_counter++;
			}

	}

	//cout << "Debug info: " << first_name << " " << second_name << " " << age << endl;

	return p = Person(first_name, second_name, age);
}


int main()
try {

	//Task 2
	cout << "Task 2" << endl;

	Person person_one = Person{"Goofy", "Human", 63};

	cout << person_one;
	cout << endl;

	//Task 3
	cout << "Task 3" << endl;

	Person person_two;

	cout << "Please enter a first name, last name and an age, all separeted by spaces!" << endl;

	cin >> person_two;

	cout << "\nYou have entered the following details:" << endl;
	cout << person_two << endl;



	//Task 8
	cout << "Task 8" << endl;

	vector<Person> persons;

	Person placeholder = Person();
	string input;

	cout << "From now on, we are storing the names." << endl;
	cout << "Please enter a first name, last name and an age, all separeted by spaces! \n(Type exit to stop recording new names!)" << endl;

	while(getline(cin, input)){
		if(input == "exit"){
			break;
		}

		if(input.empty()){
			continue;
		}

		try
		{
			input >> placeholder;
		} 
		catch (runtime_error& e) {
			cerr << "Error: " << e.what() << '\n';
			continue;
		}
		catch(...) {
			cout << "\nMake sure to enter the details in the following format: First Name, Last Name, Age\t all separeted by spaces!" << endl;
			continue;
		}

		persons.push_back(placeholder);

		cout << "\n\nGood, you can enter another name! \n(Type exit to stop recording new names!)" << endl;
	}

	cout << '\n';

	cout << "You have entered the following persons:\n";

	for (int i = 0; i < persons.size(); ++i)
	{
		cout << "[" + to_string(i+1) + "] " << persons[i] << endl;
	}

	return 0;

} catch (runtime_error& e) {
	cerr << "Error: " << e.what() << '\n';
	return 1;
} catch (...){
	cerr << "Something went wrong.\n";
	return 2;
}