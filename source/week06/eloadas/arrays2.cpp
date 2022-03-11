/*
	g++ arrays2.cpp -o arrays2.out -std=c++11 && ./arrays2.out 
*/
#include "../../gui/std_lib_facilities.h"

int length(char* str){
	int n = 0;
	while(str[n]) ++n;
	return n;
}

int main(){

	char ac[] = "Howdy\0";

	//c-style string karaktertömb
	//a c-style stringek végén van egy \0
	//amint a while elér a \0-hoz a while hamis lesz

	cout << "Length: " <<length(ac) << endl;

	return 0;
}