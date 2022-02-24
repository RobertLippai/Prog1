#include <iostream>

using namespace std;

class B
{
public:

	virtual void f() const { cout << "B::f\n"; print_message(8.5);}

	void g() const { cout << "B::g\n"; }

	void print_message(int a) const { cout << "Message: " << a << endl; }
	//TODO
};

struct D : B {
	void f() const override { cout << "D::f\n"; print_message(8.5); }
	void g() { cout << "D::g\n"; }

	void print_message(double a) const { cout << "Message: " << a << endl; }

};

struct DD: B {
	void f() { cout << "DD::f\n"; }
	void g() const { cout << "DD::g\n"; }
};


void call(const B& b){
	b.f();
	b.g();
}

int main(){

	B b;
	D d;
	DD dd;

	call(b);
	call(d);
	call(dd);

	cout << "Call end.\n";

	return 0;
}