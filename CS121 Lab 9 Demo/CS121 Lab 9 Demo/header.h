#pragma once
#include <stdio.h>

void runTaskOne(void);
char* stringReverse(char* targetString);
char* stringReversePointer(char* targetString);
void printString(char* targetString);

void runTaskTwo(void);
char* my_strcpy(char* destination, const char* source);
void testMyStrCpy(void);
char* my_strcat(char* destination, const char* source);
void testMyStrCat(void);
int my_strcmp(const char* string1, const char* string2);
void testMyStrCmp(void);
int my_strlen(const char* targetString);
void testMyStrLen(void);