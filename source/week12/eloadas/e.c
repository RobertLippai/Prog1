/*
	gcc e.c -o e.out && ./e.out 12345678 < teszt.txt > titkos.txt

	gcc e.c -o e.out && ./e.out 12345678 < titkos.txt 
*/

#include <string.h>
#include <unistd.h>

// the ley we use to encrypt has to fit in this size
#define MAX_KEY 100
#define BUFFER_SIZE 256 //2 56 byte

int main(int argc, char** argv){
	char key[MAX_KEY];
	char buffer[BUFFER_SIZE];

	int read_characters = 0;
	int key_index = 0;

	int key_size = strlen(argv[1]); // index 0 is the program name
	strncpy(key, argv[1], MAX_KEY);

	while((read_characters = read(0, (void*) buffer, BUFFER_SIZE))){
		for (int i = 0; i < read_characters; ++i)
		{
			buffer[i] = buffer[i] ^ key[key_index]; // ^ == XOR operator
			key_index = (key_index + 1) % key_size;
		}

		write(1, buffer, read_characters);

	}

	return 0;
}