/** RPN.h
* ===========================================================
* Name: Mason Utt, 14 Apr  2020
* Section: M1
* Project: Pex 3
* ===========================================================
*/

#ifndef MYEXE_RPN_H
#define MYEXE_RPN_H

#include <stdio.h>
#include <stdlib.h>
#include "shunt.h"


char* solveRPN(QueueAsLinkedList* queue);
double mixedNum(char* line);
char* convert(char* answer);
int greatestCommon(int one, int two);

#endif //MYEXE_RPN_H
