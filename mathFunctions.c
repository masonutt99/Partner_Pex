/** mathFunctions.c
* ===========================================================
* Name: Mason Utt, 24 Mar  2020
* Section: M1
* Project: Lab
* ===========================================================
 *
 * Documentation:  code from canvas
*/

#include "mainLibrary.h"
/**
 * function that adds two nums
 * @param double for first num
 * @param double for second num
 * @return double the sum of the two num
 */
double addition(double num1, double num2){
    return (num1 + num2);
}

/**
 * function that subtracts one num from another
 * @param double for first num
 * @param double for second num
 * @return double the result of the second num - first num
 */
double subtraction(double num1, double num2){
    return (num1 - num2);
}

/**
 * function that multiplies two numd
 * @param double for first num
 * @param double for second num
 * @return double the product of the two num
 */
double multiplication(double num1, double num2){
    return (num1 * num2);
}

/**
 * function that divides one num from another
 * @param double for first num
 * @param double for second num
 * @return double the answer
 */
double division(double num1, double num2){
    return num1/num2;
}

/**
 * function that takes a num to power of num
 * @param double for base
 * @param double for exponent
 * @return double the result of num1^num2
 */
double power(double num1, double num2){
    return pow(num2, num1);
}