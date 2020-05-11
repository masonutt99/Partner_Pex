/** mainPex3.c
* ===========================================================
* Name: Mason Utt, 23 Mar  2020
* Section: M1
* Project: PEX 3
* ===========================================================
*
// Documentation: provided libraries as reference on canvas, Grady Phillips explained Header Guards and to not #include .c files
// Zach Olszewski explained what kind of test cases would work, and what lessons to look at in Canvas but never looked at my code
// C3C Wang and I called on 2 different nights and he shared several youtube video with me explaining the shunting algorithm
// and where the linkedLists and Queue libraries needed to be changed for char* but did not look at my code. I looked on tutorial point and educative
//and other c library websites to understand functions
 */
#include "mainLibrary.h"
#include "shunt.h"
#include "RPN.h"
#include <stdlib.h>
#include <stdio.h>


int main(void){
    char* stringDigits = calloc(76, sizeof(char));  //allocates memory for string pointer

    printf("Enter your algebraic expression:\n");
    fgets(stringDigits, 75,stdin);                  //receives user string
//    printf("You entered: \n");
//    puts(stringDigits);
    termString(stringDigits);                       //terminates remainder of string with null

    while (!allowed(stringDigits) && (stringDigits[0] != '\0')) { //checks if legal expression makes user re-enter if not
        printf("Incorrect expression, enter a new expression:\n");
        fgets(stringDigits, 75, stdin);
        termString(stringDigits);
    }
    while (stringDigits[0] != '\0'){ // runs until null expression entered
        QueueAsLinkedList* queue = queueInit();
        RPN(stringDigits, queue);
        printf("The RPN value is: ");
        queuePrint(queue);          //////
        printf("\n");

        char* answer = solveRPN(queue);
        printf("Answer: %s\n", answer);
        free(answer);
        deleteLinkedList(queue);
        free(stringDigits);

        stringDigits = calloc(76, sizeof(char));

        printf("Enter expression or Enter blank expression to exit\n");
        fgets(stringDigits,75, stdin);
        termString(stringDigits);
        while (!allowed(stringDigits) && (stringDigits[0] != '\0')){
//            printf("Wrong!!!!");
            printf("Incorrect expression, enter a new expression:\n");
            fgets(stringDigits, 75, stdin);
            termString(stringDigits);
        }
    }

//    sscanf(stringDigits, "%d", &intFromDigits);
//    printf("%d", intFromDigits);
    free(stringDigits);
    printf("Goodbye!\n");
    return 0;
}
//    {
//        printf("Stack Test cases\n\n");
//        StackAsLinkedList *myStack = stackInit();
//        stackPush(myStack, 22);
//        stackPush(myStack, 21);
//        stackPush(myStack, 20);
//        stackPush(myStack, 19);
//        stackPrint(*myStack);
//        printf("size = %d\n", stackSize(*myStack));
//        printf("pop = %d\n", stackPop(myStack));
//        stackPrint(*myStack);
//        printf("size = %d\n", stackSize(*myStack));
//        printf("peek = %d\n", stackPeek(*myStack));
//        printf("size = %d\n\n", stackSize(*myStack));
//        deleteLinkedList(myStack);
//
//
//        printf("Queue Test Cases\n\n");
//        QueueAsLinkedList *myQueue = queueInit();
//        queueEnqueue(myQueue, 10);
//        queueEnqueue(myQueue, 8);
//        queueEnqueue(myQueue, 6);
//        queueEnqueue(myQueue, 4);
//        queuePrint(*myQueue);
//        printf("size = %d\n", queueSize(*myQueue));
//        printf("pop = %d\n", queuePop(myQueue));
//        queuePrint(*myQueue);
//        printf("size = %d\n", queueSize(*myQueue));
//        printf("peek = %d\n", queuePeek(*myQueue));
//        printf("size = %d\n\n", queueSize(*myQueue));
//        deleteLinkedList(myQueue);
//
//        printf("Math Test Cases\n\n");
//        double num1 = 2.0;
//        double num2 = 5.0;
//        printf("addition = %0.3lf\n", addition(num1, num2));
//        printf("subtraction = %0.3lf\n", subtraction(num1, num2));
//        printf("multiplication = %0.3lf\n", multiplication(num1, num2));
//        printf("division = %0.3lf\n", division(num1, num2));
//        printf("power = %0.3lf\n", power(num1, num2));
//    }

