#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 1024

void encrypt(char * str, int key);
void decrypt(char * str, int key);


int main(int argc, char const *argv[])
{
	char plaintext[] = "attack at dawn";
	char ciphertext[] = "fyyfhp fy ifbs";

	int i = 0;

	encrypt(plaintext, 5);
	decrypt(ciphertext,5);


	return 0;
}

void encrypt(char * str, int key) {

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
			ciphertext[i] = (*ptr + (char)key);

		if(ciphertext[i] > 122)
		{
			diff = ciphertext[i] - 122 - 1;
			ciphertext[i]  = (char)alphaStart + (char)diff;
		}

		i++;
		ptr++;
	}
	ciphertext[i++] = '\0';

	printf("%s\n", ciphertext);
}

void decrypt(char * str, int key)
{
	int i = 0;
	int alphaStart = 122;
	int diff = 0;
	char *ptr = str;
	char plaintext[MAXSIZE];

	while(*ptr)
	{
		tolower(*ptr);

		if(*ptr == ' ')
		{
			plaintext[i] = *ptr;
		}
		else
			plaintext[i] = (*ptr - (char)key);

		if(plaintext[i] < 97 && plaintext[i] != 32)
		{
			diff = 97 - plaintext[i] - 1;
			plaintext[i] = (char)alphaStart - (char)diff;
		}
		i++;
		ptr++;
	}

	plaintext[i++] = '\0';

	printf("%s\n", plaintext);
}
