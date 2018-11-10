#ifndef _UNIT_H_
#define _UNIT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// define a single basic unit
typedef struct Unit
{

	char letter;
	struct Unit* down;
	struct Unit* left;
	struct Unit* right;

}Unit;

// define the head of a rotor
typedef struct Rotor_Head
{

	int length;
	Unit* down;

}pRotorhead;

//function
pRotorhead* CreateRotor ();

int Size_of_Rotor (pRotorhead* pRotor);

int Insert_Unit (pRotorhead* pRotor,  char val);

Unit* Find (pRotorhead* pRotor, char val);

void Destroy (pRotorhead* pRotor);

void Print (pRotorhead* pRotor);

#endif
