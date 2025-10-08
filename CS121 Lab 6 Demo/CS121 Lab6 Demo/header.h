#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void runTaskOne(void);
int getSumFromFile(FILE* ifstream);
int isPrime(int sum);
void displayPrimeResult(int isPrime, int sum);
int getSumOfDigits(int num);
void displayPrimeDigitResult(int isPrime, int sumOfDigits);

void runTaskTwo(void);
int getNonNegativeIntegerInput(void);
int calculateFactorial(int number);
void displayFactorialResult(int factorial, int number);

void runTaskThree(void);
int calculateFibonacciNumber(int term);
void displayFibonacciNumber(int nthTerm, int term);

void runTaskFour(void);
int generateRandomNumberInRange(int range);
int coinFlip(void);
int getUserInputInRange(void);
static int inputIsInvalid(int input);
int compareGuessToNumber(int userGuess, int randomNumber);
void displayGuessCount(int guessCount);