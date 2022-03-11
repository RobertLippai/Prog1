/*
	g++ vector_001.cpp -o vector_001.out -std=c++11 && ./vector_001.out 
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

	int size() const { return sz; }
	double get(int i) const { return elem[i]; }
	void set(int i, double val) { elem[i] = val; }

	//destructor
	~My_vector(){ delete[] elem; }

};


int main(){
	
	My_vector mv {10, 5.4, 6, 6.9, 10};

	cout << "Size: " << mv.size() << endl;

	/*for (int i = 0; i < mv.size(); ++i)
	{
		mv.set(i, i*i);
	}*/

	for (int i = 0; i < mv.size(); ++i)
	{
		cout << mv.get(i) << " ";
	}

	cout << endl << endl;
	
	return 0;
}