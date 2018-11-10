#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rotor.h"

pRotorhead* CreateRotor ()
{
	//malloc a dynamic space for head     mkjabjeuhkcl   opptjp   xyjyaopi
	pRotorhead* pRotor = (pRotorhead*) malloc (sizeof(pRotorhead));
	pRotor->length = 0;
	pRotor->down = NULL;

	return pRotor;
}

int Size_of_Rotor (pRotorhead* pRotor)
{
	if (pRotor == NULL)
	{
		printf("pointer input error");
		return 0;
	}

	return pRotor->length;
}

// insert a new unit AFTER the pos (start with one)
int Insert_Unit (pRotorhead* pRotor, char val)
{

	if (pRotor == NULL )
	{
		printf("input error");
		return 0;
	}

	Unit* punit = (Unit*) malloc (sizeof(Unit));
	punit->letter = val;

	if  (pRotor->length ==0 )
	{

		pRotor->down = punit;
		punit->down = punit;

	}else
	{
		Unit* ptemp = pRotor->down;

		while ( ptemp->down != pRotor->down )
		{
			ptemp = ptemp->down;
		}

		punit->down = pRotor->down;
		pRotor->down = punit;
		ptemp->down  = punit;

	}
	// use a pointer (ptemp) of the pointer (pRotor->down) to alter the original pointer (pRotor->down)

	pRotor->length ++;
	return 0;
}

Unit* Find (pRotorhead* pRotor, char val)
{

	if (pRotor == NULL)
	{

		printf("Input error");
		return NULL;

	}

	Unit* ptemp = pRotor->down ;
	do
	{

		if (ptemp->letter == val)
		{
			return ptemp;
		}

		ptemp = ptemp->down;

	}while (ptemp != pRotor->down);

	printf("Can`t find the letter");
	return NULL;

}

void Destroy (pRotorhead* pRotor)
{

	Unit* pcurn = pRotor->down ;
	Unit* ptemp;

	if (pRotor == NULL)
	{
		printf("error");
	}

	while (pcurn->down != pRotor->down )
	{
		ptemp = pcurn->down;
		free(pcurn);
		pcurn = ptemp;
	}

	pRotor->length =0;
	pRotor->down = NULL;
}


//print the element in the unit
void Print (pRotorhead* pRotor)
{

	if (pRotor == NULL)
	{
		printf(" Input error");
	}

	Unit* ptemp = pRotor->down;

	do
	{
		printf ("%c", ptemp->letter );
		ptemp = ptemp->down;
	}while (ptemp != pRotor->down );

	printf("\n");
}
