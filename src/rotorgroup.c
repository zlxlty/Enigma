#include <stdio.h>
#include <stdlib.h>
#include "setting.h"
#include "rotor.h"
#include "rotorgroup.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int ConnectRotor (pRotorhead* Alph_Rotor, pRotorhead* Ciph_Rotor, char Allet, char Cilet) 
{
	
	//create a pair of Rotors
//	pRotorhead* Alph_Rotor = CreateRotor(); 
//	pRotorhead* Ciph_Rotor = CreateRotor();
	pRotorhead* Tran_Alph = CreateRotor ();
	
	if (Alph_Rotor == NULL || Ciph_Rotor == NULL || Tran_Alph == NULL)
	{
		printf("error in mallocing place");
		return -1;
	}

	//assign value to different rotors
	int i=0; 
	for (i=0; i<26; i++)
	{
		Insert_Unit (Tran_Alph , Alpht[i]);
	}
		
	//initialize three rotors
	Unit* ptran = Find(Tran_Alph, Allet);
	Unit* pAlph = Alph_Rotor->down;
	Unit* pCiph = Ciph_Rotor->down;
	
	//对左右指针初始化部分 
	do
	{
		Unit* pdele = pAlph->right;
//		printf("hahah");
		pdele = NULL;
		pdele = pCiph->left;
		pdele = NULL;
		pAlph = pAlph->down;
		pCiph = pCiph->down;
	}while(pAlph != Alph_Rotor->down );
	
	pAlph = Alph_Rotor->down;
	pCiph = Ciph_Rotor->down;
	
//	printf("hahah");
	//connect Alph_rotor with transition rotor
	do
	{
		
		pAlph->right = ptran; 
		ptran->left  = pAlph;
		pAlph = pAlph->down;
		ptran = ptran->down;
		
	}while(pAlph != Alph_Rotor->down );
	
	//connnect Ciph_rotor with transition rotor
	ptran = Find(Tran_Alph, Cilet);
	
	do
	{
		
		pCiph->left = ptran;
		ptran->right = pCiph;
		pCiph = pCiph->down;
		ptran = ptran->down;
		
	}while(pCiph != Ciph_Rotor->down );
	
	//connect Alph_rotor with Ciph_rotor using transition rotor as a bridge
	pAlph = Alph_Rotor->down;
	pCiph = Ciph_Rotor->down;
	
	Unit* ptemp = pAlph->right;
	do
	{
		pAlph->right = ptemp->right;
		ptemp = ptemp->down;
		pAlph = pAlph->down;
		
	}while ( pAlph != Alph_Rotor->down );

	
	ptemp = pCiph->left;
	do
	{
		pCiph->left = ptemp->left;
		ptemp = ptemp->down;
		pCiph = pCiph->down;
	}while ( pCiph != Ciph_Rotor->down );
	

	Destroy(Tran_Alph);
	

	return 0;
}

void FillRotor ( pRotorhead* Ciph_Rotor, int num)
{
	int i;
	if (num==1)
	{
		
		for (i=0; i<26; i++)
		{
			Insert_Unit (Ciph_Rotor, RotorONE[i]);
		}
		
	}else if (num==2){
		
		for (i=0; i<26; i++)
		{
			Insert_Unit (Ciph_Rotor, RotorTWO[i]);
		}
		
	}else if (num==3){
		
		for (i=0; i<26; i++)
		{
			Insert_Unit (Ciph_Rotor, RotorTHREE[i]);
		}
	}else{
		
		printf("Sequence error\n");
	} 
		
}


char Plugboard (char letter, char* plugboard)
{
	
	int i;
	for (i=0; i<12; i++)
	{
		if (letter==plugboard[i])
		{
			if (i%2==0){
				letter=plugboard[i+1];
				break;
			}else if(i%2==1){
				letter=plugboard[i-1];
				break;
			}
		}
	}
	
	
	return letter;
}



char* KeyRotation (char* key)
{
	if(key[0]=='Z')
	{
		
		key[0]='A';
		if(key[1]=='Z')
		{
			
			key[1]='A';	
			if(key[2]=='Z')
			{
				key[2]='A';	
			}else
			{
				key[2]++;
			}
			
		}else
		{
			key[1]++;
		}
		
	}else{
		
		key[0]++;
	}
	
	return key;
	
}


char Encrytion (char dyletter, char* key, int seq)
{
	
	pRotorhead* Alph_RotorONE = CreateRotor(); 
	pRotorhead* Ciph_RotorONE = CreateRotor();
	
	pRotorhead* Alph_RotorTWO = CreateRotor(); 
	pRotorhead* Ciph_RotorTWO = CreateRotor();
	
	pRotorhead* Alph_RotorTHREE = CreateRotor(); 
	pRotorhead* Ciph_RotorTHREE = CreateRotor();

    pRotorhead* Alph_RotorFOUR = CreateRotor(); 
	pRotorhead* Ciph_RotorFOUR = CreateRotor();
	
	pRotorhead* Reflect_Rotor = CreateRotor(); 
	
	//assign value to different rotors
	
	FillRotor (Ciph_RotorONE, seq/100);
	seq = seq%100;
	FillRotor (Ciph_RotorTWO, seq/10);
	FillRotor (Ciph_RotorTHREE, seq%10);
	
	
	int i=0,j=0; 
	for (i=0; i<26; i++)
	{
 
		Insert_Unit (Alph_RotorONE, Alpht[i]);

		Insert_Unit (Alph_RotorTWO, Alpht[i]);
		
		Insert_Unit (Alph_RotorTHREE, Alpht[i]);
		
		Insert_Unit (Ciph_RotorFOUR, RotorFOUR[i]); 
		Insert_Unit (Alph_RotorFOUR, Alpht[i]);
		
		Insert_Unit (Reflect_Rotor, Reflector[i]);
	}
	
	//Get the plugboard
		
	//connect every pair of rotor 
	ConnectRotor (Reflect_Rotor, Alph_RotorFOUR, 'A', key[2]);
	ConnectRotor (Alph_RotorONE, Ciph_RotorONE, 'A', key[0]);
	ConnectRotor (Alph_RotorTWO, Ciph_RotorTWO, key[0] , key[1]);
	ConnectRotor (Alph_RotorTHREE, Ciph_RotorTHREE, key[1], key[2]);
	ConnectRotor (Alph_RotorFOUR, Ciph_RotorFOUR, key[2] , 'A');
	
	//encrytion (decrytion) process
	for (j=1 ;j<=5 ;j++)
	{
		pRotorhead* Rotortemp = CreateRotor();
		
		switch (j){
				
			case 1:  Rotortemp = Alph_RotorONE; break; 
			
			case 2:  Rotortemp = Alph_RotorTWO; break;
				
			case 3:  Rotortemp = Alph_RotorTHREE; break;
				
			case 4:  Rotortemp = Alph_RotorFOUR; break;
				
			case 5:  Rotortemp = Reflect_Rotor; break;
				
			default:  printf("Error in the value of j");
				
		}
				
		Unit* pcurn = Find(Rotortemp, dyletter);
		Unit* ptemp = pcurn->right;
		
		dyletter = ptemp->letter; 
			
		Destroy(Rotortemp);
		
	}
	
	//	printf("Current dyletter is:%c\n", dyletter);
		
	for (j=1 ;j<=3 ;j++)
	{
		pRotorhead* Rotortemp = CreateRotor();
			
		switch (j){
				
			case 1:  Rotortemp = Ciph_RotorTHREE; break; 
				
			case 2:  Rotortemp = Ciph_RotorTWO; break;
				
			case 3:  Rotortemp = Ciph_RotorONE; break;
				
			default:  printf("Error in the value of j");
				
		}
				
		Unit* pcurn = Find(Rotortemp, dyletter);
		Unit* ptemp = pcurn->left;
		
		dyletter = ptemp->letter; 
			
		Destroy(Rotortemp);
		
	}
		
		
		
	return dyletter;
}


void Printsetting (int seq){
	pRotorhead* Alph_RotorONE = CreateRotor(); 
	pRotorhead* Ciph_RotorONE = CreateRotor();
	
	pRotorhead* Alph_RotorTWO = CreateRotor(); 
	pRotorhead* Ciph_RotorTWO = CreateRotor();
	
	pRotorhead* Alph_RotorTHREE = CreateRotor(); 
	pRotorhead* Ciph_RotorTHREE = CreateRotor();

    pRotorhead* Alph_RotorFOUR = CreateRotor(); 
	pRotorhead* Ciph_RotorFOUR = CreateRotor();
	
	pRotorhead* Reflect_Rotor = CreateRotor(); 
	
	//assign value to different rotors
	
	FillRotor (Ciph_RotorONE, seq/100);
	seq = seq%100;
	FillRotor (Ciph_RotorTWO, seq/10);
	FillRotor (Ciph_RotorTHREE, seq%10);
	
	
	int i=0,j=0; 
	for (i=0; i<26; i++)
	{
 
		Insert_Unit (Alph_RotorONE, Alpht[i]);

		Insert_Unit (Alph_RotorTWO, Alpht[i]);
		
		Insert_Unit (Alph_RotorTHREE, Alpht[i]);
		
		Insert_Unit (Ciph_RotorFOUR, RotorFOUR[i]); 
		Insert_Unit (Alph_RotorFOUR, Alpht[i]);
		
		Insert_Unit (Reflect_Rotor, Reflector[i]);
	}
	
	//check whether all the rotors are successfully initialize
		printf("RotorONE:     ");
		Print(Ciph_RotorONE);
		printf("AlphONE:      ");
		Print(Alph_RotorONE);
		printf("\n");
	
		printf("RotorTWO:     ");
		Print(Ciph_RotorTWO);
		printf("AlphTWO:      ");
		Print(Alph_RotorTWO);
		printf("\n");
		
		printf("RotorTHREE:   ");
		Print(Ciph_RotorTHREE);
		printf("AlphTWO:      ");
		Print(Alph_RotorTHREE);
		printf("\n");
		
		printf("RotorFOUR:    ");
		Print(Ciph_RotorFOUR);
		printf("AlphFOUR:     ");
		Print(Alph_RotorFOUR);
		printf("\n");
			
		printf("Reflector:    ");
		Print(Reflect_Rotor);
		printf("\n");
	
}




