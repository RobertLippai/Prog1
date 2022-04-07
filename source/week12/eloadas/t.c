/*
	gcc t.c -o t.out && ./t.out < titkos.txt 
*/

#define MAX_ENCRYPTED 4096
#define READ_BUFFER 256
#define KEY_SIZE 8
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>

double atlagos_szohossz(const char encrypted[], int encrypted_meret){

	int sz = 0;

	for (int i = 0; i < encrypted_meret; i++)
		if (encrypted[i] == ' ')
			++sz;

	return (double) encrypted_meret / sz;

}

int tiszta_lehet (const char encrypted[], int encrypted_meret){

	double szohossz = atlagos_szohossz(encrypted, encrypted_meret);

	return szohossz < 9.0 && szohossz > 6.0 &&
		strcasestr (encrypted, "nem") && strcasestr (encrypted, "hogy") &&
		strcasestr (encrypted, "az") && strcasestr (encrypted, "Ha");

}

void exor (const char key[], int key_meret, 
	char encrypted[], int tikos_meret){

	int key_index = 0;

	for (int i = 0; i < tikos_meret; i++){
		encrypted[i] = encrypted[i] ^ key[key_index];
		key_index = (key_index + 1) % key_meret;
	}
}

int exor_tores(const char key[], int key_meret, 
	char encrypted[], int encrypted_meret){

	exor (key, key_meret, encrypted, encrypted_meret);

	return tiszta_lehet (encrypted, encrypted_meret);

}

int main(){

	char key[KEY_SIZE];
	char encrypted[MAX_ENCRYPTED];
	char *p = encrypted;
	int olvasott_bajtok;

	while ((olvasott_bajtok = 
		read ( 0, (void*) p, 
		(p - encrypted + READ_BUFFER <
		MAX_ENCRYPTED) ? READ_BUFFER : encrypted + MAX_ENCRYPTED - p )))

	p += olvasott_bajtok;

	for (int i = 0; i < MAX_ENCRYPTED - (p - encrypted); ++i)
		encrypted[p - encrypted + i] = '\0';

	for (int ii = '0'; ii <= '9'; ++ii)
		for (int ji = '0'; ji <= '9'; ++ji)
			for (int ki = '0'; ki <= '9'; ++ki)
				for (int li = '0'; li <= '9'; ++li)
					for (int mi = '0'; mi <= '9'; ++mi) 
						for (int ni = '0'; ni <= '9'; ++ni)
							for (int oi = '0'; oi <= '9'; ++oi)
								for (int pi = '0'; pi <= '9'; ++pi){
									key[0] = ii;
									key[1] = ji;
									key[2] = ki;
									key[3] = li;
									key[4] = mi;
									key[5] = ni;
									key[6] = oi;
									key[7] = pi;

					if (exor_tores(key, KEY_SIZE, encrypted, p - encrypted))
						printf(
							"key: [%c%c%c%c%c%c%c%c]\nTiszta szöveg: [%s\n]",
							ii, ji, ki, li, mi, ni, oi, pi, encrypted);

					exor (key, KEY_SIZE, encrypted, p - encrypted);

				}

	return 0;
}