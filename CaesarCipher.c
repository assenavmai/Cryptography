#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 1024

void encrypt(char * str, int key);
void decrypt(char * str, int key);


int main(int argc, char const *argv[])
{
	char input[5];
	char keystr[100];
	char plaintext[MAXSIZE];
	char ciphertext[MAXSIZE];
	int key = 0;

	int i = 0;
	do
	{
		printf("Enter (e)ncrption (d)ecryption or (q)uit: ");
		fgets(input, 5, stdin);
		input[strlen(input) - 1] = '\0';

		if(strcmp(input, "e") == 0)
		{
			printf("Enter your plaintext: ");
			fgets(plaintext, MAXSIZE, stdin);

			printf("Enter the key: ");
			fgets(keystr, 100, stdin);

			key = atoi(keystr);
			encrypt(plaintext, key);
		}
		else if(strcmp(input, "d") == 0)
		{
			printf("Enter your ciphertext: ");
			fgets(ciphertext, MAXSIZE, stdin);
			decrypt(ciphertext, key);
		}
	}while(strcmp(input, "q") != 0);


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
