#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 1024

void encrypt(char * str);

int main(int argc, char const *argv[])
{
	char plaintext[] = "z";

	int i = 0;

	printf("%s\n", plaintext);

	encrypt(plaintext);


	return 0;
}

void encrypt(char * str) {

	int i = 0;
	char *ptr = str;
	char ciphertext[MAXSIZE];

	while(*ptr)
	{
		tolower(*ptr);

		ciphertext[i] = (*ptr + (char)1);

		i++;
		ptr++;
	}
	ciphertext[i++] = '\0';

	puts(ciphertext);
}
