/*
	gcc drill27.c -o drill27.out && ./drill27.out
*/

#include <stdio.h>

void print_out(char * p, int x){
	printf("p is %s and x is %i\n", p, x);
}

int main(){

	// Task 1
	
	printf("Hello World!\n");

	// Task 2

	char* v1 = "Hello";
	char* v2 = "World!";

	printf("%s %s\n", v1, v2);

	// Task 3

	print_out("Tom", 27);
	print_out("Jerry", 9);
	print_out("Eva", 26);

	return 0;
}