/** shunt.h
* ===========================================================
* Name: Mason Utt, 13 Apr  2020
* Section: M1
* Project: Pex3
* ===========================================================
*/

#ifndef MYEXE_SHUNT_H
#define MYEXE_SHUNT_H


#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "mainLibrary.h"

void termString(char* string);
bool isOperator(char test);
bool allowed(char* string);
bool RPN(char* string, QueueAsLinkedList* queue);
int Pemdas(char token);

#endif //MYEXE_SHUNT_H
