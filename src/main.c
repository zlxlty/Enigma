#include <stdio.h>
#include <stdlib.h>
#include "rotorgroup.h"
#include <ctype.h>
#define Max 10000 


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	printf("ENIGMA MACHINE\n\n");
	
	//assign value to different rotors
	int seq;
	printf("Enter the Sequence of the Rotor:");
	scanf("%d", &seq);
	printf("\n");

	//Get the key
	char* key = (char*) malloc (sizeof(char)*4);
	printf("Enter the Three-Character Key (XXX):");
	scanf("%s", key);
	strupr(key);
	char Tempkey[4]; 
	int i;
	for(i=0; i<4; i++)
		Tempkey[i] = key[i];
	printf("\n");
	
	//Get the plugboard
	char plugboard[13];
	printf("Enter the Plugboard (6 pairs of letters):");
	scanf("%s",plugboard);
	strupr(plugboard);
	printf("\n");
	
	//Print all the rotor
	Printsetting(seq);
		
	char letter;
	char plaintext[Max];
	char ciphertext[Max];
	int cnt=0;
	
	//choose to encrypt or decrypt
	char Mode;
	printf("Enter the Mode(E or D):");
	while(getchar()!='\n'); 
	scanf("%c", &Mode); 
	Mode = toupper(Mode);
	printf("\n");
	
	if( Mode=='E' )
	{
		
		//encrypt process
		while (letter!='-')
		{	
			printf("Plaintext:");
			while(getchar()!='\n'); 
			scanf("%c", &letter);
		
			//end with symbol '-'
			if (letter=='-')
			break;
			letter = toupper(letter);
			plaintext[cnt] = letter;
		
		
			letter = Plugboard(letter, plugboard);
			letter = Encrytion(letter, key, seq);
			letter = Plugboard(letter, plugboard);
		
		
			printf("Ciphertext:%c\n",letter);
		
			ciphertext[cnt] = letter;
			key = KeyRotation(key);
			cnt++;
			printf("\n");
		}
		printf("Plaintext is:%s\n",plaintext);
		printf("Ciphertext is:%s\n",ciphertext);
		
	}else if( Mode=='D' )
	{
		while(1)
		{
			for(i=0; i<4; i++)
			{
				key[i] = Tempkey[i];	
			}
			  
		
			printf("Ciphertext:");
			scanf("%s", ciphertext);
			int size = strlen(ciphertext);
			char ptext[Max] = {};
		
			int i;
			for (i = 0; i<size; i++)
			{
				ciphertext[i] = toupper(ciphertext[i]);
		
				ciphertext[i] = Plugboard(ciphertext[i], plugboard);
				ciphertext[i] = Encrytion(ciphertext[i], key, seq);
				ciphertext[i] = Plugboard(ciphertext[i], plugboard);
		
				ptext[i] = ciphertext[i];
				key = KeyRotation(key);
		  	}
		
		  	printf("Plaintext is:%s\n",ptext);
		  	
		}
		
	}else{
		printf("Mode error\n");
	}
	
	
	
	printf("\nOVER \n");
	
	
	
	free(key);
	
	system("pause");
	return 0;
	
	
	
}
	
	
	
	
	
	
	
