/** shunt.c
* ===========================================================
* Name: Mason Utt, 13 Apr  2020
* Section: M1
* Project: Pex 3
* ===========================================================
*/


/**     Shunting yard algo
 * while there are tokens to be read do:
read a token.
    if the token is a number, then:
push it to the output queue.
    if the token is a function then:
push it onto the operator stack
    if the token is an operator, then:
        while ((there is a function at the top of the operator stack)
            or (there is an operator at the top of the operator stack with
            greater precedence)
            or (the operator at the top of the operator stack has equal
            precedence and the token is left associative))
            and (the operator at the top of the operator stack is not a left
            parenthesis):
                pop operators from the operator stack onto the output queue.
            push it onto the operator stack.
    if the token is a left paren (i.e. "("), then:
    push it onto the operator stack.
    if the token is a right paren (i.e. ")"), then:
    while the operator at the top of the operator stack is not a left paren:
    pop the operator from the operator stack onto the output queue.
        /* if the stack runs out without finding a left paren, then there are
        mismatched parentheses.
        if there is a left paren at the top of the operator stack, then:
        pop the operator from the operator stack and discard it
/* After while loop, if operator stack not null, pop everything to output queue
        if there are no more tokens to read then:
        while there are still operator tokens on the stack:
/* if the operator token on the top of the stack is a paren, then there are
mismatched parentheses.
        pop the operator from the operator stack onto the output queue.
    exit
 */


#include "shunt.h"
/** termString
 * terminates the sting by
 * changes the enter '\n' symbol to '\0' which terminates the string
 * @param string
 */
void termString(char* string){
    for (int i = 0; string[i] != '\0'; ++i) {
        if(string[i] == '\n')
            string[i] = '\0';
    }
}
/**
 * isOperator
 * this function tests whether or not the test character is an operator
 * @param test
 * @return truth value of test = operator
 */
bool isOperator(char test){
    char ops[] = "()^*/+-";

    if ( strchr(ops, test) ){
        return true;
    } else
        return false;
}
/**
 *allowed
 * checks to see if the equation has errors
 * @param string
 * @return true if legal expression
 */
bool allowed(char* string){
    int Lparen = 0, Rparen = 0;        // used to check if even num of parenthesis
    char ops[] = "^*/+-";              // array of PEDMAS w/o ()

    for (int i = 0; string[i] != '\0' ; ++i) {
        switch(string[i]) {
            case '(':
                Lparen++;
                break;
            case ')':
                Rparen++;
                break;
            case ('/'):
                if(string[i + 1] == '-')
                    return false;
                break;
            default:
                if(!isOperator(string[i]) && string[i] != ' ' && !isdigit(string[i])){
                    return false;
                } else
                    break;
        }
    }
    if(Lparen != Rparen){
        return false;
    }
    if((string[strlen(string) -1] == ' ') || strchr(ops, string[strlen(string) - 1])){
        return false;
    }
    return true;
}


/**
 * RPN
 * this function takes the equation and puts it into a queue in RPN form
 * i.e. 22 + 3 * 5 would be 22 -> 3 -> 5 -> * -> +
 * @param string
 * @param queue
 * @return
 */

bool RPN(char* string, QueueAsLinkedList* queue){
    char* token = calloc(256, sizeof(char));
    bool operator = true;
    StackAsLinkedList* opStack = stackInit();

    for(char* ptr = string, *tmpPtr = NULL; *ptr != '\0'; ptr++){
        char* token = calloc(256, sizeof(char));
        while (*ptr == ' ')                                         //skips spaces
            ptr++;
        if(operator && (*ptr == '-' || isdigit(*ptr))){  // numbers
            tmpPtr = ptr +1;                                        //looks at next space
            while ((!isOperator(*tmpPtr) || *tmpPtr == '/') && *tmpPtr != ' ' && *tmpPtr != '\0'){ //takes multi-digit numbers
                tmpPtr++;                                           //until end of num is reached
            }
            if(*tmpPtr == ' ' && isdigit(*(tmpPtr + 1))) { // mixed numbers
                tmpPtr++;                                       //first digit of numerator
                tmpPtr = strchr(tmpPtr, '/') + 1;               // location of '/'
                while( isdigit(*tmpPtr)){
                    tmpPtr++;                                   //moves until end of denominator is read
                }
            }
            strncpy(token, ptr, (int)(tmpPtr - ptr)); //copies number
            queueEnqueue(queue, token);
            operator = false;
            ptr = tmpPtr - 1;
        } else{                                         // operators
            operator = true;
            token[0] = *ptr;
            if(*ptr == '('){
                stackPush(opStack, "(");
                operator = true;
            } else if(*ptr == ')'){
                while (!stackIsEmpty(opStack) && ('(' != (stackPeek(opStack)[0]))){ // goes until empty or begin parenthesis
                    strcpy(token, stackPop(opStack));
                    queueEnqueue(queue, token);
                }
                if (stackIsEmpty(opStack))
                    return false;
                else
                    strcpy(token, stackPop(opStack));
                operator = false;
            } else{
                int pedmas = Pemdas(token[0]);
                char tmp[2];
                while (!stackIsEmpty(opStack) && (pedmas <= Pemdas(stackPeek(opStack)[0]))){
                    strcpy(tmp, stackPop(opStack));
                    queueEnqueue(queue, tmp);
                }
                stackPush(opStack, token);
            }
        }
    free(token);
    }
    while (!stackIsEmpty(opStack)){
        strcpy(token, stackPop(opStack));
        queueEnqueue(queue, token);
    }
    return true;
}

int Pemdas(char token){
    if ( token == '(' || token == ')'){
        return 0;
    } else if(token == '^'){
        return 3;
    } else if(token == '*' || token == '/'){
        return 2;
    } else if(token == '+' || token == '-'){
        return 1;
    } else{
        return -1;
    }
}