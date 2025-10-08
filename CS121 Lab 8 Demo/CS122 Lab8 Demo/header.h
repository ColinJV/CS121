#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void runTaskOne(void);
int populateArrayFromFile(int* fileReadValues);
void reverseArray(int* targetArray, int arraySize);
void displayArray(int* targetArray, int arraySize);

void runTaskTwo(void);
void displayCharacterArray(char* characterArray, int size);
void removeWhitespace(char* characterArray, int size);

void runTaskThree(void);
void populateArray(int* targetArray, int size);
void populateFrequencyTable(int* baseArray, int baseArraySize, int* frequencyTable);

void runTaskFour(void);
void initializeMaskingArray(char* maskingArray, char* hangmanWord);
char getUserGuess(char* maskingArray);
int guessIsInWord(char guess, char* hangmanWord);
void revealGuess(char guess, char* maskingArray, char* hangmanWord);
int gameShouldContinue(char* maskingArray);
void displayGameResult(char* hangmanWord, int gameWon);