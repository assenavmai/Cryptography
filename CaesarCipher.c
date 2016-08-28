#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 1024

void encrypt(char * str, int shift);

int main(int argc, char const *argv[])
{
	char plaintext[] = "attack at dawn";

	int i = 0;

	printf("%s\n", plaintext);

	encrypt(plaintext, 5);


	return 0;
}

void encrypt(char * str, int shift) {

	int i = 0;
	int diff = 0;
	int alphaStart = 97;
	char *ptr = str;
	char ciphertext[MAXSIZE];

	while(*ptr)
	{
		tolower(*ptr);

		if(*ptr == ' ')
			ciphertext[i] = *ptr;
		else
			ciphertext[i] = (*ptr + (char)shift);

		if(ciphertext[i] > 122)
		{
			diff = ciphertext[i] - 122 - 1;
			printf("%d\n", diff);
			ciphertext[i]  = (char)alphaStart + (char)diff;
		}

		i++;
		ptr++;
	}
	ciphertext[i++] = '\0';

	puts(ciphertext);
}
