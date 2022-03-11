/*
	g++ vector_003.cpp -o vector_003.out -std=c++11 -Wall -fno-elide-constructors && ./vector_003.out 
*/

#include "../../gui/std_lib_facilities.h"

class My_vector {

	int sz; // the size of the vector
	double* elem; // the elements

	void debug(const string& str){
		cerr << this << "->" << str << " elem ptr: " << elem << endl;
	}

public:
	explicit My_vector(int s): sz(s), elem{new double[s]}{
		for (int i = 0; i < s; ++i)
		{
			elem[i] = 0;
		}

		debug("int constructor");
	}

	My_vector(initializer_list<double> lst): sz(lst.size()), elem{new double[sz]}{
		copy(lst.begin(), lst.end(), elem);

		debug("lst constructor");
	}

	My_vector(const My_vector& arg): sz{arg.sz}, elem{ new double[sz]}{
		copy(arg.elem, arg.elem+arg.sz, elem);
		// first element, last element, new place
		debug("copy constructor");
	}

	My_vector& operator=(const My_vector& arg){
		double* p = new double[arg.sz];
		copy(arg.elem, arg.elem+arg.sz, p);

		delete[] elem;
		elem = p;
		sz = arg.sz;

		debug("copy assigment");

		return *this;
	}

	My_vector(My_vector&& arg) : sz{arg.sz}, elem{arg.elem}{ //move constructor
		arg.sz = 0;
		arg.elem = nullptr;
		debug("move constructor");
	} 

	My_vector& operator=(My_vector&& arg){ //move assigment
		delete[] elem;
		sz = arg.sz;
		elem = arg.elem;
		arg.sz = 0;
		arg.elem = nullptr;

		debug("move assigment");
		return *this;
	} 

	int size() const { return sz; }
	double get(int i) const { return elem[i]; }
	void set(int i, double val) { elem[i] = val; }

	double& operator[](int n){ return elem[n]; }
	//const double& operator[] const (int n){ return elem[n]; }

	//destructor
	~My_vector(){ debug("destructor"); delete[] elem; }

};

My_vector fill(){
	My_vector t {10, 5.4, 6, 6.9, 10};

	return t;
}

My_vector glob(10);

int main(){
	My_vector mv {89, 9.7, 9, 6.7, 66};

	cout << "MV: ";
	for (int i = 0; i < mv.size(); ++i)
	{
		cout << mv.get(i) << " ";
	}
	cout << endl << endl;


	My_vector mv2 (mv);

	cout << "MV2: ";
	for (int i = 0; i < mv2.size(); ++i)
	{
		cout << mv2.get(i) << " ";
	}
	cout << endl << endl;


	My_vector mv3 {87, 1.7, 0.9, 687, 32};

	mv3 = mv;

	cout << "MV3: ";
	for (int i = 0; i < mv3.size(); ++i)
	{
		cout << mv3.get(i) << " ";
	}
	cout << endl << endl;



	My_vector mv4 = fill();

	cout << "MV4: ";
	for (int i = 0; i < mv4.size(); ++i)
	{
		cout << mv4.get(i) << " ";
	}
	cout << endl << endl;


	My_vector mv5 {10, 1.3, 9.9, 97, 30};
	mv5 = fill();

	cout << "MV5: ";
	for (int i = 0; i < mv5.size(); ++i)
	{
		cout << mv5.get(i) << " ";
	}
	cout << endl << endl;

	return 0;
}