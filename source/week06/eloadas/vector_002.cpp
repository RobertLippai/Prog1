/*
	g++ vector_002.cpp -o vector_002.out -std=c++11 && ./vector_002.out 
*/

#include "../../gui/std_lib_facilities.h"

class My_vector {

	int sz; // the size of the vector
	double* elem; // the elements

public:
	My_vector(int s): sz(s), elem{new double[s]}{
		for (int i = 0; i < s; ++i)
		{
			elem[i] = 0;
		}
	}

	My_vector(initializer_list<double> lst): sz(lst.size()), elem{new double[sz]}{
		copy(lst.begin(), lst.end(), elem);
	}

	My_vector(const My_vector& arg): sz{arg.sz}, elem{ new double[sz]}{
		for (int i = 0; i < sz; ++i)
		{
			copy(arg.elem, arg.elem+arg.sz, elem);
			// first element, last element, new place
		}
	}

	My_vector& operator=(const My_vector& arg){
		double* p = new double[arg.sz];
		copy(arg.elem, arg.elem+arg.sz, p);

		delete[] elem;
		elem = p;
		sz = arg.sz;

		return *this;
	}

	int size() const { return sz; }
	double get(int i) const { return elem[i]; }
	void set(int i, double val) { elem[i] = val; }

	//destructor
	~My_vector(){ delete[] elem; }

};


int main(){
	
	My_vector mv {10, 5.4, 6, 6.9, 10};

	cout << "Size: " << mv.size() << endl;

	cout << "MV: ";
	for (int i = 0; i < mv.size(); ++i)
	{
		cout << mv.get(i) << " ";
	}

	cout << endl << endl;

	My_vector mv2(mv); // copy constructor

	cout << "MV2: ";
	for (int i = 0; i < mv2.size(); ++i)
	{
		cout << mv2.get(i) << " ";
	}

	My_vector mv3 {6, 5.4, 6, 6.9, 10};

	cout << "MV3: ";
	for (int i = 0; i < mv3.size(); ++i)
	{
		cout << mv3.get(i) << " ";
	}

	mv3 = mv; // copy assigment

	cout << "MV3: ";
	for (int i = 0; i < mv3.size(); ++i)
	{
		cout << mv3.get(i) << " ";
	}
	return 0;
}