/** RPN.c
* ===========================================================
* Name: Mason Utt, 14 Apr  2020
* Section: M1
* Project: Pex 3
* ===========================================================
*/

#include "RPN.h"
#include "shunt.h"
#include "mainLibrary.h"
/**
 *  Solves the RPN equation
 * @param queue
 * @return answer
 */
char* solveRPN(QueueAsLinkedList* queue){
    StackAsLinkedList* stack = stackInit();

    char* arg1[20], arg2[20];
    char op;
    double doubleArg1 = 1, doubleArg2 = 1;    // double value

//    char* stupid = queuePeek(queue);
//    printf("%s", stupid);                             // testing if peek worked

    while (!queueIsEmpty(queue)){
        if(strchr(queuePeek(queue), ' ')){  // mixed num
            doubleArg1 = mixedNum(queuePop(queue));
            sprintf(arg1, "%.10lf", doubleArg1);
            stackPush(stack, &arg1);
        }
        if(isdigit(queuePeek(queue)[0]) || isdigit(queuePeek(queue)[1])){
            stackPush(stack, queuePop(queue));
        } else if (isOperator(queuePeek(queue)[0])){
            strcpy(arg2, stackPop(stack));

            if(strchr(arg2, ' ')){
                doubleArg1 = mixedNum(arg2);
                sprintf(arg2, "%.10lf", doubleArg1);
                stackPush(stack, &arg2);
                strcpy(arg2, stackPop(stack));
            }
            strcpy(arg1, stackPop(stack));
            op = queuePop(queue)[0];
            doubleArg1 = strtod(arg1, NULL);
            doubleArg2 = strtod(arg2, NULL);


            if (op == '^'){
             doubleArg1 = power((double)doubleArg1,(double) doubleArg2);
            }else if (op == '*'){
                doubleArg1 = multiplication((double)doubleArg1, (double)doubleArg2);
            }else if (op == '/'){
                doubleArg1 = division((double)doubleArg1, (double)doubleArg2);
            }else if (op == '+'){
                doubleArg1 = addition((double)doubleArg1, (double)doubleArg2);
            }else if (op == '-'){
                doubleArg1 = subtraction((double)doubleArg1, (double)doubleArg2);
            } else{
                doubleArg1 = (double)-1;
            }
            sprintf(arg1, "%.10lf", (double)doubleArg1);
            stackPush(stack, &arg1);
        }
    }

    char* answer = calloc(20, sizeof(char));
    convert(stackPeek(stack));
    strcpy(answer, convert(stackPop(stack)));
    deleteLinkedList(stack);

    return answer;
}

/**
 * mixedNum
 * @param line
 * @return double of the mixed num
 * i.e. 1 1/2 would be 1.5000
 */
double mixedNum(char* line){

    int whole, numerator, denominator;
    sscanf(line, "%d %d/%d", &whole, &numerator, &denominator);

    return ((double)whole + ((double)numerator / (double)denominator));
}

/**
 * convert
 * converts answer to mixed number or fraction
 * @param answer
 * @return converts double to fraction then string
 */
char* convert(char* answer){
    char* final = calloc(32, sizeof(char));

    double ans = strtod(answer, NULL);
    int whole = (int)ans;
    int numerator = (ans - whole) * 1000000;    //numerator
    int denominator = 1000000;                  //denominator

    int numerator1 = numerator / greatestCommon(numerator, denominator);
    int denominator1 = denominator / greatestCommon(numerator, denominator);

    if(greatestCommon(numerator, denominator) < 10){
        numerator1 = (numerator +1) / (greatestCommon((numerator+1), denominator));
        denominator1 = denominator / greatestCommon((numerator+1), denominator);

        if(greatestCommon((numerator + 1), denominator) < 10){
            numerator1 = numerator / greatestCommon(numerator, (denominator -1));
            denominator1 = (denominator - 1) / greatestCommon(numerator, (denominator-1));
        }
    }

    if(numerator1 != 0){
        if(whole != 0) {
            if (numerator1 != denominator1) {
                sprintf(final, "%d %d/%d", whole, numerator1, denominator1);
            } else
                sprintf(final, "%d", (whole +1));
        }
        else {
            if (numerator1 != denominator1) {
                sprintf(final, "%d/%d", numerator1, denominator1);
            } else {
                sprintf(final, "%d", 1);
            }
        }
    } else{
        sprintf(final, "%d", whole);
    }
    return final;
}

/**
 * greatestCommon
 * @param one
 * @param two
 * @return
 */
int greatestCommon(int one, int two){
    int remainder;
    while ( one != 0){
        remainder = two % one;
        two = one;
        one = remainder;
    }
    return two;
}