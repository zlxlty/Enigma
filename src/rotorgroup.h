#ifndef _ROTORGROUP_H_
#define _ROTORGROUP_H_

#include <stdio.h>
#include <stdlib.h>
#include "rotor.h"

int ConnectRotor (pRotorhead* Alph_Rotor, pRotorhead* Ciph_Rotor, char Allet, char Cilet);  

void FillRotor ( pRotorhead* Ciph_Rotor, int num);

char Plugboard (char letter, char* plugboard);

char* KeyRotation (char* key);

char Encrytion (char dyletter, char* key, int seq);

void Printsetting (int seq);

#endif
