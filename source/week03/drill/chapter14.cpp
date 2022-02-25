/*
g++ chapter14.cpp -o chapter14.out -std=c++11 && ./chapter14.out
*/

#include "../../gui/std_lib_facilities.h"


//Task 1
class B1{
public:
	virtual void vf() const{
		cout << "B1::vf()\n";
	};

	void f() const{
		cout << "B1::f()\n"; 
	};

	//Task 5
	virtual void pvf() const = 0;

	
};

struct D1 : B1 {
	void vf() const override {
		cout << "D1::vf()\n";	
	}

	void f() const {
		cout << "D1::f()\n";	
	}

	void pvf() const override {
		cout << "D1::pvf()\n";	
	}
};

struct D2: D1{

	void pvf() const override {
		cout << "D2::pvf()\n";	
	}
};

class B2 {
public:
	virtual void pvf() = 0;
};

struct D21 : B2{
	string s = "teszt";

	void pvf() override {
		cout << "D21:" + s + "\n";
	};
};

struct D22 : B2{
	int i = 0;

	void pvf() override {
		cout << "D22:" + to_string(i) + "\n";
	};
};

void f(B2& arg) {
	arg.pvf();
}

int main(){

	//Task 1
	/*cout << "Calling B1 Obj\n";

	B1 b1_obj = B1();

	b1_obj.vf();
	b1_obj.f();*/

	//Task 2

	cout <<"\nCalling D1 Obj\n";

	D1 d1_obj = D1();

	d1_obj.vf();
	d1_obj.f();
	d1_obj.pvf();

	//Task 3

	cout <<"\nCalling B1 Ref\n";

	B1& b1_ref = d1_obj;

	b1_ref.vf();
	b1_ref.f();
	b1_ref.pvf();

	//Task 6

	cout <<"\nCalling D2 Obj\n";

	D2 d2_obj = D2();

	d2_obj.vf();
	d2_obj.f();
	d2_obj.pvf();
	
	//Task 7

	cout <<"\nCalling B2 Obj\n";
	D21 d21_obj = D21();
	D22 d22_obj = D22();

	f(d21_obj);
	f(d22_obj);



	return 0;
}
