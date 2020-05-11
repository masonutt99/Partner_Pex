/** listAsLinkedList.h
* ================================================================
* Name: Mason UTt
* Section: M2
* Project: Header for Pex3 part 1
*
*
* 
* =================================================================
*/
#ifndef MAIN_LIBRARY_H
#define MAIN_LIBRARY_H

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>

// Define a node of the linked list
typedef struct node {
    char data[50];
    struct node* next;
} Node;

// Define the type (meta-data) that manages the linked list of nodes
typedef struct {
    Node* head;
    Node* tail;
    int numberOfElements;
} LinkedList;

// Functions that manipulate a linked list
LinkedList* createLinkedList();
void deleteLinkedList(LinkedList* list);
void appendElementLinkedList(LinkedList* list, char* element);
int lengthOfLinkedList(LinkedList* list);
void printLinkedList(LinkedList* list);
char* getElementLinkedList(LinkedList* list, int position);
void deleteElementLinkedList(LinkedList* list, int position);

// Functions that manipulate stack as linked list
typedef LinkedList StackAsLinkedList;
void stackPush(StackAsLinkedList* stack, char* element);
char* stackPop(StackAsLinkedList* stack);
bool stackIsEmpty(StackAsLinkedList* stack);
bool stackIsFull(StackAsLinkedList* stack);
StackAsLinkedList* stackInit();
char* stackPeek(StackAsLinkedList* stack);
int stackSize(StackAsLinkedList* stack);
void stackPrint(StackAsLinkedList* stack);

// Functions that manipulate queue as linked list
typedef LinkedList QueueAsLinkedList;
void queueEnqueue(QueueAsLinkedList* queue, char* element);
char* queuePop(QueueAsLinkedList* queue);
bool queueIsEmpty(QueueAsLinkedList* queue);
bool queueIsFull(QueueAsLinkedList queue);
QueueAsLinkedList* queueInit();
char* queuePeek(QueueAsLinkedList* queue);
int queueSize(QueueAsLinkedList queue);
void queuePrint(QueueAsLinkedList* queue);

// Functions that do math
double addition(double num1, double num2);
double subtraction(double num1, double num2);
double multiplication(double num1, double num2);
double division(double num1, double num2);
double power(double num1, double num2);



#endif //MAIN_LIBRARY_H