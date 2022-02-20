/*
	g++ drill14.cpp -std=c++11 -o drill14.out && ./drill14.out
*/

#include "../../gui/std_lib_facilities.h"

//Task 1
class B1 {
public:
	virtual void vf() const {
		std::cout << "B1:vf()\n";
	}

	void f() const {
		std::cout << "B1:f()\n";
	}


};

//Task 2
struct D1: B1{
	void vf() const override {
		std::cout << "D1:vf()\n";
	}

	//Task 4
	void f() const {
		std::cout << "D1:f()\n";
	}
};

int main()
{

	//Task 1
	B1 b1_obj = B1();

	b1_obj.vf();
	b1_obj.f();

	//Task 2
	D1 d1_obj = D1();

	d1_obj.vf();
	d1_obj.f();

	//Task 3
	B1& reference = d1_obj;

	reference.vf();
	reference.f();

	return 0;
}


/*

5. Add a pure virtual function called pvf() to B1 and try to repeat 1–4. Ex-
plain the result.

6. Define a class D2 derived from D1 and override pvf() in D2. Make an
object of class D2 and invoke f(), vf(), and pvf() for it.

7. Define a class B2 with a pure virtual function pvf(). Define a class D21
with a string data member and a member function that overrides pvf(); D21::pvf() should output the value of the string. Define a class D22 that is just like D21 except that its data member is an int. Define a function f() that takes a B2& argument and calls pvf() for its argument. Call f() with a D21 and a D22.


*/